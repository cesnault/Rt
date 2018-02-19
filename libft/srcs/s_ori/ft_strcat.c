/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:36:11 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:36:12 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *str;
	char *dest2;

	str = (char *)s2;
	dest2 = s1;
	while (*dest2)
		dest2++;
	while (*str)
	{
		*dest2 = *str;
		dest2++;
		str++;
	}
	*dest2 = '\0';
	return (s1);
}
