/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tostring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:57:31 by jegloff           #+#    #+#             */
/*   Updated: 2017/02/26 19:01:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_int_tostring_fd(int *tab_int, int len, int fd)
{
	int c;

	c = 0;
	ft_putstr_fd("[", fd);
	while (c < len)
	{
		ft_putnbr_fd(tab_int[c], 2);
		c++;
		if (c < len)
			ft_putstr_fd(", ", 2);
	}
	ft_putstr_fd("]\n", fd);
}
