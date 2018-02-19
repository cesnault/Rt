/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_concat_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:53:38 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 22:53:47 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_ori.h"
#include <fcntl.h>

int		file_concat_size_end(char *name, unsigned char *str, int size)
{
	int fd;

	if (!name)
		return (0);
	if ((fd = open(name, O_WRONLY | O_APPEND)) < 0)
		return (0);
	write(fd, str, size);
	close(fd);
	return (1);
}

int		file_concat_end(char *name, unsigned char *str)
{
	int fd;

	if (!name)
		return (0);
	if ((fd = open(name, O_WRONLY | O_APPEND)) < 0)
		return (0);
	write(fd, str, ft_strlen((char *)str));
	close(fd);
	return (1);
}
