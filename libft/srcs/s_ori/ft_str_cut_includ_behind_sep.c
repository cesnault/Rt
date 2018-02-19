/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cut_includ_behind_sep.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 21:51:38 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/25 21:52:17 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str_cut_includ_behind_sep(char *str, char c)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	if (!str)
		return ;
	while (str[count] != c)
		count++;
	count++;
	while (str[count2 + count])
	{
		str[count2] = str[count + count2];
		count2++;
	}
	str[count2] = '\0';
}
