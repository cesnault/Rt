/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:37:15 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/01 18:37:19 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <unistd.h>

void	ft_putstr_utf8(int const *tab)
{
	if (!tab)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (*tab)
	{
		ft_putchar_utf8(*tab);
		tab++;
	}
}
