/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_id_with_neg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:52:37 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 19:07:44 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "rt.h"

/*
** retourne 1 si on trouve un negatif sur l id voulut dans ce cas on retounr e1
** sinon 0 dans e cas on retourne l d de l objet voulu
*/

int				check_neg(t_rt *glb, int id)
{
	int			c;
	t_vect3d	p;

	c = 0;
	p.x = glb->cam->origin->x + glb->cam->dir->x * glb->tab_obj->all_obj[id]->t;
	p.y = glb->cam->origin->y + glb->cam->dir->y * glb->tab_obj->all_obj[id]->t;
	p.z = glb->cam->origin->z + glb->cam->dir->z * glb->tab_obj->all_obj[id]->t;
	while (c < glb->neg_obj->size_use)
	{
		if (glb->tab_obj->all_obj[(glb->neg_obj->tab[c])]->type == SPHERE &&\
		is_inter_sphere_other(glb->tab_obj->all_obj[(glb->neg_obj->tab[c])],\
		&p))
			return (1);
		else if (glb->tab_obj->all_obj[(glb->neg_obj->tab[c])]->type ==\
		CYLINDER &&\
		is_hit_cylinder(glb, glb->tab_obj->all_obj[(glb->neg_obj->tab[c])]))
			return (1);
		c++;
	}
	return (0);
}

void			found_id(t_rt *glb, int *id)
{
	int			c;
	int			c2;
	int			id_found;
	int			actual_id;
	int			count_neg;

	c = 0;
	c2 = 1;
	id_found = -1;
	actual_id = 0;
	count_neg = 0;
	while (c < glb->tmp_obj->size_use && c2 == 1)
	{
		c2 = check_neg(glb, glb->tmp_obj->ti[c]);
		if (c2)
			c++;
	}
	if (c < glb->tmp_obj->size_use)
		*id = glb->tmp_obj->ti[c];
}
