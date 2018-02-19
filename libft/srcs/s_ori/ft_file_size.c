/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:16:10 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 14:58:04 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_ori.h"

int		ft_file_size(char *name)
{
	char	c;
	int		fd;
	int		size;
	int		retour;

	retour = ft_file_exist(name);
	size = 0;
	if (!retour)
		return (0);
	fd = open(name, O_RDONLY);
	while (read(fd, &c, 1))
		size++;
	close(fd);
	return (size);
}
