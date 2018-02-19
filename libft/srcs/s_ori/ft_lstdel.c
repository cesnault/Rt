/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:26:28 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/09 02:37:14 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *hero_de_puta;
	t_list *bitch;

	hero_de_puta = *alst;
	bitch = *alst;
	while (bitch)
	{
		bitch = hero_de_puta->next;
		del(hero_de_puta->content, hero_de_puta->content_size);
		free(hero_de_puta);
		hero_de_puta = bitch;
	}
	*alst = NULL;
}
