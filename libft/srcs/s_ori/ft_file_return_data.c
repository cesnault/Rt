/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_return_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:48:26 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 14:57:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_ori.h"

char	*ft_file_return_data(char *name)
{
	char	*str;
	char	c;
	int		count;
	int		size;
	int		fd;

	size = ft_file_size(name);
	if (!name || size <= 0)
		return (0);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	fd = open(name, O_RDONLY);
	count = 0;
	while (read(fd, &c, 1) && count < size)
	{
		str[count] = c;
		count++;
	}
	close(fd);
	str[size - 1] = '\0';
	return (str);
}
