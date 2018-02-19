/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:06:20 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/13 20:12:05 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_ori.h"
#include <stdlib.h>
#include <unistd.h>

static void		core_parser_obj(t_obj *obj, int *type, char *str, int fd)
{
	if (*type == POS && !(obj->origin))
		obj->origin = parser_extract_vector("pos", str);
	else if (*type == DIRR && !(obj->dir))
		obj->dir = parser_extract_vector("dir", str);
	else if (*type == NAME && !(obj->name))
		obj->name = parser_extract_string("name", str);
	else if (*type == ROT && !(obj->rot))
		obj->rot = parser_extract_vector("rot", str);
	else if (*type == REY)
		obj->rey = parser_extract_double("rey", str, type);
	else if (*type == TEXTURE)
		obj->texture = parser_extract_texture(fd, str);
	else if (*type == NEG)
		obj->neg = str[6] - '0';
}

t_obj			*parser_extract_obj(int fd)
{
	char		*str;
	int			ret;
	int			type;
	t_obj		*obj;

	type = 1;
	str = 0;
	if (!(parser_extract_verif(fd)))
		return (0);
	if (!(obj = obj_init()))
		return (0);
	while (type != END && (ret = get_next_line(fd, &str)) > 0)
	{
		type = field_type(str);
		core_parser_obj(obj, &type, str, fd);
		if (str)
			ft_strdel(&str);
	}
	return (obj);
}
