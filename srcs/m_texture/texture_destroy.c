/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:38:40 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/05 18:39:04 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include <stdlib.h>
#include "type.h"

void			texture_destroy(t_texture **text)
{
	int			c;
	t_texture	*t;

	if (!(text) || !(*text))
		return ;
	c = 0;
	t = *text;
	if (t->rgb)
	{
		while (c < t->dim.y)
		{
			free(t->rgb[c]);
			c++;
		}
		free(t->rgb);
	}
	free(t->name);
	free(t);
	*text = 0;
}
