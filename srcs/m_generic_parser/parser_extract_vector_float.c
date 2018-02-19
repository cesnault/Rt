/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_vector_float.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:08:23 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/13 20:09:30 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>
#include "parser.h"

static t_color_light	*extract_vector(char *data)
{
	t_color_light		*vector;
	float				*tab;
	int					error;

	tab = ft_extract_nb_float(data, 3, &error);
	if (error == 1)
		return (0);
	if (!(vector = (t_color_light *)malloc(sizeof(t_color_light))))
	{
		ft_putstr_fd("extract_vector : erreur : malloc\n", 2);
		exit(0);
	}
	vector->x = tab[0];
	vector->y = tab[1];
	vector->z = tab[2];
	free(tab);
	return (vector);
}

t_color_light			*parser_extract_vector_float(char *begining, char *data)
{
	data = parser_extract_begin(begining, data);
	if (!data)
	{
		ft_putstr_fd("parser_float: error ...\n", 2);
		exit(0);
	}
	return (extract_vector(data));
}
