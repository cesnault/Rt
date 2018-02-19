/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:48:42 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:57:12 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	count;
	char	*str;

	count = 0;
	str = (char *)b;
	while (count < len)
	{
		str[count] = c;
		count++;
	}
	return (b);
}
