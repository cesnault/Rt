/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 01:31:23 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 01:35:14 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

void		ft_lstreverse(t_list **begin_list)
{
	int		var[2];
	t_list	*list;
	t_list	*list2;
	void	*addr;

	var[0] = 0;
	var[1] = ft_lstsize(*begin_list);
	while (var[0] != (var[1] / 2))
	{
		list = ft_lstextract_elem_id(*begin_list, var[0]);
		list2 = ft_lstextract_elem_id(*begin_list, var[1] - var[0] - 1);
		addr = list->content;
		list->content = list2->content;
		list2->content = addr;
		(var[0])++;
	}
}
