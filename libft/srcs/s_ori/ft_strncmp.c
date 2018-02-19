/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:47:46 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:47:55 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] && s1[i] == s2[i] && --n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
