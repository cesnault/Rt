/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_perlin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:06:18 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 16:31:18 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perlin.h"
#include "parser.h"
#include "ft_point.h"
#include "ft_ori.h"

int			type_perlin(char *str)
{
	if (!(ft_strncmp(str, "perlin : wood", 13)) &&\
			ft_strlen("perlin : wood") == ft_strlen(str))
		return (WOOD);
	else if (!(ft_strncmp(str, "perlin : smooth", 15)) &&\
			ft_strlen("perlin : smooth") == ft_strlen(str))
		return (SMOOTH);
	else if (!(ft_strncmp(str, "perlin : marble", 15)) &&\
			ft_strlen("perlin : marble") == ft_strlen(str))
		return (MARBLE);
	return (-1);
}

t_texture	*parser_extract_perlin(char *str)
{
	t_point	dim;

	dim.x = 500;
	dim.y = 500;
	return (perlin_texture_generator(dim, type_perlin(str), str, 20));
}
