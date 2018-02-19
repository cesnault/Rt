/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tir_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 23:41:07 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/30 23:41:29 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_int_resize.h"
#include <stdlib.h>

t_tir		*tir_init(int size_max)
{
	t_tir	*t;
	int		c;

	if (!(t = malloc(sizeof(t_tir))))
		return (0);
	if (!(t->tab = malloc(sizeof(int) * size_max)))
		return (0);
	c = 0;
	while (c < size_max)
	{
		t->tab[c] = 0;
		c++;
	}
	t->size_max = size_max;
	t->size_use = 0;
	return (t);
}
