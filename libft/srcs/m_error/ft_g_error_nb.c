/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_error_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:26:21 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/22 08:26:29 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gestion_error.h"

int	ft_g_error_nb(t_error *error)
{
	int count;
	int nb;
	int end;
	int retour;

	nb = 0;
	end = 0;
	count = 0;
	if (!error)
		return (nb);
	while (!end)
	{
		retour = ft_g_error_get_error_with_id(error, count);
		if (retour == -1)
			return (nb);
		if (retour == 1)
			nb++;
		count++;
	}
	return (nb);
}
