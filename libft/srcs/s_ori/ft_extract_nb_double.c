/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_nb_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:09:35 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/27 22:10:00 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"

double		*ft_extract_nb_double(char *data, int nb, int *error)
{
	int		c;
	int		actual;
	double	*tab_i;

	*error = 0;
	if (!(tab_i = malloc(sizeof(double) * nb)))
	{
		ft_putstr_fd("ft_extract_nb_double: invalid extract\n", 2);
		*error = 1;
		return (0);
	}
	c = 0;
	actual = 0;
	while (*data && actual != nb)
	{
		tab_i[actual] = ft_atoi_double(data);
		actual++;
		while (actual != nb && *data != ' ')
			data++;
		while (actual != nb && *data == ' ')
			data++;
	}
	return (tab_i);
}
