/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_found_median.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:03:52 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/01 18:43:09 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

int		ft_int_found_median(int *tab_int, int len)
{
	int	*tab_new;
	int	ret;

	if (!(tab_new = ft_intdup(tab_int, len)))
		return (0);
	ft_int_mysort(tab_new, len);
	if (!(len % 2))
		ret = tab_new[len / 2 - 1];
	else
		ret = tab_new[len / 2];
	free(tab_new);
	return (ret);
}
