/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:42:59 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/30 15:44:22 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <unistd.h>

void	ft_putstr_null(char const *s)
{
	if (!s)
	{
		write(1, "(null)", ft_strlen("(null)") + 1);
	}
	else if (*s)
		write(1, s, ft_strlen(s));
}
