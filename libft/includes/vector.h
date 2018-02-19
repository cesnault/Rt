/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:40:06 by jegloff           #+#    #+#             */
/*   Updated: 2017/04/04 15:40:36 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	double x;
	double y;
	double z;
}				t_vector;

t_vector		make_vector(double x, double y, double z);

t_vector		*vector_construct(double x, double y, double z);

t_vector		vector_norm(t_vector a);

t_vector		vector_substraction(t_vector a, t_vector b);

t_vector		vector_add(t_vector a, t_vector b);

t_vector		vector_mult(double a, t_vector b);

t_vector		vector_multi(t_vector a, t_vector b);

t_vector		vector_cross_product(t_vector v1, t_vector v2);

double			vector_len(t_vector a);

double			dot_product(t_vector a, t_vector b);
#endif
