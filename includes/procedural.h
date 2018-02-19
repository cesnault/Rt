/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procedural.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:08:26 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:08:28 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCEDURAL_H
# define PROCEDURAL_H

# include "rgb.h"
# include "vector.h"
# include "parser.h"

enum	e_procedural
{
	DAMIER2D,
	DAMIER3D
};

t_rgb	procedural_main(t_vect3d *vec, int *type);

int		*procedural_type(char *str);

t_rgb	rgb_damier2d(t_vect3d *vec);

t_rgb	rgb_damier3d(t_vect3d *vec);

#endif
