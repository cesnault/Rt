/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:57:54 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 01:21:32 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

void	ft_lstclear(t_list **begin_list)
{
	t_list *list;

	list = *begin_list;
	while (list && list->next)
	{
		list = ft_lstlast_last(*begin_list);
		free(list->next);
		list->next = 0;
	}
	if (list)
	{
		free(list);
		*begin_list = 0;
	}
}
