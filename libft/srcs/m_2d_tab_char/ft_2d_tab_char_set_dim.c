/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_char_set_dim.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:38:30 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/19 20:30:18 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2d_tab_char.h"
#include "ft_ori.h"

void	ft_2d_tab_char_set_dim(t_2d_tab_char **tab_2d, int dim)
{
	if (!tab_2d && !(*tab_2d) && dim <= 0)
		return ;
	ft_2d_tab_char_del_tab(tab_2d);
	(*tab_2d)->dim = dim;
	ft_2d_tab_char_generate_tab(tab_2d);
	ft_2d_tab_char_init_tab_with_value(tab_2d);
}
