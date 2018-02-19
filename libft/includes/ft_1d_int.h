/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1d_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 23:07:35 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 14:35:31 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_1D_INT_H
# define FT_1D_INT_H

typedef	struct	s_1d_int
{
	int			*tab;
	int			len;
}				t_1d_int;

t_1d_int		*ft_1d_int_init(int len);

void			ft_1d_int_malloc_tab(t_1d_int **tab_1d);

void			ft_1d_int_init_values(t_1d_int **tab_1d);

int				ft_1d_int_get_len(t_1d_int *tab_1d);

int				*ft_1d_int_get_tab(t_1d_int *tab_1d);

void			ft_1d_int_set_len(t_1d_int **tab_1d, int len);

void			ft_1d_int_set_value_with_id\
				(t_1d_int **tab_1d, int id, int value);

void			ft_1d_int_to_string(t_1d_int *tab_1d);

void			ft_1d_int_del(t_1d_int **tab_1d);

void			ft_1d_int_del_tab(t_1d_int **tab_1d);

void			ft_1d_int_destruct(t_1d_int **tab_1d);

#endif
