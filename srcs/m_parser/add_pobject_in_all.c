/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pobject_in_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:15:57 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/27 20:16:09 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_pobject_in_all(t_all_pobject *all, t_pobject *obj)
{
	if (!all || !obj || all->size_use >= all->size_total)
		return ;
	all->all_obj[all->size_use] = (void *)obj;
	all->size_use += 1;
}
