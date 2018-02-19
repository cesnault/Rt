/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1d_int_to_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:56:35 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/20 17:00:24 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1d_int.h"
#include "ft_ori.h"

void	ft_1d_int_to_string(t_1d_int *tab_1d)
{
	int count;

	count = 0;
	ft_putstr("Len : ");
	ft_putnbr(tab_1d->len);
	if (!tab_1d)
		return ;
	ft_putchar('[');
	while (count < tab_1d->len)
	{
		ft_putnbr(tab_1d->tab[count]);
		ft_putchar(',');
		count++;
	}
	ft_putstr("]\n");
}
