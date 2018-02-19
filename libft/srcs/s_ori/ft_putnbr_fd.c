/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:42:05 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:42:07 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nbb;

	nbb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbb *= -1;
	}
	if (nbb > 9)
	{
		ft_putnbr_fd(nbb / 10, fd);
		ft_putnbr_fd(nbb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nbb + '0', fd);
		nbb = 0;
	}
}
