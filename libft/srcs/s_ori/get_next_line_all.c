/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 22:20:34 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/16 23:55:13 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char		***get_next_line_all(char *name_file)
{
	char	***tab;
	char	*line;
	int		fd;
	int		nb;

	line = 0;
	nb = ft_file_nb_line(name_file);
	if (!nb)
		return (0);
	if ((fd = open(name_file, O_RDONLY)) == -1)
		return (0);
	if (!(tab = malloc(sizeof(char **) * (nb + 1))))
		return (0);
	nb = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tab[nb] = ft_strsplit(line, ' ');
		ft_strdel(&line);
		nb++;
	}
	free(line);
	tab[nb] = 0;
	return (tab);
}
