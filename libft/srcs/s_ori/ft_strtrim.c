/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:38:32 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/08 16:26:35 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

static int		is_sep(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static int		nb_sep_begin(char const *str)
{
	int count;

	if (!str)
		return (0);
	count = 0;
	while (is_sep(str[count]))
		count++;
	return (count);
}

static int		nb_sep_end(char const *str)
{
	int count;
	int size;

	count = 0;
	if (!str)
		return (0);
	size = ft_strlen(str) - 1;
	if (size <= 0)
		return (0);
	while (is_sep(str[size]))
	{
		count++;
		size--;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		begin;
	int		end;
	int		count;
	int		size;

	if (!s)
		return (0);
	begin = nb_sep_begin(s);
	end = nb_sep_end(s);
	count = 0;
	size = ft_strlen(s);
	if (begin + end > size)
		str = malloc(sizeof(char) * 1);
	else
		str = malloc(sizeof(char) * (size - begin - end + 1));
	if (!str)
		return (0);
	while (count + begin < size - end)
	{
		str[count] = s[count + begin];
		count++;
	}
	str[count] = '\0';
	return (str);
}
