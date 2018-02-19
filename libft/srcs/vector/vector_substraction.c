/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_substraction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:27:17 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/10 15:27:26 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector		vector_substraction(t_vector a, t_vector b)
{
	t_vector	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return (vec);
}
