/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_obj_redim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:31:30 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/08 17:31:58 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include "ft_ori.h"

void			obj_redim_init(int size, t_obj_redim *r)
{
	if (size < 1)
		return ;
	if (!(r->all_obj = malloc(sizeof(t_obj *) * size)))
		malloc_fail("obj_redim_init");
	r->size_total = size;
	r->size_use = 0;
}

void			obj_redim_push(t_obj_redim *r, t_obj *o)
{
	if (r->size_use + 1 >= r->size_total)
		exit(1);
	o->t = 20000.0;
	r->all_obj[r->size_use] = o;
	r->size_use += 1;
}

void			obj_redim_destruct(t_obj_redim **r)
{
	t_obj_redim		*rr;
	int				c;

	if (!r || !(*r))
		return ;
	rr = *r;
	c = 0;
	while (c < (int)rr->size_use)
	{
		obj_destroy(rr->all_obj[c]);
		c++;
	}
	free(rr->all_obj);
	free(rr);
}
