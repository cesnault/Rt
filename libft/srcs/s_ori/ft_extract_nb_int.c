/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_nb_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:59:29 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/27 22:00:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"

static int	check_error(char *data, int nb)
{
	int		c;
	int		begin;
	int		nb_number;

	c = 0;
	begin = 1;
	nb_number = 0;
	while (*data && data[c])
	{
		if (ft_isdigit(data[c]) && begin == 1)
		{
			nb_number++;
			begin = 0;
		}
		else if (data[c] == ' ' && begin == 0)
			begin = 1;
		else if (data[c] != ' ' && !ft_isdigit(data[c]))
			return (0);
		c++;
	}
	return (nb_number == nb);
}

int			*ft_extract_nb_int(char *data, int nb, int *error)
{
	int		actual;
	int		*tab_i;

	*error = 0;
	if (!check_error(data, nb) || !(tab_i = malloc(sizeof(int) * nb)))
	{
		ft_putstr_fd("Invalid data ...\n", 2);
		*error = 1;
		return (0);
	}
	actual = 0;
	while (*data && actual != nb)
	{
		tab_i[actual] = ft_atoi(data);
		actual++;
		while (actual != nb && *data != ' ')
			data++;
		while (actual != nb && *data == ' ')
			data++;
	}
	return (tab_i);
}
