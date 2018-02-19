/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tidr_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 00:22:08 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/03 00:22:10 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_int_double_resize.h"
#include <stdlib.h>

void	tidr_destroy(t_tidr **t)
{
	if (!t || !(*t))
		return ;
	if ((*t)->ti)
		free((*t)->ti);
	if ((*t)->td)
		free((*t)->td);
	free(*t);
	*t = 0;
}
