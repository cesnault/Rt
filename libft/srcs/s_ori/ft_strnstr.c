/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:05:53 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/08 23:28:29 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		size;
	int		size2;
	size_t	c;
	int		c2;

	size = 0;
	size2 = 0;
	c = 0;
	while (big[size])
		size++;
	while (little[size2])
		size2++;
	if (size < size2)
		return (0);
	while (big[c] && c < len)
	{
		c2 = 0;
		while (big[c + c2] && little[c2] &&\
		big[c + c2] == little[c2] && c + c2 < len)
			c2++;
		if (c2 == size2)
			return (char *)(&(big[c]));
		c++;
	}
	return (size == 0 && size2 == 0) ? (char *)big : 0;
}
