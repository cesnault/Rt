/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_error_destruct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:24:43 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 13:47:17 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gestion_error.h"
#include <stdlib.h>

void	ft_g_error_destruct(t_error **error1)
{
	int		count;
	int		end;
	t_error *error;

	error = *error1;
	count = 0;
	end = 0;
	if (!error)
		return ;
	while (!end)
	{
		if ((error[count]).id == -1)
			end = 1;
		if ((error[count]).msg)
			free((error[count]).msg);
		count++;
	}
	if (error)
		free(error);
	error = 0;
}
