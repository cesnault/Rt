/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1d_int_set_value_with_id.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:37:09 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/20 16:39:32 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1d_int.h"

void	ft_1d_int_set_value_with_id(t_1d_int **tab_1d, int id, int value)
{
	if (!tab_1d || !(*tab_1d) || !(*tab_1d)->tab || (*tab_1d)->len < id)
		return ;
	(*tab_1d)->tab[id] = value;
}
