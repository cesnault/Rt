/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_int_tostring.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:30:20 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/14 18:30:30 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "ft_2d_tab_int.h"

void	ft_2d_tab_int_tostring(t_2d_tab_int *tab)
{
	ft_putstr_fd("ft_2d_tab_int:\n", 2);
	ft_2dint_tostring_fd(tab->tab, tab->y, tab->x, 2);
}
