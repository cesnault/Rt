/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:06:38 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/14 18:07:19 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

static int	is_sep(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int			ft_nb_word(char *str)
{
	int		begin;
	int		nb;
	int		c;

	if (!str)
		return (0);
	c = 0;
	nb = 0;
	begin = 0;
	while (str[c])
	{
		if (!is_sep(str[c]) && begin == 0)
		{
			begin = 1;
			nb++;
		}
		else if (is_sep(str[c]) && begin == 1)
			begin = 0;
		c++;
	}
	return (nb);
}
