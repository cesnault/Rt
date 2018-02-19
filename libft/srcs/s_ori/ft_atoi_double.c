/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:55:55 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 23:04:20 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		is_separator(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r'\
	|| c == '\n' || c == ' ')
	{
		return (1);
	}
	return (0);
}

static char		*init_data(double *nb, int *neg,\
		const char *str, int *is_divide)
{
	*nb = 0;
	*neg = 0;
	*is_divide = 0;
	return ((char *)str);
}

static char		*begin_processing(char *str2, int *neg)
{
	while (*str2 && is_separator(*str2))
		str2++;
	if (*str2 && *str2 == '+')
	{
		*neg += 1;
		str2++;
	}
	else if (*str2 && *str2 == '-')
	{
		*neg -= 1;
		str2++;
	}
	return (str2);
}

double			ft_atoi_double(const char *str)
{
	double		nb;
	int			neg;
	char		*str2;
	int			is_divide;
	double		divide;

	str2 = init_data(&nb, &neg, str, &is_divide);
	divide = 1;
	str2 = begin_processing(str2, &neg);
	while (*str2 && ((*str2 <= '9' && *str2 >= '0') || *str2 == '.'))
	{
		if (is_divide)
			divide *= 10.0;
		if (*str2 != '.')
			nb = (nb) ? nb * 10 + (*str2 - '0') : *str2 - '0';
		else
			is_divide = 1;
		str2++;
	}
	nb /= divide;
	if (nb > 2147483647)
		nb = 0;
	return (neg) ? nb * neg : nb;
}
