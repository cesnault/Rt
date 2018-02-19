/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_rectangle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 21:34:30 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/28 21:35:59 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>
#include <unistd.h>
#include "ft_ori.h"
#include "parser.h"
#include "math.h"
#include "rt.h"
#include "generic_parser.h"

static	void	core_spe_object(char *str, int fd, int type, t_spe_object *spe)
{
	if (type == NAME)
		spe->name = parser_extract_string("name", str);
	else if (type == POS)
		spe->origin = parser_extract_vector("pos", str);
	else if (type == DIM_RECT)
		spe->dim = parser_extract_vector2d("dim_rect", str);
	else if (type == ROT)
		spe->rot = parser_extract_vector("rot", str);
	else if (type == TEXTURE)
		spe->texture = parser_extract_texture(fd, str);
	else if (type == LIGHT_COLOR)
		spe->color_light =\
parser_extract_vector_float("light color", str);
}

t_spe_object	*extract_spe_object(int fd, int type_obj)
{
	t_spe_object	*spe;
	char			*str;
	int				ret;
	int				type;

	if (!(parser_extract_verif(fd)))
		return (0);
	if (!(spe = spe_object_init()))
		return (0);
	type = 0;
	str = 0;
	while (type != END && (ret = get_next_line(fd, &str)) > 0)
	{
		type = field_type(str);
		if (type == NAME || type == POS || type == DIM_RECT ||\
type == ROT || type == TEXTURE || type == LIGHT_COLOR)
			core_spe_object(str, fd, type, spe);
		free(str);
	}
	spe->type = type_obj;
	return (spe);
}
