/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:02:21 by jegloff           #+#    #+#             */
/*   Updated: 2017/02/26 18:02:29 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_intdup(int *tab_1d, int len)
{
	int		*tab_new;
	int		c;

	if (!tab_1d || !(tab_new = malloc(sizeof(int) * len)))
		return (0);
	c = 0;
	while (c < len)
	{
		tab_new[c] = tab_1d[c];
		c++;
	}
	return (tab_new);
}
