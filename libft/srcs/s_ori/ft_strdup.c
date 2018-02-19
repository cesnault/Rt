/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:35:20 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:49:34 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	unsigned int	count;
	char			*str;
	unsigned int	size;

	count = 0;
	size = ft_strlen(s1);
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (0);
	while (s1[count] && count < size)
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
