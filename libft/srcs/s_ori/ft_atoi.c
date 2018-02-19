/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:09:30 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/08 16:37:55 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		is_separator(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r'\
	|| c == '\n' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int				ft_atoi(const char *str)
{
	int		nb;
	int		neg;
	char	*str2;

	nb = 0;
	neg = 0;
	str2 = (char *)str;
	while (*str2 && is_separator(*str2))
		str2++;
	if (*str2 && *str2 == '+')
	{
		neg += 1;
		str2++;
	}
	else if (*str2 && *str2 == '-')
	{
		neg -= 1;
		str2++;
	}
	while (*str2 && *str2 <= '9' && *str2 >= '0')
	{
		nb = (nb) ? nb * 10 + (*str2 - '0') : *str2 - '0';
		str2++;
	}
	return (neg) ? nb * neg : nb;
}
