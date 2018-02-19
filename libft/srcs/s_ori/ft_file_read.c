/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 00:00:31 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/17 00:00:41 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <fcntl.h>
#include <unistd.h>

void		ft_file_read(char *name_file)
{
	int		fd;
	char	*line;

	line = 0;
	if ((fd = open(name_file, O_RDONLY)) == -1)
		return ;
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	close(fd);
}
