/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:09:11 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/09 16:29:09 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>
#include "parser.h"

static char		*extract_string(char *data)
{
	char *res;

	if (ft_nb_word(data) == 1)
	{
		if (!(res = ft_strdup(data)))
			malloc_fail("extract_string");
		return (res);
	}
	return (0);
}

char			*parser_extract_string(char *begining, char *data)
{
	data = parser_extract_begin(begining, data);
	if (!data)
	{
		ft_putstr_fd("error ...\n", 2);
		exit(0);
	}
	return (extract_string(data));
}
