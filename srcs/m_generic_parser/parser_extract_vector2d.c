/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_vector2d.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:20:39 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:21:02 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_ori.h"
#include <stdlib.h>
#include "parser.h"

static t_vect3d		*extract_vector2d(char *data)
{
	t_vect3d		*vector;
	double			*tab;
	int				error;

	tab = ft_extract_nb_double(data, 2, &error);
	if (error == 1)
		return (0);
	if (!(vector = malloc(sizeof(t_vect3d))))
	{
		ft_putstr_fd("extract_vector_2d : error : malloc\n", 2);
		exit(0);
	}
	vector->x = tab[0];
	vector->y = tab[1];
	vector->z = 0.0;
	free(tab);
	return (vector);
}

t_vect3d			*parser_extract_vector2d(char *begining, char *data)
{
	data = parser_extract_begin(begining, data);
	if (!data)
	{
		ft_putstr_fd("parser_extract_vector: error data ...\n", 2);
		exit(0);
	}
	return (extract_vector2d(data));
}
