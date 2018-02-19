/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_rgb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:07:35 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/06 00:08:08 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgb.h"
#include "ft_ori.h"
#include <stdlib.h>
#include "parser.h"

static t_rgb	*extract_rgb(char *data)
{
	t_rgb		*rgb;
	int			*tab;
	int			error;

	tab = ft_extract_nb_int(data, 3, &error);
	if (error == 1)
		return (0);
	if (!(rgb = malloc(sizeof(t_rgb))))
		malloc_fail("extract_rgb");
	rgb->a = tab[0];
	rgb->r = tab[1];
	rgb->g = tab[2];
	rgb->b = 0;
	free(tab);
	return (rgb);
}

t_rgb			*parser_extract_rgb(char *begining, char *data)
{
	data = parser_extract_begin(begining, data);
	if (!data)
		malloc_fail("extract_rgb");
	return (extract_rgb(data));
}
