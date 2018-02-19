/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:16:29 by jegloff           #+#    #+#             */
/*   Updated: 2016/12/03 17:16:36 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_putnbr_ll(long long nb)
{
	unsigned long long nbb;

	nbb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbb *= -1;
	}
	if (nbb > 9)
	{
		ft_putnbr_ll(nbb / 10);
		ft_putnbr_ll(nbb % 10);
	}
	else
	{
		ft_putchar(nbb + '0');
		nbb = 0;
	}
}
