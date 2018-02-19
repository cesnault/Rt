/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_issort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 20:48:23 by jegloff           #+#    #+#             */
/*   Updated: 2017/02/26 20:48:32 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

int		ft_int_issort(int *tab, int len)
{
	int	c;
	int	type;

	c = 0;
	type = 0;
	while (c < len - 1)
	{
		if (ft_max(tab[c], tab[c + 1]) == tab[c] && type <= 1)
			type = 1;
		else if (ft_min(tab[c], tab[c + 1]) == tab[c] &&\
(type == 0 || type == 2))
			type = 2;
		else
			return (0);
		c++;
	}
	return (type);
}
