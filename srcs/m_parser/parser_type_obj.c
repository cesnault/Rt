/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_type_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:08:17 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 16:37:53 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_ori.h"

static int	parser_core_obj(char *str)
{
	if (!ft_strncmp(str, "square", 5) && ft_strlen("square") ==\
			ft_strlen(str))
		return (SQUARE);
	if (!ft_strncmp(str, "sphere", 5) && ft_strlen("sphere") ==\
			ft_strlen(str))
		return (SPHERE);
	if (!ft_strncmp(str, "cylinder", 8) && ft_strlen("cylinder") ==\
			ft_strlen(str))
		return (CYLINDER);
	if (!ft_strncmp(str, "cone", 4) && ft_strlen("cone") == ft_strlen(str))
		return (CONE);
	if (!ft_strncmp(str, "rectangle", 9) && ft_strlen("rectangle") ==\
ft_strlen(str))
		return (RECTANGLE);
	if (!ft_strncmp(str, "disk", 4) && ft_strlen("disk") == ft_strlen(str))
		return (DISK);
	if (!ft_strncmp(str, "pyramid", 7) && ft_strlen("pyramid") ==\
ft_strlen(str))
		return (PYRAMID);
	return (0);
}

static int	parser_type_obj2(char *str)
{
	if (!ft_strncmp(str, "generic", 7) && ft_strlen("generic") ==\
			ft_strlen(str))
		return (GENERIC);
	if (!ft_strncmp(str, "hypercube", 9) && ft_strlen("hypercube") ==\
			ft_strlen(str))
		return (HYPERCUBE);
	if (!ft_strncmp(str, "prism_t", 7) && ft_strlen("prism_t") ==\
			ft_strlen(str))
		return (PRISM_T);
	if (!ft_strncmp(str, "prism_h", 7) && ft_strlen("prism_h") ==\
			ft_strlen(str))
		return (PRISM_H);
	return (ERROR);
}

int			parser_type_obj(char *str)
{
	int ret;

	if (!str || ft_strncmp(str, "type : ", 7))
		return (ERROR);
	str += 7;
	if ((ret = parser_core_obj(str)))
		return (ret);
	if (!ft_strncmp(str, "plan", 4) && ft_strlen("plan") == ft_strlen(str))
		return (PLAN);
	if (!ft_strncmp(str, "light", 5) && ft_strlen("light") ==\
			ft_strlen(str))
		return (LIGHT);
	if (!ft_strncmp(str, "cam", 3) && ft_strlen("cam") == ft_strlen(str))
		return (CAM);
	if (!ft_strncmp(str, "triangle", 7) && ft_strlen("triangle") ==\
			ft_strlen(str))
		return (TRIANGLE);
	return (parser_type_obj2(str));
}
