/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_nb_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:59:58 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/17 00:00:12 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

unsigned int		ft_file_nb_line(char *name_file)
{
	unsigned int	nb;
	int				fd;
	char			*line;

	nb = 0;
	line = 0;
	if ((fd = open(name_file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		nb++;
		ft_strdel(&line);
	}
	free(line);
	close(fd);
	return (nb);
}
