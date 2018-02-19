/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:07:21 by jegloff           #+#    #+#             */
/*   Updated: 2017/07/22 20:07:25 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPORT_BMP_H
# define IMPORT_BMP_H

# include "texture.h"

/*
** En-tete du fichier (BITMA{FILEHEADER)
** 2   : m_number : signature du fichier : BM : bitmap windows |
** BA : bitmap OS2 | CI = $
** 4   : size_o : taille total du fichier en octet
** 2-2 : id_app et id_app2 : champs reserve
** 4   : offset_start : adresse de la zone de definition de l image
*/
typedef struct		s_header_bmp
{
	unsigned char	m_number[2];
	unsigned char	size_o[4];
	unsigned char	id_app[2];
	unsigned char	id_app2[2];
	unsigned char	offset_start[4];
}					t_header_bmp;

/*
** EN-tete du bitmap(BITMAPINFOHEADER)
** 4 : bi_size         : taille en octet de cette entete
** 4 : bi_width        : largeur de l image en pixels
** 4 : bi_height       : hauteur de l image en pixels
** 2 : bi_planes       : nombre de plans
** 2 : bi_bit_count    : nombre de bits par pixel
** 4 : bi_compress     : type de compression : 0 : pas de compression
** | 1 : compresse a $
** 4 : bi_size_img   : taille en octet des donnees de l image
** 4 : bi_xpixel_meter : resolution horizontale en pixels par metre
** 4 : bi_ypixel_meter : resolution vertical en pixel par metre
** 4 : bi_color_use    : nombre de couleurs dans l image : 0 = max.
** 4 : bi_color_import : nombre de couleurs importantes. 0= all
** important
*/

typedef struct		s_bmp_info_head
{
	unsigned char	bi_size[4];
	unsigned char	bi_width[4];
	unsigned char	bi_height[4];
	unsigned char	bi_planes[2];
	unsigned char	bi_bit_count[2];
	unsigned char	bi_compress[4];
	unsigned char	bi_size_img[4];
	unsigned char	bi_xpixel_meter[4];
	unsigned char	bi_ypixel_meter[4];
	unsigned char	bi_color_use[4];
	unsigned char	bi_color_import[4];
}					t_bmp_info_head;

t_texture			*import_bmp(char *name);

int					export_bmp(t_texture *text, char *name);

void				bmp_read_header(t_header_bmp bmp);

void				bmp_read_info_header(t_bmp_info_head bmp);

t_bmp_info_head		bmp_extract_bmp_info_header(int fd);

t_header_bmp		bmp_extract_header(int fd);

unsigned int		get_size_bmp(t_texture *text);

int					octet_to_int(unsigned char *str, int size);

void				head_bmp_add_size(t_texture *text, t_header_bmp *head);

void				info_bmp_add_size(t_texture *text,\
t_bmp_info_head *inf);

t_header_bmp		header_bmp_create(t_texture *text);

void				bmp_info_head_create_basic(t_texture *text,\
t_bmp_info_head *bmp);

t_bmp_info_head		bmp_info_head_create(t_texture *text);

/*
** generate data unsigned char for bmp file
*/
void				add_header_bmp(t_header_bmp bm,\
		unsigned char *data, int *count);

void				add_info_bmp(t_bmp_info_head inf,\
		unsigned char *data, int *count);

void				add_picture(t_texture *text,\
unsigned char *data, int *count);

int					bmp_export(t_texture *text, char *name);

/*
** check format
*/
int					bmp_file_verif(char *name);
int					png_file_verif(char *name);

t_texture			*import_png(char *name);

#endif
