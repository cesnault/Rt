/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:53:59 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 22:54:06 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <fcntl.h>
#include <unistd.h>

int		file_create(char *name)
{
	int	fd;

	if (!name || ft_file_exist(name) ||\
	(fd = open(name, O_CREAT, 0777)) < 0)
		return (0);
	close(fd);
	return (1);
}
