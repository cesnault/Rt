/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_error_display_all.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:24:54 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 13:48:06 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gestion_error.h"
#include "ft_ori.h"

void	ft_g_error_display_all(t_error *error)
{
	int count;

	if (!error)
		return ;
	count = 0;
	while ((error[count]).id != -1)
	{
		ft_putnbr((error[count]).id);
		ft_putstr(")");
		ft_putstr(ft_g_error_get_msg_with_id(error, count));
		ft_putchar('|');
		ft_putnbr((error[count]).error);
		ft_putchar('\n');
		count++;
	}
}
