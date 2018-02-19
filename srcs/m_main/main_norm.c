/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 20:56:41 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/25 20:56:42 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "ft_ori.h"
#include "rt.h"
#include "type.h"
#include "texture.h"
#include "post_treatment.h"
#include "gtkgui.h"

t_all_pobject		*extract_data_little(char *name)
{
	t_all_pobject	*p;

	if (!(p = main_parser(name)))
	{
		ft_putstr("Usage : ./rt [name_file].sc\n");
		exit(0);
	}
	return (p);
}

t_all_pobject		*extract_data(int argc, char **argv)
{
	t_all_pobject	*p;

	if (argc != 2)
		return (0);
	if (!(p = extract_data_little(argv[1])))
		return (0);
	return (p);
}

void				free_generic(t_all_pobject *pop, unsigned int i)
{
	i++;
	while (i < pop->size_use)
	{
		if (pop->all_obj[i]->type == 8)
		{
			free(((t_generic_param *)pop->all_obj[i]->obj)->name);
			free(((t_generic_param *)pop->all_obj[i]->obj));
		}
		i++;
	}
}
