/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_color_light_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 20:44:53 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/05 20:45:42 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "type.h"

void		free_all_light(t_light **light, int size)
{
	int		c;
	t_light	*l;

	if (!light || !(*light))
		return ;
	c = 0;
	l = *light;
	while (c < size)
	{
		free(&(l[c]));
		c++;
	}
	free(*light);
	*light = 0;
}
