/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 00:16:36 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/13 00:16:50 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

int			get_id_with_ray(int x, int y, t_rt *rt)
{
	int		id;

	if (!rt || !(rt->cam) || !(rt->setting))
		return (-1);
	id = -1;
	rt->tmp_obj->size_use = 0;
	init_ray(x, y, rt->cam, rt->setting);
	check_hit(rt);
	found_id(rt, &id);
	return (id);
}
