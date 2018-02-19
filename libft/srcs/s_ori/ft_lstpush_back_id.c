/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:34:35 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 00:36:47 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_lstpush_back_id(t_list **begin_list, void *data, int id)
{
	t_list *list;

	list = *begin_list;
	while (list && list->next)
		list = list->next;
	if (!list)
	{
		*begin_list = ft_lstcreate_elem(data);
		if ((*begin_list))
			(*begin_list)->content_size = id;
	}
	else
	{
		list->next = ft_lstcreate_elem(data);
		if ((list->next))
			list->next->content_size = id;
	}
}
