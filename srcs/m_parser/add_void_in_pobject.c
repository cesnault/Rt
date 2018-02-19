/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_void_in_pobject.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:16:20 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/27 20:16:28 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_void_in_pobject(t_all_pobject *all, void *data, unsigned int type)
{
	add_pobject_in_all(all, pobject_create(data, type));
}
