/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_int_double_resize.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:48:54 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 22:53:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_INT_DOUBLE_RESIZE_H
# define TAB_INT_DOUBLE_RESIZE_H

typedef struct					s_tab_int_double_resize
{
	int							*ti;
	double						*td;
	int							size_use;
	int							size_max;
}								t_tab_int_double_resize;

typedef t_tab_int_double_resize	t_tidr;

t_tidr							*tidr_init(int size_max);

void							tidr_set_double(t_tidr *tidr, int id,\
		double v);

void							tidr_destroy(t_tidr **tidr);

t_tidr							*tidr_dup(t_tidr *t);

#endif
