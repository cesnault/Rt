/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_dim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 21:22:28 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/19 21:22:53 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "parser.h"
#include <stdlib.h>
#include "ft_point.h"

static t_point	extract_point(char *data)
{
	t_point		pts;
	int			*tab;
	int			error;

	if (!(tab = ft_extract_nb_int(data, 2, &error)))
	{
		ft_putstr_fd("Errort extract pts.\n", 2);
		pts.x = 0;
		pts.y = 0;
		return (pts);
	}
	pts.x = tab[0];
	pts.y = tab[1];
	free(tab);
	return (pts);
}

t_point			parser_extract_dim(char *begining, char *data)
{
	data = parser_extract_begin(begining, data);
	if (!data)
		ft_putstr_fd("Error bitch.\n", 2);
	return (extract_point(data));
}
