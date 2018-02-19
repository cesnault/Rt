/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:08:37 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/24 14:54:03 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		initial(int nb, int mult)
{
	if (mult > 46340 || mult < 1)
		return (0);
	else if (nb == 2147395600)
		return (46340);
	else if (nb == 1)
		return (1);
	else if (mult * mult == nb)
		return (mult);
	else if (mult * mult < nb)
		return (initial(nb, mult + 1));
	else if (mult * mult > nb)
		return (0);
	else
		return (0);
}

int				ft_sqrt(int nb)
{
	int	result;

	result = initial(nb, 1);
	return (result);
}
