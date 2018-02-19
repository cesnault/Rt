/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tir_push_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 23:50:58 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/30 23:51:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_int_resize.h"
#include <stdlib.h>

void	tir_push_value(t_tir *t, int value)
{
	if (!t || !(t->tab) || t->size_use >= t->size_max)
		return ;
	t->tab[t->size_use] = value;
	t->size_use += 1;
}
