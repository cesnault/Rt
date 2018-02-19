/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:01:51 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 21:17:47 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "ft_ori.h"
#include "parser.h"
#include "bmp.h"
#include <stdlib.h>
#include "synthax_checker.h"

static void		core_man(int ret2, int *tab)
{
	if (ret2 == SPECULAR)
		tab[2] += 1;
	else if (ret2 == REFRACT)
		tab[3] += 1;
	else if (ret2 == DIFFUSE)
		tab[1] += 1;
}

static int		basic_quit(char **str)
{
	ft_strdel(str);
	return (0);
}

static int		we_are_refactoring(int ret2, int type_text, char **str)
{
	if (ret2 == COLOR)
	{
		if (COLOR != type_text)
			return (core_end(str, "check_texture - error color : "));
	}
	else if (ret2 == LINK)
	{
		if (PICTURE != type_text)
			return (core_end(str, "check_texture - error link :"));
		else if (png_file_verif(*str + 7))
			return (core_end(str, "check_texture - error texture format : "));
	}
	else if (ret2 == PERLIN)
	{
		if (PERLIN != type_text || type_perlin(*str) == -1)
			return (core_end(str, "check_texture - error perlin : "));
	}
	else if (ret2 == PROCEDURAL)
	{
		if (PROCEDURAL != type_text)
			return (core_end(str, "check_texture - error procedural : "));
	}
	else if (ret2 != NAME && ret2 != END2)
		return (core_end(str, "check_texture - error : "));
	return (1);
}

static int		core_texture(int ret2, int fd, char *str, int type_text)
{
	int			ret;
	int			tab[4];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	while (ret2 != END2 && (ret = get_next_line(fd, &str)) > 0)
	{
		ret2 = field_type_texture(str);
		if (!(*str) && ret != 1 && field_type_texture(str) == 0)
			return (basic_quit(&str));
		else if (ret2 == SPECULAR || ret2 == DIFFUSE || ret2 == REFRACT)
			core_man(ret2, tab);
		else if (ret2 == COLOR || ret2 == LINK || ret2 == PERLIN ||\
		ret2 == PROCEDURAL || (ret2 != NAME && ret2 != END2))
			if (!(we_are_refactoring(ret2, type_text, &str)))
				return (0);
		if (ret2 == COLOR || ret2 == LINK ||\
		ret2 == PERLIN || ret2 == PROCEDURAL)
			tab[0] += 1;
		ft_strdel(&str);
	}
	return (tab[0] == 1 && tab[2] == 1 && tab[1] == 1 && tab[3] == 1);
}

int				check_texture(int fd, char *texture)
{
	char		*str;
	int			ret;
	int			ret2;
	int			type_text;

	ret2 = 1;
	str = 0;
	if ((type_text = type_texture(texture)) == 0)
	{
		ft_putstr_fd("check_texture: unknown texture.\n", 2);
		return (0);
	}
	ret = get_next_line(fd, &str);
	if (ret < 1 || field_type_texture(str) != BEGIN2)
		return (0);
	free(str);
	return (core_texture(ret2, fd, str, type_text));
}
