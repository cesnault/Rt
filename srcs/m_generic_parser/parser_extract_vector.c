/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:13:45 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/15 16:10:53 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_ori.h"
#include <stdlib.h>
#include "parser.h"

t_vect3d		*extract_vector3d(char *data)
{
	t_vect3d	*vector;
	double		*tab;
	int			error;

	tab = ft_extract_nb_double(data, 3, &error);
	if (error == 1)
		return (0);
	if (!(vector = malloc(sizeof(t_vect3d))))
	{
		ft_putstr_fd("extract_vector : error : malloc\n", 2);
		exit(0);
	}
	vector->x = tab[0];
	vector->y = tab[1];
	vector->z = tab[2];
	free(tab);
	return (vector);
}

t_vect3d		*parser_extract_vector(char *begining, char *data)
{
	data = parser_extract_begin(begining, data);
	if (!data)
	{
		ft_putstr_fd("parser_extract_vector: error data ...\n", 2);
		exit(0);
	}
	return (extract_vector3d(data));
}
