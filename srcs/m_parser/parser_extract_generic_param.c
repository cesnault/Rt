/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_generic_param.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:25:43 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/02 22:14:19 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_ori.h"
#include <stdlib.h>
#include <unistd.h>
#include "type.h"

static void				core_parser_gen(t_generic_param *g, char *str,\
int type)
{
	int					error;

	error = 0;
	if (type == AMBIANT)
		g->ambiant = parser_extract_float("ambiant", str, &error);
	else if (type == NAME && !(g->name))
		g->name = parser_extract_string("name", str);
	else if (type == DIM)
		g->dim = parser_extract_dim("dim", str);
	else if (type == SEPIA)
		g->sepia = parser_extract_int("sepia", str, &error);
	else if (type == STEREO)
		g->stereo = parser_extract_int("stereoscopic", str, &error);
	else if (type == ALIA)
		g->antialia = parser_extract_int("antialiasing", str, &error);
	else if (type == GREEN)
		g->green = parser_extract_int("green", str, &error);
	else if (type == RED)
		g->red = parser_extract_int("red", str, &error);
	else if (type == YELLOW)
		g->yellow = parser_extract_int("yellow", str, &error);
	else if (type == F_NEG)
		g->neg = parser_extract_int("f_neg", str, &error);
}

t_generic_param			*parser_extract_generic_param(int fd)
{
	t_generic_param		*g;
	char				*str;
	int					type;

	str = 0;
	type = 0;
	if (!(parser_extract_verif(fd)))
	{
		ft_putstr_fd("parser_extract_generic_param: error form.\n", 2);
		return (0);
	}
	if (!(g = init_generic_param()))
		return (0);
	while (type != END && get_next_line(fd, &str) > 0)
	{
		type = field_type(str);
		core_parser_gen(g, str, type);
		if (str)
			ft_strdel(&str);
	}
	return (g);
}
