/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 21:18:05 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 22:29:11 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "parser.h"
#include "bmp.h"
#include "synthax_checker.h"
#include "ft_ori.h"

static int			quit_bibitch(char **str)
{
	free(*str);
	return (0);
}

static	void		init_tab(int *tab, int size)
{
	int				c;

	c = 0;
	while (c < size)
	{
		tab[c] = 0;
		c++;
	}
}

static int			core_core_obj(int *tab, int ret2, char **str, int fd)
{
	if (ret2 == POS)
		tab[0] += 1;
	else if (ret2 == ROT)
		tab[1] += 1;
	else if (ret2 == DIRR)
		tab[2] += 1;
	else if (ret2 == LIGHT_COLOR)
		tab[3] += 1;
	else if (ret2 == REY)
		tab[4] += 1;
	else if (ret2 == TEXTURE)
	{
		if (check_texture(fd, *str))
			tab[5] += 1;
		else
		{
			free(*str);
			return (0);
		}
	}
	else if (ret2 == NEG)
		tab[6] += 1;
	return (1);
}

static int			core_obj(int fd, char *str, int ret2, int ret3)
{
	int				ret;
	int				tab[7];

	init_tab((int *)tab, 7);
	while (ret2 != END && (ret = get_next_line(fd, &str)) > 0)
	{
		ret2 = field_type(str);
		if (!(*str) && ret != 1 && ret2 == 0)
			return (quit_bibitch(&str));
		else if (ret2 == POS || ret2 == ROT || ret2 == DIRR ||\
ret2 == LIGHT_COLOR || ret2 == REY || ret2 == TEXTURE || ret2 == NEG)
		{
			if (!(core_core_obj((int *)tab, ret2, &str, fd)))
				return (0);
		}
		else if (ret2 != NAME && ret2 != END)
			return (core_end(&str, "check_obj: "));
		free(str);
	}
	if (!(ret3 == CYLINDER || ret3 == SPHERE || ret3 == DISK))
		tab[4] += 1;
	if (ret3 != SPHERE && ret3 != CYLINDER)
		tab[6] += 1;
	return (tab[0] == 1 && tab[1] == 1 && tab[2] == 1 && tab[3] == 1 &&\
tab[4] == 1 && tab[5] == 1 && tab[6] <= 1);
}

int					check_obj(int fd, int ret3)
{
	char			*str;
	int				ret;
	int				ret2;

	ret2 = 1;
	str = 0;
	ret = get_next_line(fd, &str);
	if (ret < 1 || field_type(str) != BEGIN)
	{
		ft_strdel(&str);
		return (0);
	}
	free(str);
	return (core_obj(fd, str, ret2, ret3));
}
