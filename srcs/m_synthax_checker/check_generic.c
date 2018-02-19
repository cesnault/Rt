/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_generic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:50:44 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/02 20:56:06 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "ft_ori.h"
#include "parser.h"
#include "bmp.h"
#include "synthax_checker.h"
#include <stdlib.h>

static int		quit_bibitch(char **str)
{
	free(*str);
	return (0);
}

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

static void		core_core_basic(int *tab, int ret2)
{
	if (ret2 == GREEN)
		tab[6] += 1;
	else if (ret2 == RED)
		tab[7] += 1;
	else if (ret2 == YELLOW)
		tab[8] += 1;
	else if (ret2 == F_NEG)
		tab[9] += 1;
	else if (ret2 == SEPIA)
		tab[1] += 1;
	else if (ret2 == STEREO)
		tab[2] += 1;
	else if (ret2 == ALIA)
		tab[3] += 1;
	else if (ret2 == NAME)
		tab[4] += 1;
	else if (ret2 == AMBIANT)
		tab[5] += 1;
}

static int		core_generic(char *str, int fd, int ret2)
{
	int			tab[10];
	int			ret;

	init_tab(tab, 10);
	while (ret2 != END && (ret = get_next_line(fd, &str)) > 0)
	{
		ret2 = field_type(str);
		if (!(*str) && ret != 1 && ret2 == 0)
			quit_bibitch(&str);
		else if (ret2 == DIM)
			tab[0] += 1;
		else if (ret2 == GREEN || ret2 == RED ||\
ret2 == YELLOW || ret2 == F_NEG || ret2 == SEPIA || ret2 == STEREO ||\
ret2 == ALIA || ret2 == NAME || ret2 == AMBIANT)
			core_core_basic((int *)tab, ret2);
		else if (ret2 != END)
			return (core_end(&str, "check_generic: "));
		ft_strdel(&str);
	}
	return (tab[0] <= 1 && tab[1] <= 1 && tab[2] <= 1 && tab[3] <= 1 &&\
	tab[4] <= 1 && tab[5] <= 1 && tab[6] <= 1 && tab[7] <= 1 && tab[8] <= 1 &&\
	tab[9] <= 1);
}

int				check_generic(int fd)
{
	char		*str;
	int			ret;
	int			ret2;

	ret2 = 1;
	str = 0;
	ret = get_next_line(fd, &str);
	if (ret < 1 || field_type(str) != BEGIN)
	{
		free(str);
		return (0);
	}
	free(str);
	return (core_generic(str, fd, ret2));
}
