/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:02:18 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 17:14:15 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_ori.h"
#include <stdlib.h>
#include "procedural.h"

int				type_texture(char *str)
{
	if (!str)
		return (0);
	else if (!ft_strncmp(str, "texture : color", 15) &&\
ft_strlen("texture : color") == ft_strlen(str))
		return (COLOR);
	else if (!ft_strncmp(str, "texture : picture", 17) &&\
ft_strlen("texture : picture") == ft_strlen(str))
		return (PICTURE);
	else if (!ft_strncmp(str, "texture : perlin", 16) &&\
ft_strlen("texture : perlin") == ft_strlen(str))
		return (PERLIN);
	else if (!ft_strncmp(str, "texture : procedural", 21) &&\
ft_strlen("texture : procedural") == ft_strlen(str))
		return (PROCEDURAL);
	return (0);
}

static void		core_extract_texture(char *s, int *type, t_ptextu *textu)
{
	if (*type == SPECULAR)
		textu->refl_specu = parser_extract_float("specular", s, type);
	else if (*type == DIFFUSE)
		textu->refl_diffuse = parser_extract_float("diffuse", s, type);
	else if (*type == COLOR)
		textu->obj = parser_extract_vector_float("color", s);
	else if (*type == REFRACT)
		textu->refract = parser_extract_float("refract", s, type);
	else if (*type == LINK)
		textu->obj = parser_extract_png(s);
	else if (*type == PERLIN)
	{
		textu->obj = parser_extract_perlin(s);
	}
	else if (*type == PROCEDURAL)
		textu->obj = procedural_type(s);
}

t_ptextu		*parser_extract_texture(int fd, char *str)
{
	int			error;
	char		*s;
	t_ptextu	*textu;
	int			type;
	int			ret;

	error = 0;
	s = 0;
	type = 1;
	if (!(textu = malloc(sizeof(t_ptextu))))
		malloc_fail("parser_extract_texture");
	textu->obj = NULL;
	textu->type = type_texture(str);
	while (type != END2 && (ret = get_next_line(fd, &s)) > 0)
	{
		type = field_type_texture(s);
		core_extract_texture(s, &type, textu);
		if (s)
			ft_strdel(&s);
	}
	return (textu);
}
