/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:29:19 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/10 15:29:26 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector		vector_add(t_vector a, t_vector b)
{
	t_vector	vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	vec.z = a.z + b.z;
	return (vec);
}
