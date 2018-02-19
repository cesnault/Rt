/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_egal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:05:31 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/22 21:05:40 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

int		ft_str_egal(char *str1, char *str2)
{
	int	size1;
	int	size2;
	int	c;

	c = 0;
	if (!str1 || !str2)
		return (0);
	size1 = ft_strlen(str1);
	size2 = ft_strlen(str2);
	if (size1 != size2)
		return (0);
	while (c < size1)
	{
		if (str1[c] != str2[c])
			return (0);
		c++;
	}
	return (1);
}
