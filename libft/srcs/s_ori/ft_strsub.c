/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:35:12 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:51:34 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*str;

	if (!s)
		return (0);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	count = 0;
	while (s[count + start] && count < len)
	{
		str[count] = s[start + count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
