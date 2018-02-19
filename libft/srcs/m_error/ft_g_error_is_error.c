/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_error_is_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:59:50 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/20 18:04:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gestion_error.h"

int	ft_g_error_is_error(t_error *error1)
{
	int count;

	count = 0;
	if (!error1 || error1->id < 0)
		return (1);
	while (error1[count].id != -1)
	{
		if (error1[count].error == 1)
			return (1);
		count++;
	}
	return (0);
}
