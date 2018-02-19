/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_type_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:05:26 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/06 00:05:59 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "parser.h"

int	field_type_texture(char *str)
{
	if (!str)
		return (ERRR);
	else if (!ft_strncmp(str, "[", 1) && ft_strlen(str) == ft_strlen("["))
		return (BEGIN2);
	else if (!ft_strncmp(str, "color : ", 8))
		return (COLOR);
	else if (!ft_strncmp(str, "link : ", 7))
		return (LINK);
	else if (!ft_strncmp(str, "perlin : ", 9))
		return (PERLIN);
	else if (!ft_strncmp(str, "diffuse : ", 10))
		return (DIFFUSE);
	else if (!ft_strncmp(str, "specular : ", 11))
		return (SPECULAR);
	else if (!ft_strncmp(str, "procedural : ", 13))
		return (PROCEDURAL);
	else if (!ft_strncmp(str, "refract : ", 10))
		return (REFRACT);
	else if (!ft_strncmp(str, "]", 1) && ft_strlen(str) == ft_strlen("]"))
		return (END2);
	return (ERRR);
}
