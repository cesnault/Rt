/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_error_valid_id.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:26:05 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/22 08:26:13 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "ft_gestion_error.h"

int	ft_g_error_valid_id(t_error *error, int id)
{
	int count;
	int end;

	count = 0;
	end = 0;
	while ((error[count]).id != -1 && !end)
	{
		if (id == count)
			end = 1;
		count++;
	}
	return (end);
}
