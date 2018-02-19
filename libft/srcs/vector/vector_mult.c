/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:35:11 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/10 15:35:21 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector		vector_multi(t_vector a, t_vector b)
{
	t_vector	vec;

	vec.x = a.x * b.x;
	vec.y = a.y * b.y;
	vec.z = a.z * a.z;
	return (vec);
}

t_vector		vector_mult(double a, t_vector b)
{
	t_vector	vec;

	vec.x = a * b.x;
	vec.y = a * b.y;
	vec.z = a * b.z;
	return (vec);
}
