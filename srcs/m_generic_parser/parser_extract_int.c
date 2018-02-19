/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:12:51 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/27 20:13:35 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "parser.h"
#include <stdlib.h>

static int	extract_int(char *data, int *error)
{
	int		nb;
	int		*tab;

	tab = ft_extract_nb_int(data, 1, error);
	if (*error == 1)
		return (0);
	nb = tab[0];
	free(tab);
	return (nb);
}

int			parser_extract_int(char *begining, char *data, int *error)
{
	data = parser_extract_begin(begining, data);
	if (!data || *error == 1)
	{
		ft_putstr_fd("error ...\n", 2);
		return (0);
	}
	return (extract_int(data, error));
}
