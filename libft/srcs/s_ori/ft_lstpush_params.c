/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:45:59 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 00:51:03 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

t_list	*ft_lstpush_params(int ac, char **av)
{
	t_list	*list;
	int		count;

	list = 0;
	count = 0;
	if (ac < 0)
		return (0);
	while (count < ac)
	{
		ft_lstpush_front(&list, av[count]);
		count++;
	}
	return (list);
}
