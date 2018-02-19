/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_generic.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:11:01 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/13 20:12:39 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_ori.h"

static int			is_obj(int type)
{
	if (type == SPHERE || type == CYLINDER || type == CONE ||\
type == PLAN | type == DISK)
		return (1);
	return (0);
}

static t_pobject	*parser_core_extract_generic(int fd, int type,\
t_all_pobject *mimi)
{
	if (type == RECTANGLE)
		parser_extract_rectangle(fd, type, mimi);
	else if (type == SQUARE)
		parser_extract_square(fd, type, mimi);
	else if (type == PYRAMID)
		parser_extract_pyramid(fd, type, mimi);
	else if (type == HYPERCUBE)
		parser_extract_hypercube(fd, type, mimi);
	else if (type == PRISM_T)
		parser_extract_prism(fd, type, mimi);
	else if (type == PRISM_H)
		parser_extract_prism_hex(fd, type, mimi);
	return (0);
}

t_pobject			*parser_extract_generic(int fd, int type,\
t_all_pobject *mimi)
{
	t_pobject		*p;
	void			*obj;

	p = 0;
	obj = 0;
	if (type == CAM)
		obj = parser_extract_cam(fd);
	if (type == LIGHT)
		obj = parser_extract_light(fd);
	else if (is_obj(type))
	{
		obj = parser_extract_obj(fd);
	}
	else if (type == TRIANGLE)
		obj = parser_extract_triangle(fd);
	else if (type == RECTANGLE || type == SQUARE || type == PYRAMID ||\
type == HYPERCUBE || type == PRISM_T || type == PRISM_H)
		return (parser_core_extract_generic(fd, type, mimi));
	else if (type == SPHEROID)
		obj = parser_extract_spheroid(fd);
	else if (type == GENERIC)
		obj = parser_extract_generic_param(fd);
	if (obj)
		p = pobject_create(obj, type);
	return (p);
}
