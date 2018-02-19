/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_png.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 22:13:19 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/12 22:13:20 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "ft_ori.h"
#include "parser.h"
#include "bmp.h"

t_texture		*parser_extract_png(char *str)
{
	t_texture	*text;
	char		*s;

	if (!str || !check_extand(str, ".png"))
	{
		ft_putstr_fd("parser_extract_png: error extand.\n", 2);
		return (0);
	}
	s = parser_extract_string("link", str);
	text = import_png(s);
	ft_strdel(&s);
	return (text);
}
