/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_post_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:40:18 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/12 23:40:19 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "post_treatment.h"

void	main_post_treatment(t_texture *text, t_generic_param *g)
{
	if (g->sepia)
		applied_sepia(text);
	if (g->green)
		applied_green(text);
	if (g->red)
		applied_red(text);
	if (g->yellow)
		applied_yellow(text);
	if (g->neg)
		applied_negative(text);
	if (g->stereo)
		stereo(text);
}
