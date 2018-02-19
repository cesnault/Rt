/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:56:38 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/01 18:33:13 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void		ft_str_reverse(char *str)
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
