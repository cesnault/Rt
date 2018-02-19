/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cross_product.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:20:02 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/27 22:20:09 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector		vector_cross_product(t_vector v1, t_vector v2)
{
	t_vector	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}
