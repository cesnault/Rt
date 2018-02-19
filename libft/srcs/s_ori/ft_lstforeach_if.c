/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 01:26:52 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 01:28:22 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_lstforeach_if(t_list *begin_list, void (*f)(void *)\
			, void *data_ref, int (*cmp)())
{
	t_list *list;

	list = begin_list;
	while (list)
	{
		if (cmp(list->content, data_ref) == 0)
			f(list->content);
		list = list->next;
	}
}
