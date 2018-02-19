/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synthax_checker.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:11:00 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:11:02 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTHAX_CHECKER_H
# define SYNTHAX_CHECKER_H

int	main_checker_sc(char *name);

int	check_cam(int fd);

int	check_light(int fd);

int	check_texture(int fd, char *texture);

int	check_triangle(int fd);

int	check_rectangle(int fd);

int	check_square(int fd);

int	check_spheroid(int fd);

int	check_file_valid_synthax(int fd);

int	check_obj(int fd, int ret3);

int	check_generic(int fd);

int	core_end(char **str, char *data);

#endif
