/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:23:05 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 19:23:18 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

int	core_end(char **str, char *data)
{
	ft_putstr_fd(data, 2);
	ft_putstr_fd(*str, 2);
	ft_putstr_fd("\n", 2);
	free(*str);
	return (0);
}
