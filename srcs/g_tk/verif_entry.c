/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 22:14:19 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/30 22:14:20 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "gtkgui.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int		check_file(char *tmp)
{
	struct stat		buf;

	stat(tmp, &buf);
	if (!S_ISREG(buf.st_mode))
	{
		return (0);
	}
	if (open(tmp, O_RDONLY) == -1)
	{
		return (0);
	}
	if (!tmp || !check_extand((char *)tmp, ".png"))
	{
		return (0);
	}
	return (1);
}
