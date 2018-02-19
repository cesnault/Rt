/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_pobject.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:03:53 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/27 20:04:06 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>
#include <unistd.h>

t_all_pobject		*init_all_pobject(unsigned int size)
{
	t_all_pobject	*obj;

	if (!(obj = malloc(sizeof(t_all_pobject))))
		malloc_fail("init_all_pobject");
	if (!(obj->all_obj = malloc(sizeof(t_pobject *) * size)))
		malloc_fail("init_all_pobject");
	obj->size_use = 0;
	obj->size_total = size;
	return (obj);
}
