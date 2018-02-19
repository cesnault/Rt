/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_li.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:53:33 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/01 18:36:22 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void					ft_putnbr_li(long int nb)
{
	unsigned long int	nbb;

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
