/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tidr_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:42:45 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/03 00:27:53 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tab_int_double_resize.h"

static t_tidr	*force_quit(t_tidr **t)
{
	free(*t);
	return (0);
}

t_tidr			*tidr_dup(t_tidr *t)
{
	int			c;
	t_tidr		*tir;

	c = 0;
	if (!(tir = malloc(sizeof(t_tidr))))
		return (0);
	if (!(tir->ti = malloc(sizeof(int) * t->size_max)))
		return (force_quit(&tir));
	if (!(tir->td = malloc(sizeof(double) * t->size_max)))
	{
		free(tir->ti);
		free(tir);
		return (0);
	}
	while (c < t->size_use)
	{
		tir->ti[c] = t->ti[c];
		tir->td[c] = t->td[c];
		c++;
	}
	tir->size_use = c;
	tir->size_max = t->size_max;
	return (tir);
}
