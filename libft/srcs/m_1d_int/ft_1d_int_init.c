/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1d_int_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 23:16:43 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 13:43:34 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1d_int.h"
#include <stdlib.h>

t_1d_int	*ft_1d_int_init(int len)
{
	t_1d_int *tab_1;

	if (!(tab_1 = malloc(sizeof(t_1d_int))))
		return (NULL);
	tab_1->len = len;
	if (!(tab_1->tab = malloc(sizeof(int) * len)))
	{
		free(tab_1);
		return (0);
	}
	return (tab_1);
}
