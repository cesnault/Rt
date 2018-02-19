/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:37:41 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 00:39:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_lstpush_front(t_list **begin_list, void *data)
{
	t_list *list;

	list = *begin_list;
	if (!list)
		*begin_list = ft_lstcreate_elem(data);
	else
	{
		*begin_list = ft_lstcreate_elem(data);
		(*begin_list)->next = list;
	}
}
