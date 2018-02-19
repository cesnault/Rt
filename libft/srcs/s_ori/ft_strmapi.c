/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:37:50 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:54:57 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*str;

	if (!s || !f)
		return (0);
	count = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[count])
	{
		str[count] = (char)f(count, s[count]);
		count++;
	}
	str[count] = '\0';
	return ((char *)str);
}
