/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_int_resize.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 23:51:33 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 22:52:21 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_INT_RESIZE_H
# define TAB_INT_RESIZE_H

typedef struct				s_tab_int_resize
{
	int						*tab;
	int						size_use;
	int						size_max;
}							t_tab_int_resize;

typedef t_tab_int_resize	t_tir;

t_tir						*tir_init(int size_max);

void						tir_push_value(t_tir *t, int value);

void						tir_destroy(t_tir **tir);

t_tir						*tir_dup(t_tir *tir);

#endif
