/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:15:16 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/27 20:15:39 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "parser.h"
#include <stdlib.h>

static double	extract_double(char *data, int *error)
{
	double		nb;
	double		*tab;

	tab = ft_extract_nb_double(data, 1, error);
	if (*error == 1)
	{
		ft_putstr_fd("Extract double error ...\n", 2);
		return (0);
	}
	nb = tab[0];
	free(tab);
	return (nb);
}

double			parser_extract_double(char *begining, char *data, int *error)
{
	data = parser_extract_begin(begining, data);
	if (!data || *error == 1)
	{
		ft_putstr_fd("error ...\n", 2);
		return (0);
	}
	return (extract_double(data, error));
}
