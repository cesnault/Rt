/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pobject_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:03:16 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/14 03:52:28 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

t_pobject		*pobject_create(void *obj, int type)
{
	t_pobject	*pob;

	if (!(pob = malloc(sizeof(t_pobject))))
		malloc_fail("pobject_create");
	pob->obj = obj;
	pob->type = type;
	return (pob);
}
