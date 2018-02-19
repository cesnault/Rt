/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_error.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:11:23 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/18 17:20:40 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GESTION_ERROR_H
# define FT_GESTION_ERROR_H

typedef struct	s_error
{
	int			id;
	char		*msg;
	int			error;
}				t_error;

t_error			*ft_g_error_init(int nb);

int				ft_g_error_get_error_with_id(t_error *error, int id);

char			*ft_g_error_get_msg_with_id(t_error *error, int id);

void			ft_g_error_set_msg_with_id(t_error **error1, int id, char *msg);

void			ft_g_error_set_error_with_id(t_error **error2, int id,\
				int error1);

void			ft_g_error_display_all(t_error *error);

void			ft_g_error_display_error_only(t_error *error);

int				ft_g_error_nb(t_error *error);

void			ft_g_error_destruct(t_error **error1);

int				ft_g_error_is_error(t_error *error1);

int				ft_g_error_valid_id(t_error *error, int id);

#endif
