/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tidr_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 00:22:16 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/03 00:22:25 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_int_double_resize.h"
#include <stdlib.h>

t_tidr		*tidr_init(int size_max)
{
	t_tidr	*t;
	int		c;

	if (!(t = malloc(sizeof(t_tidr))))
		return (0);
	if (!(t->ti = malloc(sizeof(int) * size_max)))
		return (0);
	if (!(t->td = malloc(sizeof(double) * size_max)))
		return (0);
	c = 0;
	while (c < size_max)
	{
		t->ti[c] = 0;
		t->td[c] = 0.0;
		c++;
	}
	t->size_max = size_max;
	t->size_use = 0;
	return (t);
}
