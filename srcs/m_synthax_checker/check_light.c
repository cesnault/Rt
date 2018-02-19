/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:32:16 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 19:32:44 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "ft_ori.h"
#include "parser.h"
#include "bmp.h"
#include <stdlib.h>
#include "synthax_checker.h"

static int	core_light(char *str, int fd, int ret2)
{
	int		pos;
	int		dir;
	int		ret;

	dir = 0;
	pos = 0;
	while (ret2 != END && (ret = get_next_line(fd, &str)) > 0)
	{
		ret2 = field_type(str);
		if (!(*str) && ret != 1 && ret2 == 0)
		{
			free(str);
			return (0);
		}
		else if (ret2 == POS && !pos)
			pos = 1;
		else if (ret2 == LIGHT_COLOR && !dir)
			dir = 1;
		else if (ret2 != NAME && ret2 != END)
			return (core_end(&str, "check light: "));
		ft_strdel(&str);
	}
	ft_strdel(&str);
	return (dir == 1 && pos == 1);
}

int			check_light(int fd)
{
	char	*str;
	int		ret;
	int		ret2;

	ret2 = 1;
	str = 0;
	ret = get_next_line(fd, &str);
	if (ret < 1 || field_type(str) != BEGIN)
	{
		free(str);
		return (0);
	}
	free(str);
	return (core_light(str, fd, ret2));
}
