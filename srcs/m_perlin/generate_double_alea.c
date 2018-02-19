/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_double_alea.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:55:34 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/09 17:07:26 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "type.h"

static double	d_rand(void)
{
	return (rand() % 32768) / 32768.0;
}

double			**generate_double_alea(int height, int width)
{
	int			c;
	int			c2;
	double		**tab;

	srand(time(0));
	c = 0;
	if (!(tab = malloc(sizeof(double *) * height)))
		malloc_fail("generate_dou...");
	while (c < height)
	{
		c2 = 0;
		if (!(tab[c] = malloc(sizeof(double) * width)))
			malloc_fail("generate_dou");
		while (c2 < width)
		{
			tab[c][c2] = d_rand();
			c2++;
		}
		c++;
	}
	return (tab);
}

void			free_tab2d(double ***str, int size)
{
	int			c;

	c = 0;
	while (c < size)
	{
		free(str[0][c]);
		c++;
	}
	free(str[0]);
	str[0] = 0;
}
