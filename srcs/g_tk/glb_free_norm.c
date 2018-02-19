/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb_free_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:19:07 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/26 00:19:09 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include "gtkgui.h"

void	cam_free(t_cam *cam)
{
	free(cam->origin);
	free(cam->rot);
	free(cam->dir);
	free(cam);
	cam = NULL;
}

void	pos_obj_free(t_tir *pos_obj)
{
	free(pos_obj->tab);
	free(pos_obj);
	pos_obj = NULL;
}

void	neg_obj_free(t_tir *neg_obj)
{
	free(neg_obj->tab);
	free(neg_obj);
	neg_obj = NULL;
}

void	tmp_obj_free(t_tidr *tmp_obj)
{
	free(tmp_obj->ti);
	free(tmp_obj->td);
	free(tmp_obj);
	tmp_obj = NULL;
}

void	setting_free(t_generic_param *setting)
{
	free(setting->name);
	free(setting);
	setting = NULL;
}
