/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_char_generate_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:03:26 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 14:48:04 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_tab_char.h"
#include <stdlib.h>

static void		ft_alloc_or_free(t_2d_tab_char *tab_2)
{
	int		count;

	count = 0;
	while (count < tab_2->dim)
	{
		if (!(tab_2->tab[count] = malloc(sizeof(char) * tab_2->dim)))
		{
			tab_2->dim = 0;
			count--;
			while (count >= 0)
			{
				if (tab_2->tab[count])
					free(tab_2->tab[count]);
				count--;
			}
			if (tab_2->tab)
				free(tab_2->tab);
			tab_2->tab = 0;
			return ;
		}
		count++;
	}
}

void			ft_2d_tab_char_generate_tab(t_2d_tab_char **tab_2d)
{
	t_2d_tab_char *tab_2;

	if (!tab_2d || !(*tab_2d) || (*tab_2d)->dim <= 0)
		return ;
	tab_2 = *tab_2d;
	if (!(tab_2->tab = malloc(sizeof(char *) * tab_2->dim)))
	{
		tab_2->dim = 0;
		return ;
	}
	ft_alloc_or_free(tab_2);
}
