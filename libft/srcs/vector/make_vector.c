/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:42:20 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/23 16:42:31 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector		make_vector(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
