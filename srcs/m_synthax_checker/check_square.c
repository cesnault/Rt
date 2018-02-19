/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:39:16 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/02 21:40:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "parser.h"
#include "bmp.h"
#include "synthax_checker.h"
#include "ft_ori.h"

static void		init_tab(int *tab, int size)
{
	int			c;

	c = 0;
	while (c < size)
	{
		tab[c] = 0;
		c++;
	}
}

static int		quit_bibitch(char **str)
{
	free(*str);
	return (0);
}

static int		core_core_square(int *tab, int ret2, char **str, int fd)
{
	if (ret2 == NAME)
		tab[0] += 1;
	else if (ret2 == POS)
		tab[1] += 1;
	else if (ret2 == DIM_SQUARE)
		tab[2] += 1;
	else if (ret2 == ROT)
		tab[3] += 1;
	else if (ret2 == TEXTURE)
	{
		if (check_texture(fd, *str))
			tab[4] += 1;
		else
		{
			free(*str);
			return (0);
		}
	}
	else if (ret2 == LIGHT_COLOR)
		tab[5] += 1;
	return (1);
}

static int		core_square(char *str, int fd, int ret2)
{
	int			tab[6];
	int			ret;

	init_tab(tab, 6);
	while (ret2 != END && (ret = get_next_line(fd, &str)) > 0)
	{
		ret2 = field_type(str);
		if (!(*str) && ret != 1 && ret2 == 0)
			return (quit_bibitch(&str));
		else if (ret2 == NAME || ret2 == POS ||\
ret2 == DIM_SQUARE || ret2 == ROT ||\
		ret2 == TEXTURE || ret2 == LIGHT_COLOR)
		{
			if (!(core_core_square(tab, ret2, &str, fd)))
				return (0);
		}
		else if (ret2 != NAME && ret2 != END)
			return (core_end(&str, "check_square: "));
		free(str);
	}
	return (tab[1] == 1 && tab[2] == 1 &&\
	tab[3] == 1 && tab[4] == 1 && tab[5] == 1);
}

int				check_square(int fd)
{
	char		*str;
	int			ret;
	int			ret2;

	ret2 = 1;
	str = 0;
	ret = get_next_line(fd, &str);
	if (ret < 1 || field_type(str) != BEGIN)
	{
		ft_strdel(&str);
		return (0);
	}
	free(str);
	return (core_square(str, fd, ret2));
}
