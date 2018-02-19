/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:09:23 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/13 19:12:24 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <fcntl.h>
#include <stdlib.h>
#include "parser.h"
#include "rgb.h"
#include "vector.h"
#include <unistd.h>
#include "ft_ori.h"
#include "synthax_checker.h"
#include "value_checker.h"

t_all_pobject		*main_parser(char *name)
{
	t_all_pobject	*miaou;
	int				type_o;
	t_pobject		*o;
	int				fd;

	if (!main_checker_sc(name))
		return (0);
	if (!main_value_checker(name))
		return (0);
	if (!name || (fd = open(name, O_RDONLY)) == -1)
		return (0);
	miaou = init_all_pobject(1000);
	type_o = 1;
	while (type_o != 0)
	{
		type_o = found_type_obj_to_extract(fd);
		if (type_o != 0 && (o = parser_extract_generic(fd, type_o, miaou)))
			add_pobject_in_all(miaou, o);
	}
	if (fd >= 0)
		close(fd);
	return (miaou);
}
