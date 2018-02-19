/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_char_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:17:27 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/23 03:04:07 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ori.h"
#include "ft_2d_tab_char.h"

t_2d_tab_char	*ft_2d_tab_char_init(int dim)
{
	int				x;
	t_2d_tab_char	*tab_2d;

	x = 0;
	if (dim <= 0 || (!(tab_2d = malloc(sizeof(t_2d_tab_char)))))
		return (0);
	tab_2d->dim = dim;
	tab_2d->tab = malloc(sizeof(char *) * dim);
	while (x < dim)
	{
		tab_2d->tab[x] = malloc(sizeof(char) * dim);
		x++;
	}
	return (tab_2d);
}
