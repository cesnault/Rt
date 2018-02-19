/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_char_del_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 20:22:47 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/19 20:33:00 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_tab_char.h"
#include <stdlib.h>

void	ft_2d_tab_char_del_tab(t_2d_tab_char **tab_2d)
{
	int count;

	if (!tab_2d || !(*tab_2d))
		return ;
	count = 0;
	while ((*tab_2d)->tab[count] && count < (*tab_2d)->dim)
	{
		if ((*tab_2d)->tab && (*tab_2d)->tab[count])
			free((*tab_2d)->tab[count]);
		count++;
	}
	(*tab_2d)->tab = 0;
}
