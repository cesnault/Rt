/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:30:23 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 00:34:17 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

t_list	*ft_lstcreate_elem(void *data)
{
	t_list *elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->next = NULL;
	elem->content = data;
	return (elem);
}
