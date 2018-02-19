/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:11:19 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:11:24 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_CHECKER_H
# define VALUE_CHECKER_H

int		main_value_checker(char *name);

int		check_nb_float(char *str, int nb);

int		check_two_float(char *str, int type);

int		check_one_int2(char *str);

int		check_one_int(char *str, int type);

#endif
