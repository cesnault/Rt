/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:41:40 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/10 15:42:14 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

double		vector_len(t_vector a)
{
	double	l;

	l = a.x * a.x + a.y * a.y + a.z * a.z;
	l = (float)sqrt(l);
	return (l);
}