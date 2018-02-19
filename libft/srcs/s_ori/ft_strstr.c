/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:44:09 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:44:10 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int size;
	int size2;
	int c;
	int c2;

	size = 0;
	size2 = 0;
	c = 0;
	while (big[size])
		size++;
	while (little[size2])
		size2++;
	if (size < size2)
		return (0);
	while (big[c])
	{
		c2 = 0;
		while (big[c + c2] && little[c2] && big[c + c2] == little[c2])
			c2++;
		if (c2 == size2)
			return (char *)(&(big[c]));
		c++;
	}
	return (size == 0 && size2 == 0) ? (char *)big : 0;
}
