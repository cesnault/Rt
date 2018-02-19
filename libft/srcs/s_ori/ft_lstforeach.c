/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 01:25:20 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 01:26:43 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void	ft_lstforeach(t_list *begin_list, void (*f)(void *))
{
	t_list *list;

	list = begin_list;
	while (list)
	{
		f(list->content);
		list = list->next;
	}
}
