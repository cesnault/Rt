/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:28:43 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/22 20:29:19 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>

typedef struct	s_complex
{
	long double		x;
	long double		y;
}				t_complex;

t_complex		make_complex(long double x, long double y);

/*
** a += b
*/
void			complex_add(t_complex *a, t_complex b);

/*
** a *= b
*/
void			complex_square(t_complex *a);

#endif
