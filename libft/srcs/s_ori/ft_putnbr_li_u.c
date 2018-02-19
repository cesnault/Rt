/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_li_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:56:15 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/01 18:38:19 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_putnbr_li_u(unsigned long int nb)
{
	if (nb > 9)
	{
		ft_putnbr_li_u(nb / 10);
		ft_putnbr_li_u(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
		nb = 0;
	}
}
