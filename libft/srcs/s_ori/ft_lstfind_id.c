/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:47:33 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/25 19:51:58 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <string.h>

t_list	*ft_lstfind_id(t_list *begin_list, size_t id)
{
	t_list *list;

	list = begin_list;
	while (list)
	{
		if (list->content_size == id)
			return (list);
		list = list->next;
	}
	return (0);
}
