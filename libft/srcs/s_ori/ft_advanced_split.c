/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 22:22:53 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/01 22:28:26 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <stdlib.h>

static int		ft_nb_word_o(const char *str, char sep)
{
	int			nb_word;
	int			count;
	int			begin;

	nb_word = 0;
	count = 0;
	begin = 0;
	while (str && str[count])
	{
		if (begin == 0 && str[count] != sep)
		{
			nb_word++;
			begin = 1;
		}
		if (begin == 1 && str[count] == sep)
			begin = 0;
		count++;
	}
	return (nb_word);
}

static void		ft_copy_2d_in_2d(char **str, char **cp, int *count)
{
	int			c;

	c = 0;
	while (cp[c])
	{
		str[(*count)] = ft_strdup(cp[c]);
		*count += 1;
		c++;
	}
}

static void		ft_free_mtf(char ***str)
{
	int			c;

	c = 0;
	while (str[0][c])
	{
		free(str[0][c]);
		c++;
	}
	free(str[0]);
}

char			**ft_advanced_split(int argc, char **argv, int *argc2)
{
	int			count;
	int			count_tab;
	char		**tmp;
	char		**tab;

	count = 0;
	*argc2 = 0;
	while (count < argc)
	{
		*argc2 += ft_nb_word_o(argv[count], ' ');
		count++;
	}
	if (!(tab = malloc(sizeof(char *) * (*argc2))))
		return (0);
	count = 0;
	count_tab = 0;
	while (count < argc)
	{
		tmp = ft_strsplit(argv[count], ' ');
		ft_copy_2d_in_2d(tab, tmp, &count_tab);
		ft_free_mtf(&tmp);
		count++;
	}
	return (tab);
}
