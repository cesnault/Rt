/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_verif.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:09:21 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/06 00:09:32 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_ori.h"
#include <stdlib.h>
#include <unistd.h>

int			parser_extract_verif(int fd)
{
	int		ret;
	char	*str;

	str = 0;
	if ((ret = get_next_line(fd, &str)) < 0)
	{
		ft_putstr_fd("parser_extract_cam: error file ...\n", 2);
		return (0);
	}
	if (field_type(str) != BEGIN)
	{
		ft_putstr_fd("parser)extract_cam: error begin ...\n", 2);
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
