/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_tab_char.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:17:18 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 14:46:54 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2D_TAB_CHAR_H
# define FT_2D_TAB_CHAR_H

typedef	struct	s_2d_tab_char
{
	int			dim;
	char		**tab;
}				t_2d_tab_char;

t_2d_tab_char	*ft_2d_tab_char_init(int dim);

void			ft_2d_tab_char_generate_tab(t_2d_tab_char **tab_2d);

void			ft_2d_tab_char_init_tab_with_value\
				(t_2d_tab_char **tab_2d);

char			ft_2d_tab_char_get_value_x_y\
				(t_2d_tab_char *tab_2d, int x, int y);

int				ft_2d_tab_char_get_dim(t_2d_tab_char *tab_2d);

void			ft_2d_tab_char_set_dim(t_2d_tab_char **tab_2d, int dim);

int				ft_2d_tab_char_found_number_type_char\
				(t_2d_tab_char **tab_2d, char c);

void			ft_2d_tab_char_to_string(t_2d_tab_char *tab_2d);

void			ft_2d_tab_char_del(t_2d_tab_char **tab_2d);

void			ft_2d_tab_char_del_tab(t_2d_tab_char **tab_2d);

void			ft_2d_tab_char_destruct(t_2d_tab_char **tab_2d);

#endif
