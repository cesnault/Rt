/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:44:30 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/19 17:44:50 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex		make_complex(long double x, long double y)
{
	t_complex	cp;

	cp.x = x;
	cp.y = y;
	return (cp);
}
