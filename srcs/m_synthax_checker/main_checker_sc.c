/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_sc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:39:35 by jegloff           #+#    #+#             */
/*   Updated: 2017/05/18 18:40:04 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "ft_ori.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "parser.h"
#include "bmp.h"
#include "synthax_checker.h"

int		main_checker_sc(char *name)
{
	int	fd;
	int	ret;

	if (!name || ft_file_nb_line(name) < 2 || !check_extand(name, ".sc"))
		return (0);
	if (!name || (fd = open(name, O_RDONLY)) == -1)
	{
		ft_putstr_fd("error: file doesn't exist.\n", 2);
		return (0);
	}
	ret = check_file_valid_synthax(fd);
	if (fd >= 0)
		close(fd);
	return (ret);
}
