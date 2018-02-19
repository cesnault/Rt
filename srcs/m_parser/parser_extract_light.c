/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:03:39 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 16:08:59 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "ft_ori.h"

t_light				*parser_extract_light(int fd)
{
	t_light			*light;
	int				type;
	int				ret;
	char			*str;

	str = 0;
	type = 0;
	ret = 0;
	if (!(parser_extract_verif(fd)))
		return (0);
	if (!(light = light_init()))
		return (0);
	while (type != END && (ret = get_next_line(fd, &str)) > 0)
	{
		type = field_type(str);
		if (type == POS && !(light->origin))
			light->origin = parser_extract_vector("pos", str);
		else if (type == NAME && !(light->name))
			light->name = parser_extract_string("name", str);
		else if (type == LIGHT_COLOR)
			light->color_light =\
		parser_extract_vector_float("light color", str);
		ft_strdel(&str);
	}
	return (light);
}
