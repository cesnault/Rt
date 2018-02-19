/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extract_begin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:05:07 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/27 20:06:06 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"

char	*parser_extract_begin(char *begining, char *data)
{
	if (!begining || !data)
		return (0);
	if (ft_strncmp(data, begining, ft_strlen(begining)))
	{
		ft_putstr_fd("error: not valid input\n", 2);
		return (0);
	}
	data += ft_strlen(begining);
	if (ft_strncmp(data, " : ", 3))
	{
		ft_putstr_fd("error ...\n", 2);
		return (0);
	}
	data += 3;
	return (data);
}
