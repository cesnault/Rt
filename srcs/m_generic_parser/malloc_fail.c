/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:35:07 by cesnault          #+#    #+#             */
/*   Updated: 2017/07/22 20:35:08 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

void		malloc_fail(char *str)
{
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("malloc failed, program will shut down\n", 2);
	exit(0);
}
