/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tir_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 23:50:50 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/30 23:50:52 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tab_int_resize.h"

void	tir_destroy(t_tir **tir)
{
	if (!tir || !(*tir))
		return ;
	if ((*tir)->tab)
		free((*tir)->tab);
	free(*tir);
	*tir = 0;
}
