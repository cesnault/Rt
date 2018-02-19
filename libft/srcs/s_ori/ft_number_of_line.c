/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_of_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:52:18 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 14:53:27 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

int		ft_number_of_line(char *str)
{
	int		number_line;

	if (!str)
		return (0);
	number_line = 0;
	while (*str)
	{
		if (*str == '\n')
			number_line++;
		str++;
	}
	return (number_line + 1);
}
