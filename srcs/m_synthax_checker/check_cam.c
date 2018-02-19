/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:44:58 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 19:15:47 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "ft_ori.h"
#include "parser.h"
#include "bmp.h"
#include <stdlib.h>
#include "synthax_checker.h"

static int		core_cam(char *str, int fd, int ret2)
{
	int			pos;
	int			rot;
	int			ret;

	rot = 0;
	pos = 0;
	while (ret2 != END && (ret = get_next_line(fd, &str)) > 0)
	{
		ret2 = field_type(str);
		if (!(*str) && ret != 1 && ret2 == 0)
		{
			ft_strdel(&str);
			return (0);
		}
		else if (ret2 == POS && !pos)
			pos = 1;
		else if (ret2 == ROT && !rot)
			rot = 1;
		else if (ret2 != END)
			return (core_end(&str, "check cam: "));
		ft_strdel(&str);
	}
	ft_strdel(&str);
	return (rot == 1 && pos == 1);
}

int				check_cam(int fd)
{
	char		*str;
	int			ret;
	int			ret2;

	str = 0;
	ret2 = 1;
	ret = get_next_line(fd, &str);
	if (ret < 1 || field_type(str) != BEGIN)
	{
		ft_strdel(&str);
		return (0);
	}
	ft_strdel(&str);
	return (core_cam(str, fd, ret2));
}
