/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tortoa_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:13:10 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/26 00:13:14 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"

void			var_vectortoa(int *i, int *cur, int *j)
{
	*i = -1;
	*cur = -1;
	j = 0;
}

char			*vectortoa(char *str1, char *str2, char *str3)
{
	char	*tab;
	int		i;
	int		j;
	int		len;
	int		cur;

	var_vectortoa(&i, &cur, &j);
	len = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3);
	if (!(tab = (char *)malloc(sizeof(char) * len + 3)))
		malloc_fail("vectortoa");
	while (++cur <= (int)ft_strlen(str1))
		tab[++i] = str1[j++];
	tab[i] = ' ';
	cur = -1;
	j = 0;
	while (++cur <= (int)ft_strlen(str2))
		tab[++i] = str2[j++];
	tab[i] = ' ';
	cur = -1;
	j = 0;
	while (++cur <= (int)ft_strlen(str3))
		tab[++i] = str3[j++];
	tab[i] = '\0';
	return (tab);
}
