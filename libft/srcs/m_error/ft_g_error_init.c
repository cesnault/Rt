/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_error_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:28:11 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 14:14:09 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_gestion_error.h"

t_error	*ft_g_error_init(int nb)
{
	t_error *error;
	int		count;

	if (nb <= 0)
		return (0);
	if (!(error = (t_error *)malloc(sizeof(t_error) * nb)))
		return (NULL);
	if (!error)
		return (0);
	count = 0;
	while (count < nb - 1)
	{
		(error[count]).id = count;
		(error[count]).msg = 0;
		(error[count]).error = 0;
		count++;
	}
	(error[count]).id = -1;
	(error[count]).msg = 0;
	(error[count]).error = 0;
	return (error);
}
