/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:17:40 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/18 22:17:50 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>
#include <unistd.h>

static t_list		*ft_get_all(int fd, t_list *lst)
{
	t_file			*new;

	if (lst->content && ((t_file*)lst->content)->fd == fd)
		return (lst);
	else if (lst->next)
		return (ft_get_all(fd, lst->next));
	else
	{
		if (!(new = (t_file*)malloc(sizeof(t_file))))
			return (0);
		new->fd = fd;
		new->chaine = new->buff + BUFF_SIZE;
		ft_bzero(new->buff, BUFF_SIZE + 1);
		if (!(lst->next = (t_list*)malloc(sizeof(t_list))))
			return (0);
		lst->next->next = 0;
		lst->next->content = new;
		return (lst->next);
	}
}

static int			ft_oklm(char **line, t_file *chaine)
{
	char			*tmp;
	char			*tmpl;

	tmpl = *line;
	if ((tmp = ft_strchr(chaine->chaine, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strjoin(*line, chaine->chaine)))
			return (-1);
		free(tmpl);
		chaine->chaine = tmp + 1;
		return (1);
	}
	if (!(*line = ft_strjoin(*line, chaine->chaine)))
		return (-1);
	free(tmpl);
	chaine->chaine = chaine->buff + BUFF_SIZE;
	return (0);
}

static int			ft_join(char **line, t_file *chaine_buff)
{
	char			*tmp;

	tmp = *line;
	*chaine_buff->chaine++ = '\0';
	if (!(*line = ft_strjoin(tmp, chaine_buff->buff)))
		return (-1);
	free(tmp);
	return (1);
}

static int			ft_get_one(const int fd, char **line, t_file *content)
{
	int				tmp;
	int				ret;

	ret = 0;
	while ((tmp = read(fd, content->buff, BUFF_SIZE)) > 0)
	{
		ret = 1;
		content->buff[tmp] = '\0';
		if ((content->chaine = ft_strchr(content->buff, '\n')))
			return (ft_join(line, content));
		content->chaine = content->buff + tmp;
		if (ft_join(line, content) == -1)
			return (-1);
		content->chaine = content->buff + tmp;
	}
	return ((tmp == -1) ? -1 : ret);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	lst_fd;
	t_list			*lst;
	t_file			*content;
	int				tmp;
	int				ret;

	ret = 0;
	if (!(lst = ft_get_all(fd, &lst_fd)) || !line)
		return (-1);
	content = lst->content;
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (*(content->chaine))
	{
		if ((tmp = ft_oklm(line, content)) || tmp == -1)
			return (tmp);
		ret = 1;
	}
	if ((tmp = ft_get_one(fd, line, content)) != 0)
		return (tmp);
	free(lst->content);
	lst->content = 0;
	return (ret);
}
