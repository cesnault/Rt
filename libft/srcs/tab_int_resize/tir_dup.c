/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tir_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 00:23:50 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/03 00:23:59 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tab_int_resize.h"

t_tir		*tir_dup(t_tir *t)
{
	int		c;
	t_tir	*tir;

	c = 0;
	if (!(tir = malloc(sizeof(t_tir))))
		return (0);
	if (!(tir->tab = malloc(sizeof(int) * t->size_max)))
	{
		free(tir);
		return (0);
	}
	while (c < t->size_use)
	{
		tir->tab[c] = t->tab[c];
		c++;
	}
	tir->size_use = c;
	tir->size_max = t->size_max;
	return (tir);
}
