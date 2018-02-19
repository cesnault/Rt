/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_nb_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 22:07:06 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/27 22:07:54 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"

static int	check_error(char *data, int nb)
{
	int		nb_w;

	if (!data || data[0] == ' ')
		return (0);
	nb_w = ft_nb_word(data);
	return (nb_w == nb);
}

char		**ft_extract_nb_string(char *data, int nb, int *error)
{
	char	**str;

	if (!check_error(data, nb))
	{
		ft_putstr_fd("Invalid data ...\n", 2);
		*error = 1;
		return (0);
	}
	str = ft_strsplit(data, ' ');
	return (str);
}
