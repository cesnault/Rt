/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_construct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:38:42 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/24 20:38:56 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

t_vector		*vector_construct(double x, double y, double z)
{
	t_vector	*vector;

	if (!(vector = malloc(sizeof(t_vector))))
		return (0);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}
