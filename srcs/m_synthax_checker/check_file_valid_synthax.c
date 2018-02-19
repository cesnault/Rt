/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_valid_synthax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:00:49 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/02 22:09:24 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "parser.h"
#include "bmp.h"
#include "synthax_checker.h"
#include "ft_ori.h"

static int	error_manage(char **str, char *msg)
{
	ft_putstr_fd(msg, 2);
	free(*str);
	return (0);
}

static int	core_core_check(int ret2, int fd, char **str)
{
	if (ret2 == RECTANGLE)
	{
		if (!(check_rectangle(fd)))
			return (error_manage(str, "synthax: error object rectangle.\n"));
	}
	else if (ret2 == SQUARE || ret2 == PYRAMID ||\
ret2 == HYPERCUBE || ret2 == PRISM_T || ret2 == PRISM_H)
	{
		if (!(check_square(fd)))
			return (error_manage(str, "synthax: error object square.\n"));
	}
	else if (ret2 == SPHEROID)
	{
		if (!(check_spheroid(fd)))
			return (error_manage(str, "synthax: error object spheroid\n"));
	}
	else if (ret2 == GENERIC)
	{
		if (!(check_generic(fd)))
			return (error_manage(str, "synthax: error object generic\n"));
	}
	return (1);
}

static int	core_check_file_valid_synthax(int ret2, char **str, int fd)
{
	if (ret2 == CAM)
	{
		if (!(check_cam(fd)))
			return (error_manage(str, "synthax: error object cam.\n"));
	}
	else if (ret2 == LIGHT)
	{
		if (!(check_light(fd)))
			return (error_manage(str, "synthax: error object light.\n"));
	}
	else if (ret2 == TRIANGLE)
	{
		if (!(check_triangle(fd)))
			return (error_manage(str, "synthax: error object triangle.\n"));
	}
	else if (ret2 == RECTANGLE || ret2 == SQUARE || ret2 == PYRAMID ||\
			ret2 == SPHEROID || ret2 == GENERIC || ret2 == HYPERCUBE ||\
		ret2 == PRISM_H || ret2 == PRISM_T)
		return (core_core_check(ret2, fd, str));
	else
	{
		if (!(check_obj(fd, ret2)))
			return (error_manage(str, "synthax: error object obj.\n"));
	}
	return (1);
}

int			check_file_valid_synthax(int fd)
{
	int		ret;
	int		ret2;
	char	*str;

	while ((ret = get_next_line(fd, &str)) > 0)
	{
		ret2 = parser_type_obj(str);
		if (ret2 != ERROR)
		{
			if (!core_check_file_valid_synthax(ret2, &str, fd))
				return (0);
		}
		else if (ret != 1 || ft_strlen(str) > 4)
			return (core_end(&str, "Invalid line:"));
		free(str);
	}
	ft_strdel(&str);
	return (1);
}
