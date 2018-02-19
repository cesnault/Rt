/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_li_uli.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:37:06 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/01 18:46:27 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"

static void				reverse(char *str)
{
	int					size;
	int					count;
	char				temp;

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

static int				size_li(unsigned long int nb, int neg)
{
	int					count;

	count = 0;
	while (nb || count == 0)
	{
		nb /= 10;
		count++;
	}
	if (neg == -2)
		count++;
	return (count);
}

static char				ft_special_char_base(int nb, int base)
{
	if (base > 10 && nb > 9)
	{
		return ('a' + nb - 10);
	}
	return (nb + '0');
}

char					*ft_itoa_base_li_uli(long int n, int base)
{
	int					count;
	char				*str;
	unsigned long int	nb;

	count = 0;
	nb = n;
	str = malloc(sizeof(char) * (size_li(nb, 0) + 1));
	if (!str)
		return (NULL);
	while (nb || count == 0)
	{
		str[count] = (nb > (unsigned long int)(base - 1)) ?\
ft_special_char_base(nb % (unsigned long int)(base), base) :\
ft_special_char_base(nb, base);
		nb /= base;
		count++;
	}
	str[count] = '\0';
	reverse(str);
	return (str);
}
