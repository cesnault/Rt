/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_bmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 23:27:16 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/08 23:27:29 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "ft_ori.h"
#include "parser.h"
#include "bmp.h"

t_texture		*parser_extract_bmp(char *str)
{
	t_texture	*text;
	char		*s;

	if (!str || !check_extand(str, ".bmp"))
	{
		ft_putstr_fd("parser_extract_bmp: error extension.\n", 2);
		return (0);
	}
	s = parser_extract_string("link", str);
	text = import_bmp(s);
	ft_strdel(&s);
	return (text);
}
