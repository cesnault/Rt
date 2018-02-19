/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 01:22:10 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 01:24:40 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

t_list	*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *list;

	list = begin_list;
	while (list)
	{
		if (cmp((char *)list->content, (char *)data_ref) == 0)
			return (list);
		list = list->next;
	}
	return (0);
}
