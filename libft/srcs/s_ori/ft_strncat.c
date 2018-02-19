/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:50:37 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:50:38 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t count;
	size_t count2;

	count = 0;
	count2 = 0;
	while (s1[count])
		count++;
	while (s2[count2] && count2 < n)
	{
		s1[count + count2] = s2[count2];
		count2++;
	}
	while (s1[count + count2])
	{
		s1[count + count2] = '\0';
		count++;
	}
	return (s1);
}
