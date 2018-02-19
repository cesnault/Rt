/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tidr_set_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 00:22:57 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/03 00:23:15 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_int_double_resize.h"

static int	found_pos_value_croiss(t_tidr *tidr, double v)
{
	int		c;

	c = 0;
	while (c < tidr->size_use && tidr->td[c] < v)
		c++;
	return (c);
}

static int	tidr_add_value(t_tidr *tidr, double v, int id)
{
	int		c;
	int		value_add;

	c = found_pos_value_croiss(tidr, v);
	if (c == tidr->size_use)
	{
		tidr->ti[tidr->size_use] = id;
		tidr->td[tidr->size_use] = v;
		tidr->size_use += 1;
		return (1);
	}
	value_add = tidr->size_use;
	while (c < value_add)
	{
		tidr->ti[value_add] = tidr->ti[value_add - 1];
		tidr->td[value_add] = tidr->td[value_add - 1];
		value_add--;
	}
	tidr->ti[c] = id;
	tidr->td[c] = v;
	tidr->size_use += 1;
	return (1);
}

void		tidr_set_double(t_tidr *tidr, int id, double v)
{
	tidr_add_value(tidr, v, id);
}
