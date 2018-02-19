/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:04:15 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/19 18:04:39 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

void		complex_square(t_complex *a)
{
	long double	v_a;
	long double	v_b;

	v_a = a->x * a->x - a->y * a->y;
	v_b = 2 * a->x * a->y;
	a->x = v_a;
	a->y = v_b;
}
