/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1d_int_set_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:39:43 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/20 16:43:39 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1d_int.h"

void	ft_1d_int_set_len(t_1d_int **tab_1d, int len)
{
	ft_1d_int_del_tab(tab_1d);
	(*tab_1d)->len = len;
	ft_1d_int_malloc_tab(tab_1d);
	ft_1d_int_init_values(tab_1d);
}
