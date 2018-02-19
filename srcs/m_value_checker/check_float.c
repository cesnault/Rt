/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 23:50:30 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/02 23:59:42 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

static char	*core_float(char *str, int *neg, int *pts, int *num)
{
	if (*str == '-' || *str == '+')
	{
		*neg = 1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		*num += 1;
		str++;
	}
	while (*str && *str == '.')
	{
		*pts += 1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		*num += 1;
		str++;
	}
	return (str);
}

static char	*check_float(char *str, int *error)
{
	int		neg;
	int		pts;
	int		num;

	neg = 0;
	pts = 0;
	num = 0;
	str = core_float(str, &neg, &pts, &num);
	*error = 1;
	if (num > 1 && pts == 1 && neg <= 1)
		*error = 0;
	return (str);
}

int			check_nb_float(char *str, int nb)
{
	int		error;
	int		nb_float;

	error = 0;
	nb_float = 0;
	while (str && *str && error == 0 && nb_float < nb)
	{
		str = check_float(str, &error);
		nb_float++;
		if (nb_float < nb && *str)
			str++;
	}
	if (error == 0 && !(*str) && nb_float == nb)
		return (1);
	return (0);
}

int			check_two_float(char *str, int type)
{
	if (type == DIM_RECT)
		str += 11;
	return (check_nb_float(str, 2));
}
