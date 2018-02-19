/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dint_tostring_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 22:30:12 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/10 22:30:18 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_2dint_tostring_fd(int **tab_int, int y, int x, int fd)
{
	int	c_y;

	c_y = 0;
	while (c_y < y)
	{
		ft_int_tostring_fd(tab_int[c_y], x, fd);
		c_y++;
	}
}
