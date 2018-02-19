/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:39:36 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:54:42 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		size1;
	int		size2;
	char	*str;

	if (!s1 || !s2)
		return (0);
	count = 0;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!str)
		return (0);
	while (count < size1)
	{
		str[count] = s1[count];
		count++;
	}
	while (count - size1 < size2)
	{
		str[count] = s2[count - size1];
		count++;
	}
	str[count] = '\0';
	return (str);
}
