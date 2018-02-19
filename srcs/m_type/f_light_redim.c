/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_light_redim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:27:24 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 14:18:07 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include "ft_ori.h"
#include "type.h"

void			light_redim_init(int size, t_light_redim *r)
{
	if (size < 1)
		return ;
	if (!(r->all_light = malloc(sizeof(t_light *) * size)))
		malloc_fail("light_redim_init");
	r->size_total = size;
	r->size_use = 0;
}

void			light_redim_push(t_light_redim *r, t_light *o)
{
	if (r->size_use + 1 >= r->size_total)
		return ;
	r->all_light[r->size_use] = o;
	r->size_use += 1;
}

void			light_redim_destruct(t_light_redim **r)
{
	t_light_redim		*rr;
	int					c;

	if (!r || !(*r))
		return ;
	rr = *r;
	c = 0;
	while (c < (int)rr->size_use)
	{
		light_destroy(&(rr->all_light[c]));
		c++;
	}
	free(rr->all_light);
	free(rr);
}
