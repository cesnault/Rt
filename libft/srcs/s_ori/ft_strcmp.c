/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:48:34 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:48:35 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int count;

	count = 0;
	while (s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
