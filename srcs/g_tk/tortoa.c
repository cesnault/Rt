/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tortoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 20:06:03 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/23 20:06:05 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

static char		*format(long long nbr, unsigned long long *grand)
{
	size_t	len;

	len = nbr >= 0 ? 1 : 2;
	nbr = nbr >= 0 ? nbr : -nbr;
	*grand = 10;
	while (*grand <= (unsigned long long)nbr)
	{
		*grand *= 10;
		len++;
	}
	return (ft_strnew(len));
}

char			*ft_lltoa_norm(long long n)
{
	char	*res;

	if (n == LLONG_MIN)
	{
		if (!(res = ft_strdup("-9223372036854775808")))
			malloc_fail("ft_lltoa");
		return (res);
	}
	return (NULL);
}

char			*ft_lltoa(long long n)
{
	int					is_neg;
	char				*nbr;
	unsigned long long	grand;
	size_t				len;
	char				*res;

	if ((res = ft_lltoa_norm(n)))
		return (res);
	nbr = format(n, &grand);
	if (nbr == NULL)
		return (NULL);
	is_neg = n < 0 ? 1 : 0;
	n *= n > 0 ? 1 : -1;
	len = 0;
	while (grand > 1)
	{
		grand = grand / 10 == 0 ? 1 : grand / 10;
		nbr[is_neg + len++] = '0' + (n / grand);
		n = n % grand;
	}
	nbr[0] = is_neg ? '-' : nbr[0];
	return (nbr);
}

static char		*fill_point(char *str, size_t lp)
{
	size_t	len;
	char	*tmp;
	char	*str2;
	size_t	i;

	i = 0;
	if (lp > 0)
	{
		len = ft_strlen(str);
		tmp = ft_strnew(len + 1);
		str2 = str;
		while (i < len + 1)
		{
			tmp[i++] = *(str2++);
			if (len - i == lp)
				tmp[i++] = '.';
		}
		ft_memdel((void **)&str);
		return (tmp);
	}
	else
	{
		ft_memdel((void **)&tmp);
		return (str);
	}
}

char			*ft_ftoa(double nb, size_t precision)
{
	char	*str;
	size_t	len;
	size_t	i;
	long	limit;

	limit = 10000000000000000;
	str = ft_lltoa((long long)nb);
	len = ft_strlen(str);
	i = 0;
	while (i <= precision)
	{
		str = (char *)ft_realloc((void **)&str, ++len + 1);
		while (nb >= limit || nb <= -limit)
			nb += nb >= limit ? -limit : limit;
		nb *= nb < 0 ? -10 : 10;
		str[len - 1] = ('0' + (((long)nb) % 10));
		i++;
	}
	str[len - 2] += str[len - 1] >= '5' ? 1 : 0;
	str[len - 1] = 0;
	str = fill_point(str, precision);
	return (str);
}
