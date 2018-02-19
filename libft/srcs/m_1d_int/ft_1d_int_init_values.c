/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1d_int_init_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:06:10 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/20 16:11:44 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1d_int.h"

void	ft_1d_int_init_values(t_1d_int **tab_1d)
{
	int count;

	if (!tab_1d || !(*tab_1d) || !((*tab_1d)->tab) || (*tab_1d)->len <= 0)
		return ;
	count = 0;
	while (count < (*tab_1d)->len)
	{
		(*tab_1d)->tab[count] = 0;
		count++;
	}
}
