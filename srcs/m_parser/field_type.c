/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:02:09 by cesnault          #+#    #+#             */
/*   Updated: 2017/06/15 16:35:28 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include "parser.h"

static int			type_pts(char *str)
{
	if (!ft_strncmp(str, "p1 : ", 5))
		return (P1);
	else if (!ft_strncmp(str, "p2 : ", 5))
		return (P2);
	else if (!ft_strncmp(str, "p3 : ", 5))
		return (P3);
	else if (!ft_strncmp(str, "ambiant : ", 10))
		return (AMBIANT);
	return (P3);
}

static int			core1_ft(char *str)
{
	if (!ft_strncmp(str, "pos : ", 6))
		return (POS);
	else if (!ft_strncmp(str, "dir : ", 6))
		return (DIRR);
	else if (!ft_strncmp(str, "name : ", 7))
		return (NAME);
	else if (!ft_strncmp(str, "light color : ", 14))
		return (LIGHT_COLOR);
	else if (!ft_strncmp(str, "rot : ", 6))
		return (ROT);
	else if (!ft_strncmp(str, "rey : ", 6))
		return (REY);
	else if (!ft_strncmp(str, "dim_rect : ", 11))
		return (DIM_RECT);
	else if (!ft_strncmp(str, "dim_square : ", 13))
		return (DIM_SQUARE);
	else if (!ft_strncmp(str, "texture : ", 10))
		return (TEXTURE);
	else if (!ft_strncmp(str, "neg : ", 6))
		return (NEG);
	else if (!ft_strncmp(str, "dim : ", 6))
		return (DIM);
	else if (!ft_strncmp(str, "stereoscopic : ", 15))
		return (STEREO);
	return (ERR);
}

static int			core2_ft(char *str)
{
	if (!ft_strncmp(str, "green : ", 8))
		return (GREEN);
	else if (!ft_strncmp(str, "red : ", 6))
		return (RED);
	else if (!ft_strncmp(str, "yellow : ", 9))
		return (YELLOW);
	else if (!ft_strncmp(str, "f_neg : ", 8))
		return (F_NEG);
	return (ERR);
}

static int			found_type_bbq(char *str)
{
	if (!ft_strncmp(str, "pos : ", 6) || !ft_strncmp(str, "dir : ", 6) ||\
	!ft_strncmp(str, "name : ", 7) || !ft_strncmp(str, "light color : ", 14) ||\
	!ft_strncmp(str, "rot : ", 6) || !ft_strncmp(str, "rey : ", 6) ||\
	!ft_strncmp(str, "dim_rect : ", 11) ||\
	!ft_strncmp(str, "texture : ", 10) ||\
	!ft_strncmp(str, "dim_square : ", 13) || !ft_strncmp(str, "neg : ", 6) ||\
	!ft_strncmp(str, "dim : ", 6) || !ft_strncmp(str, "stereoscopic : ", 15))
		return (1);
	return (0);
}

int					field_type(char *str)
{
	if (!str)
		return (ERR);
	else if (!ft_strncmp(str, "{", 1) && ft_strlen(str) == ft_strlen("{"))
		return (BEGIN);
	else if (found_type_bbq(str))
		return (core1_ft(str));
	else if (!ft_strncmp(str, "antialiasing : ", 15))
		return (ALIA);
	else if (!ft_strncmp(str, "sepia : ", 8))
		return (SEPIA);
	else if (!ft_strncmp(str, "p1 : ", 5) ||\
	!ft_strncmp(str, "p2 : ", 5) || !ft_strncmp(str, "p3 : ", 5) ||\
!ft_strncmp(str, "ambiant : ", 10))
		return (type_pts(str));
	else if (!ft_strncmp(str, "green : ", 8) ||\
	!ft_strncmp(str, "red : ", 6) ||\
	!ft_strncmp(str, "yellow : ", 9) || !ft_strncmp(str, "f_neg : ", 6))
		return (core2_ft(str));
	else if (!ft_strncmp(str, "}", 1) && ft_strlen(str) == ft_strlen("}"))
		return (END);
	return (ERR);
}
