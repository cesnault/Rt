/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_base10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:53:28 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/17 16:53:34 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

int		ft_is_base10(char *str)
{
	int c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] && str[c] == ' ')
		c++;
	if (!(str[c]))
		return (0);
	if (str[c] == '-' || str[c] == '+')
		c++;
	while (str[c] && ft_isdigit(str[c]))
		c++;
	c = (str[c]) ? 0 : 1;
	return (c);
}
