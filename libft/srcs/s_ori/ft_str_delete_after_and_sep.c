/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_delete_after_and_sep.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:16:05 by jegloff           #+#    #+#             */
/*   Updated: 2017/03/17 19:16:08 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str_delete_after_and_sep(char *str, char sep)
{
	int c;

	if (!str)
		return ;
	c = 0;
	while (str[c] && str[c] != sep)
		c++;
	while (str[c])
	{
		str[c] = 0;
		c++;
	}
}
