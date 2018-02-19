/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_nb_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:05:00 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/27 22:14:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"

static void	update(int *nb_number, int *begin)
{
	*nb_number += 1;
	*begin = 0;
}

static int	check_error(char *data, int nb)
{
	int		c;
	int		begin;
	int		nb_number;
	int		nb_point;

	c = 0;
	begin = 1;
	nb_number = 0;
	nb_point = 0;
	while (*data && data[c])
	{
		if (data[c] == '.')
			nb_point++;
		else if (ft_isdigit(data[c]) && begin == 1)
			update(&nb_number, &begin);
		else if (data[c] == ' ' && begin == 0)
			begin = 1;
		else if (data[c] != ' ' && !ft_isdigit(data[c]))
			return (0);
		c++;
	}
	if (nb_number == nb && nb_point == nb)
		return (1);
	return (0);
}

float		*ft_extract_nb_float(char *data, int nb, int *error)
{
	int		c;
	int		actual;
	float	*tab_i;

	*error = 0;
	if (!check_error(data, nb) || !(tab_i = malloc(sizeof(float) * nb)))
	{
		ft_putstr_fd("ft_extract_float: error bitch ...\n", 2);
		*error = 1;
		return (0);
	}
	c = 0;
	actual = 0;
	while (*data && actual != nb)
	{
		tab_i[actual] = (float)ft_atoi_double(data);
		actual++;
		while (actual != nb && *data != ' ')
			data++;
		while (actual != nb && *data == ' ')
			data++;
	}
	return (tab_i);
}
