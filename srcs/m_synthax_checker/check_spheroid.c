/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spheroid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 21:37:26 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/02 21:38:31 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "synthax_checker.h"
#include "ft_ori.h"
#include "type.h"
#include <unistd.h>
#include <stdlib.h>
#include "parser.h"

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

static void		core_core_spheroid(int *tab, int ret2)
{
	if (ret2 == NAME)
		tab[0] += 1;
	else if (ret2 == POS)
		tab[1] += 1;
	else if (ret2 == ROT)
		tab[2] += 1;
	else if (ret2 == LIGHT_COLOR)
		tab[3] += 1;
	else if (ret2 == P1)
		tab[4] += 1;
}

static int		core_spheroid(char *str, int fd, int ret2)
{
	int			tab[6];
	int			ret;

	init_tab(tab, 6);
	while (ret2 != END && (ret = get_next_line(fd, &str)) > 0)
	{
		ret2 = field_type(str);
		if (!(*str) && ret != 1 && ret2 == 0)
			quit_bibitch(&str);
		else if (ret2 == NAME || ret2 == POS || ret2 == ROT ||\
		ret2 == LIGHT_COLOR || ret2 == P1)
			core_core_spheroid((int *)tab, ret2);
		else if (ret2 == TEXTURE)
		{
			if (check_texture(fd, str))
				tab[5] += 1;
			else
				quit_bibitch(&str);
		}
		else if (ret2 != END)
			return (core_end(&str, "check_sheroid: "));
		ft_strdel(&str);
	}
	return (tab[0] <= 1 && tab[1] == 1 && tab[2] == 1 && tab[3] == 1 &&\
tab[4] == 1 && tab[5] == 1);
}

int				check_spheroid(int fd)
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
	return (core_spheroid(str, fd, ret));
}
