/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_resize_concat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:24:32 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/27 04:59:32 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

int			ft_str_resize_concat(char **str, char *cp)
{
	char	*str2;
	int		size_str;
	int		size_cp;

	size_str = ft_strlen(*str);
	size_cp = ft_strlen(cp);
	str2 = malloc(sizeof(char) * (size_str + size_cp + 1));
	ft_bzero(str2, size_str + size_cp + 1);
	ft_strcpy(str2, *str);
	ft_strcat(str2, cp);
	free(*str);
	*str = str2;
	return (0);
}
