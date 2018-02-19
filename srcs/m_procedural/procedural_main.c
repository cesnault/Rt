/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 18:36:33 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/09 16:49:24 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "procedural.h"
#include "ft_ori.h"
#include <stdlib.h>

int			*procedural_type(char *str)
{
	int		*a;

	if (!(a = malloc(sizeof(int))))
		malloc_fail("procedural_type");
	if (!(ft_strncmp(str, "procedural : damier2d", 21)))
		*a = (DAMIER2D);
	else if (!(ft_strncmp(str, "procedural : damier3d", 21)))
		*a = (DAMIER3D);
	*a = (DAMIER2D);
	return (a);
}

t_rgb		procedural_main(t_vect3d *vec, int *type)
{
	if (*type == DAMIER2D)
	{
		return (rgb_damier2d(vec));
	}
	else if (*type == DAMIER3D)
	{
		return (rgb_damier3d(vec));
	}
	return (rgb_damier3d(vec));
}
