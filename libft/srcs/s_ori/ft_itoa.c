/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:52:32 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/08 16:31:35 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

static void		reverse(char *str)
{
	int		size;
	int		count;
	char	temp;

	size = ft_strlen(str) - 1;
	count = 0;
	while (size > count)
	{
		temp = str[count];
		str[count] = str[size];
		str[size] = temp;
		size--;
		count++;
	}
}

static int		size_int(int nb, int neg)
{
	int count;

	count = 0;
	while (nb || count == 0)
	{
		nb /= 10;
		count++;
	}
	if (neg == -1)
		count++;
	return (count);
}

char			*ft_itoa(int n)
{
	int				neg;
	int				count;
	char			*str;
	unsigned int	nb;

	count = 0;
	neg = (n < 0) ? -1 : 1;
	nb = n * neg;
	str = malloc(sizeof(char) * (size_int(nb, neg) + 1));
	if (!str)
		return (NULL);
	while (nb || count == 0)
	{
		str[count] = (nb > 9) ? (nb % 10) + '0' : nb + '0';
		nb /= 10;
		count++;
	}
	if (neg == -1)
		str[count++] = '-';
	str[count] = '\0';
	reverse(str);
	return (str);
}
