/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 23:20:51 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/01 18:43:56 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"

static void			reverse(char *str)
{
	int				size;
	int				count;
	char			temp;

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

static int			size_int(int nb, int neg)
{
	int				count;

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

static char			ft_special_char_base(int nb, int base)
{
	if (base > 10 && nb > 9)
	{
		return ('a' + nb - 10);
	}
	return (nb + '0');
}

char				*ft_itoa_base(int n, int base)
{
	int				neg;
	unsigned int	count;
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
		str[count] = (nb > ((unsigned int)base - 1)) ?\
ft_special_char_base((nb % (unsigned int)base), base) :\
ft_special_char_base(nb, base);
		nb /= base;
		count++;
	}
	if (neg == -1)
		str[count++] = '-';
	str[count] = '\0';
	reverse(str);
	return (str);
}
