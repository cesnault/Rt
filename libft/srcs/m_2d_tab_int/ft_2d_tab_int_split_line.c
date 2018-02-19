/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_int_split_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:58:54 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/16 23:59:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_tab_int.h"
#include "ft_ori.h"

int		ft_2d_tab_int_split_line(t_2d_tab_int *tab, int y, char *line)
{
	int c;
	int num;

	c = 0;
	num = 0;
	while (line[c] && num < tab->x)
	{
		tab->tab[y][num] = ft_atoi(&(line[c]));
		if (line[c] == '-')
			c++;
		while (ft_isdigit(line[c]))
			c++;
		while (line[c] == ' ')
			c++;
		num++;
	}
	if (num != tab->x)
		return (0);
	return (1);
}
