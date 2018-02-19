/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_error_set_msg_with_id.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:28:01 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/22 08:28:02 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "ft_gestion_error.h"

void	ft_g_error_set_msg_with_id(t_error **error1, int id, char *msg)
{
	t_error *error;

	error = *error1;
	if (id < 0 || !error || !msg || !(ft_g_error_valid_id(error, id)))
		return ;
	(error[id]).msg = msg;
}
