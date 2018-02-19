/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_utf8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:04:22 by jegloff           #+#    #+#             */
/*   Updated: 2016/12/02 15:04:25 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_putchar_utf8(int c)
{
	if (c < 128)
		ft_putchar(c);
	else if (c < 2048)
	{
		ft_putchar((c >> 6) + 192);
		ft_putchar((c & 63) + 128);
	}
	else if (c < 65536)
	{
		ft_putchar((c >> 12) + 224);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
	}
	else if (c < 2097152)
	{
		ft_putchar((c >> 18) + 240);
		ft_putchar(((c >> 12) & 63) + 128);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
	}
}
