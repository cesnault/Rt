/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:01:16 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/27 20:01:48 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "parser.h"
#include <stdlib.h>

static float	extract_float(char *data, int *error)
{
	float		nb;
	float		*tab;

	tab = ft_extract_nb_float(data, 1, error);
	if (*error == 1)
		return (0);
	nb = tab[0];
	free(tab);
	return (nb);
}

float			parser_extract_float(char *begining, char *data, int *error)
{
	data = parser_extract_begin(begining, data);
	if (!data || *error == 1)
	{
		ft_putstr_fd("error ...\n", 2);
		return (0);
	}
	return (extract_float(data, error));
}
