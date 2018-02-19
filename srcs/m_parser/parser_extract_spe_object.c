/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_spe_object.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 22:39:23 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 23:14:42 by cesnault         ###   ########.fr       */
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

static t_spe_object		*spe_extract(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

static void				core_spe_object(int type, int fd, char *str,\
t_spe_object *spe)
{
	if (type == NAME)
		spe->name = parser_extract_string("name", str);
	else if (type == POS)
		spe->origin = parser_extract_vector("pos", str);
	else if (type == DIM_SQUARE)
		spe->dim = parser_extract_vector("dim_square", str);
	else if (type == ROT)
		spe->rot = parser_extract_vector("rot", str);
	else if (type == TEXTURE)
		spe->texture = parser_extract_texture(fd, str);
	else if (type == LIGHT_COLOR)
		spe->color_light = parser_extract_vector_float("light color", str);
}

t_spe_object			*parser_extract_spe_object(int fd, int type_obj)
{
	t_spe_object		*spe;
	char				*str;
	int					ret;
	int					type;

	if (!(parser_extract_verif(fd)))
		return (spe_extract("parser_extract_spe_object.\n"));
	if (!(spe = spe_object_init()))
		return (0);
	type = 0;
	str = 0;
	while (type != END && (ret = get_next_line(fd, &str)) > 0)
	{
		type = field_type(str);
		core_spe_object(type, fd, str, spe);
		free(str);
	}
	spe->type = type_obj;
	return (spe);
}
