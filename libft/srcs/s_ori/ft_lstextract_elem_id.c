/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstextract_elem_id.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 01:29:00 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 01:31:12 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

t_list		*ft_lstextract_elem_id(t_list *begin_list, int id)
{
	int		count;
	t_list	*list;

	list = begin_list;
	count = 0;
	while (list && count != id)
	{
		list = list->next;
		count++;
	}
	if (!list && count != id)
		return (0);
	return (list);
}
