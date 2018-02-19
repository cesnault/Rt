/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 06:32:51 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 06:34:58 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

static void	ft_lstpush_back_elem(t_list **begin_list, t_list *data)
{
	t_list *list;

	list = *begin_list;
	while (list && list->next)
		list = list->next;
	if (!list)
		*begin_list = data;
	else
		list->next = data;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;
	t_list *temp;

	new_list = 0;
	temp = 0;
	if (!f || !lst)
		return (0);
	while (lst)
	{
		temp = f(lst);
		lst = lst->next;
		ft_lstpush_back_elem(&new_list, temp);
	}
	return (new_list);
}
