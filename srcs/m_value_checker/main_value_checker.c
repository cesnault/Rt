/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_value_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 23:59:53 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/03 00:10:49 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "type.h"
#include "parser.h"
#include <stdlib.h>
#include <fcntl.h>
#include "value_checker.h"
#include <unistd.h>

static int	check_three_float(char *str, int type, int type2)
{
	if (type == POS || type == DIRR || type == ROT)
		str += 6;
	else if (type == P1 || type == P2 || type == P3)
		str += 5;
	else if (type2 == COLOR)
		str += 8;
	else if (type == LIGHT_COLOR)
		str += 14;
	else if (type == DIM_SQUARE)
		str += 13;
	return (check_nb_float(str, 3));
}

static int	check_one_float(char *str, int type, int type2)
{
	if (type == AMBIANT)
		str += 10;
	else if (type == REY)
		str += 6;
	else if (type2 == SPECULAR)
		str += 11;
	else if (type2 == DIFFUSE)
		str += 10;
	else if (type2 == REFRACT)
		str += 10;
	return (check_nb_float(str, 1));
}

static int	check_field_type_value(char *str)
{
	int		type;
	int		type2;

	type = field_type(str);
	type2 = field_type_texture(str);
	if ((type == ERR && type2 == ERR) || type == END || type == BEGIN ||\
	!ft_strncmp(str, "type : ", 7) ||\
	type == TEXTURE || type2 == BEGIN2 || type2 == END2 || type == NAME ||\
	type2 == PERLIN || type2 == PICTURE || type2 == PROCEDURAL || type2 == LINK)
		return (1);
	else if (type == POS || type == DIRR || type == ROT || type == P1 ||\
	type == P2 || type == P3 ||\
	type2 == COLOR || type == LIGHT_COLOR || type == DIM_SQUARE)
		return (check_three_float(str, type, type2));
	else if (type == AMBIANT || type == REY || type2 == SPECULAR ||\
	type2 == DIFFUSE\
		|| type2 == REFRACT)
		return (check_one_float(str, type, type2));
	else if (type == DIM_RECT)
		return (check_two_float(str, type));
	else if (type == NEG || type == SEPIA || type == STEREO || type == ALIA ||\
		type == GREEN || type == RED || type == YELLOW || type == F_NEG)
		return (check_one_int(str, type));
	return (1);
}

int			main_value_checker(char *name)
{
	int		ret;
	char	*str;
	int		fd;
	int		ret2;

	str = 0;
	ret = 0;
	ret2 = 2;
	if ((fd = open(name, O_RDONLY)) < 0)
		return (0);
	while (ret2 && (ret = get_next_line(fd, &str)) > 0)
	{
		ret2 = check_field_type_value(str);
		if (ret2)
			free(str);
	}
	if (fd >= 0)
		close(fd);
	free(str);
	return (ret2);
}
