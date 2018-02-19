/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:06:33 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/27 22:21:00 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vector		vector_norm(t_vector a)
{
	t_vector	vec;
	double		l;

	vec = a;
	l = vector_len(a);
	if (l)
	{
		l = 1 / l;
		vec = vector_mult(l, vec);
	}
	return (vec);
}
