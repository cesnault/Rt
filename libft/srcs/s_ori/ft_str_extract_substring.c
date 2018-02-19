/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_extract_substring.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 17:33:21 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/01 18:36:59 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

char		*ft_str_extract_substring(char *str, int begin, int end)
{
	char	*new_s;
	int		count;

	if (!str || begin < 0 || begin > end || ft_strlen(str) < (size_t)end)
		return (0);
	if (!(new_s = malloc(sizeof(char) * (begin - end + 1))))
		return (0);
	count = 0;
	while ((begin + count) < end)
	{
		new_s[count] = str[begin + count];
		count++;
	}
	new_s[count] = 0;
	return (new_s);
}
