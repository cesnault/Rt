/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_error_display_error_only.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:34:26 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 14:13:53 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gestion_error.h"
#include "ft_ori.h"

void	ft_g_error_display_error_only(t_error *error)
{
	int count;

	if (!error)
		return ;
	count = 0;
	while ((error[count]).id != -1)
	{
		if (ft_g_error_get_error_with_id(error, count))
		{
			ft_putendl_fd("*** ", 2);
			ft_putendl_fd(ft_g_error_get_msg_with_id(error, count), 2);
			ft_putendl_fd("\n", 2);
		}
		count++;
	}
}
