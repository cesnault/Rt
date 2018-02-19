/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 20:40:38 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/02 20:40:39 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

int		check_extand(char *str, char *ext)
{
	int	size;
	int	size2;
	int	ret;
	int	c;

	ret = 1;
	c = 0;
	size = ft_strlen(str);
	size2 = ft_strlen(ext);
	if (size < size2)
		ret = 0;
	else
	{
		size -= size2;
		while (ext[c] && str[size + c] == ext[c])
			c++;
	}
	if (!(ret && c == size2))
	{
		ft_putstr_fd("* Error : invalid size check_ext\n", 2);
		return (0);
	}
	return (1);
}
