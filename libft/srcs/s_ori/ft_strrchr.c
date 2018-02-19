/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:09:26 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/07 14:10:05 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

char	*ft_strrchr(const char *s, int c)
{
	int size;

	size = ft_strlen(s);
	while (size > 0)
	{
		if (s[size] == c)
			return ((char *)s + size);
		size--;
	}
	if (c == s[size])
		return ((char *)s + size);
	return (0);
}
