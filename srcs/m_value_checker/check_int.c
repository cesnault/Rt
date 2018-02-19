/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 00:05:50 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/03 00:05:59 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "type.h"
#include "parser.h"
#include <stdlib.h>
#include <fcntl.h>
#include "value_checker.h"
#include <unistd.h>

int		check_one_int2(char *str)
{
	if (!str && ft_strlen(str) != 7)
		return (0);
	str += 6;
	if (*str != '0' && *str != '1')
		return (0);
	return (1);
}

int		check_one_int(char *str, int type)
{
	if (type == NEG)
	{
		str += 6;
		if (*str != '0' && *str != '1')
			return (0);
	}
	else if (type == SEPIA)
	{
		str += 8;
		if (*str != '0' && *str != '1')
			return (0);
	}
	else if (type == STEREO || type == ALIA)
	{
		str += 15;
		if (type == STEREO && *str != '0' && *str != '1')
			return (0);
		else if (type != STEREO && !(*str >= '0' && *str <= '9'))
			return (0);
	}
	return (1);
}
