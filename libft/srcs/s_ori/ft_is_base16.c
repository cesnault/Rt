/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_base16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:54:50 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/17 18:54:52 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

int	is_hexa(char c)
{
	if ((c <= 'F' && c >= 'A') ||\
(c <= 'f' && c >= 'a') || (c <= '9' && c >= '0'))
		return (1);
	return (0);
}

int	ft_is_base16(char *str)
{
	int c;

	c = 2;
	if (!str)
	{
		ft_putstr_fd("str not exist ...\n", 2);
		return (0);
	}
	if (ft_strlen(str) > 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		while (str[c])
		{
			if (!is_hexa(str[c]))
				return (0);
			c++;
		}
		return (c != 2) ? 1 : 0;
	}
	else
		return (0);
}
