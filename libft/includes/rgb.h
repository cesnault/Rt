/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:30:43 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/22 20:31:06 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

typedef struct	s_rgb
{
	int			a;
	int			r;
	int			g;
	int			b;
}				t_rgb;

t_rgb			rgb_construct(int a, int r, int g, int b);

t_rgb			*rgb_const(int r, int g, int b, int a);

void			p_rgb_construct(t_rgb *rgb, int r, int g, int b);

t_rgb			rgb_mult(t_rgb rgb, float factor);

void			p_rgb_mult(t_rgb *rgb, float factor);

t_rgb			rgb_add(t_rgb v1, t_rgb v2);

#endif
