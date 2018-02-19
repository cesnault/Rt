/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_int.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:46:29 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/15 22:47:03 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2D_TAB_INT_H
# define FT_2D_TAB_INT_H

typedef struct	s_2d_tab_int
{
	int			x;
	int			y;
	int			**tab;
}				t_2d_tab_int;

t_2d_tab_int	*ft_2d_tab_int_init(int y, int x);

int				ft_2d_tab_int_split_line(t_2d_tab_int *tab, int y, char *line);

int				ft_2d_tab_int_split_all_line(t_2d_tab_int *tab, char **data);

void			ft_2d_tab_int_tostring(t_2d_tab_int *tab);

void			ft_2d_tab_int_destroy(t_2d_tab_int **tab);

#endif
