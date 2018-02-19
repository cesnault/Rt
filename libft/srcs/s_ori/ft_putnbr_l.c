/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:04:32 by jegloff           #+#    #+#             */
/*   Updated: 2016/12/03 20:04:36 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_putnbr_l(long nb)
{
	unsigned long nbb;

	nbb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbb *= -1;
	}
	if (nbb > 9)
	{
		ft_putnbr_l(nbb / 10);
		ft_putnbr_l(nbb % 10);
	}
	else
	{
		ft_putchar(nbb + '0');
		nbb = 0;
	}
}
