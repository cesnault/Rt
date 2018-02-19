/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_cam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:18:04 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/27 20:18:27 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_ori.h"
#include <stdlib.h>
#include <unistd.h>

t_cam		*parser_extract_cam(int fd)
{
	char	*str;
	int		ret;
	int		type;
	t_cam	*cam;

	if (!(parser_extract_verif(fd)))
	{
		ft_putstr_fd("parser_extract_cam: error form\n", 2);
		return (0);
	}
	if (!(cam = cam_init()))
		return (0);
	type = 0;
	str = 0;
	while (type != END && (ret = get_next_line(fd, &str)) > 0)
	{
		type = field_type(str);
		if (type == POS && !(cam->origin))
			cam->origin = parser_extract_vector("pos", str);
		else if (type == ROT && !(cam->rot))
			cam->rot = parser_extract_vector("rot", str);
		if (str)
			ft_strdel(&str);
	}
	return (cam);
}
