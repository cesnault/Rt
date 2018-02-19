/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_all_pobject.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 21:45:09 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/29 21:45:15 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

void	all_pobject_destroy(t_all_pobject *p)
{
	unsigned int i;

	i = 0;
	if (!p)
		return ;
	while (i < p->size_use)
	{
		free(p->all_obj[i]);
		i++;
	}
	if ((p->all_obj))
		free(p->all_obj);
	free(p);
}
