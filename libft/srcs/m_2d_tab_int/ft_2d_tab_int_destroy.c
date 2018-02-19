/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_int_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 23:58:34 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/16 23:58:43 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_2d_tab_int.h"

void	ft_2d_tab_int_destroy(t_2d_tab_int **tab)
{
	int c;

	c = 0;
	while (c < tab[0]->y)
	{
		free(tab[0]->tab[c]);
		c++;
	}
	free(tab[0]);
	tab[0] = 0;
}
