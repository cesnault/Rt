/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_type_obj_to_extract.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:04:14 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 15:16:23 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "parser.h"
#include <stdlib.h>

int			found_type_obj_to_extract(int fd)
{
	int		ret;
	int		ret2;
	char	*line;

	line = 0;
	if ((ret = get_next_line(fd, &line)) < 0)
	{
		ft_putstr_fd("found_type..._extract: Error end of file .\n", 2);
		return (ERR);
	}
	ret2 = parser_type_obj(line);
	if (!(*line) && ret == 1 && ret2 == 0)
	{
		free(line);
		return (found_type_obj_to_extract(fd));
	}
	else
	{
		free(line);
		return (ret2);
	}
}
