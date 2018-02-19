/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_treatment.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:10:46 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:10:49 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POST_TREATMENT_H
# define POST_TREATMENT_H

# include "texture.h"
# include "rgb.h"
# include "rt.h"

t_rgb	anti_aliasing(t_texture *text, int x, int y, int atal);

void	applied_antialia(t_texture *ori, t_texture *tmp, int anti_alia);

void	main_post_treatment(t_texture *text, t_generic_param *g);

void	applied_sepia(t_texture *text);

void	applied_green(t_texture *text);

void	applied_negative(t_texture *text);

void	applied_red(t_texture *text);

void	applied_yellow(t_texture *text);

void	stereo(t_texture *text);

#endif
