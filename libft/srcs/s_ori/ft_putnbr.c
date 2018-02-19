/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:49:46 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:49:52 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_putnbr(int nb)
{
	unsigned int nbb;

	nbb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbb *= -1;
	}
	if (nbb > 9)
	{
		ft_putnbr(nbb / 10);
		ft_putnbr(nbb % 10);
	}
	else
	{
		ft_putchar(nbb + '0');
		nbb = 0;
	}
}
