/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1d_int_get_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:21:40 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/20 16:22:54 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_1d_int.h"

int	*ft_1d_int_get_tab(t_1d_int *tab_1d)
{
	if (!tab_1d || !(tab_1d->tab))
		return (0);
	return (tab_1d->tab);
}
