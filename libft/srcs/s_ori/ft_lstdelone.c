/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:17:14 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 02:18:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, sizeof(size_t));
	free(*alst);
	*alst = 0;
}
