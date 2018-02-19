/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 20:50:23 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/26 20:50:24 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtkgui.h"
#include "rt.h"

t_all_pobject	*extract_data_for_gtk(char *name)
{
	t_all_pobject *p;

	if (!name || !(p = extract_data_little(name)))
		return (0);
	return (p);
}

char			*write_scenes_please(char *dest)
{
	dest[0] = 's';
	dest[1] = 'c';
	dest[2] = 'e';
	dest[3] = 'n';
	dest[4] = 'e';
	dest[5] = 's';
	dest[6] = '/';
	dest[7] = '\0';
	return (dest);
}

void			save_open_norme(char *str, char *dest, t_e *e)
{
	t_all_pobject	*pop;
	t_rt			*glb;

	glb = NULL;
	dest = write_scenes_please(dest);
	dest = ft_strcat(dest, str);
	if (!(pop = extract_data_for_gtk(dest)))
		return ;
	free(dest);
	glb_free(e->glb);
	if (!(glb = malloc(sizeof(t_rt))))
		malloc_fail("save_open_norme");
	data_processing(pop, glb);
	all_pobject_destroy(pop);
	update_main_texture(glb);
	e->glb = glb;
	draw(e->glb, e);
	e->imagepb = gtk_image_new_from_pixbuf(e->pixbufrt);
	e->imagepbcpy = gtk_image_new_from_pixbuf(e->pixbufrtcpy);
	gtk_label_set_text(GTK_LABEL(e->label[7]), str);
	e->perlin = 0;
}

void			save_open(GtkWidget *button, t_e *e)
{
	char			*str;
	int				j;
	int				i;
	struct dirent	*file;
	char			*dest;

	i = 0;
	j = 0;
	e->dir = opendir("./scenes");
	while (j++ < 100)
	{
		if (button == e->button_open[j])
			break ;
	}
	while (i++ < j - 1)
		file = readdir(e->dir);
	str = file->d_name;
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 8)))
		malloc_fail("save_open");
	save_open_norme(str, dest, e);
	quitwindow_open(button, e);
	if (closedir(e->dir) == -1)
		exit(0);
}
