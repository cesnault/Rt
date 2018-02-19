# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesnault <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 20:50:21 by jegloff           #+#    #+#              #
#    Updated: 2017/06/21 18:00:48 by cesnault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Ofast -Wall -Wextra -Werror `pkg-config --cflags gtk+-3.0`
SOURCES=srcs
LIB_PATH= ./libft
INC=includes
INC_LODE=lib/lodepng
INCTEST=\
./includes/bmp.h             ./includes/parser.h          ./includes/procedural.h      ./includes/synthax_checker.h ./includes/type.h\
./includes/generic_parser.h  ./includes/perlin.h          ./includes/rt.h              ./includes/texture.h         ./includes/value_checker.h\
./includes/gtkgui.h ./lib/lodepng/lodepng.h

INC_PATH= ./$(LIB_PATH)/$(INC)
NAME= rt

SRC_M_MAIN_PATH= m_main
SRC_M_PARSER_PATH = m_parser
SRC_COLOR_PATH = color
SRC_DRAW_PATH = draw
SRC_CALCUL_PATH = calcul
SRC_OBJECT_PATH = object
SRC_RT_PATH  = raytracer
SRC_DATA_PATH = data_processing
SRC_ROTATION_PATH = rotation
SRC_M_GENERIC_PARSER_PATH= m_generic_parser
SRC_M_TEXTURE_PATH = m_texture
SRC_M_PERLIN_PATH = m_perlin
SRC_M_PROCED_PATH = m_procedural
SRC_M_TYPE_PATH = m_type
SRC_M_SYNTHAX_CHECKER_PATH = m_synthax_checker
SRC_M_BMP_PATH = m_bmp
SRC_M_VALUE_CHECKER_PATH = m_value_checker
SRC_M_POST_TREATMENT_PATH = m_post_treatment
SRC_G_INIT_PATH = g_tk
SRC_M_LODEPNG_PATH = lodepng

SRC_PATH=srcs
SRC_LIB_PATH=lib
OBJ_PATH=srcs

#################################################
### COLOR
##################################################

COL_BLACK       = \033[1;30m
COL_RED         = \033[1;31m
COL_GREEN       = \033[1;32m
COL_YELLOW      = \033[1;33m
COL_BLUE        = \033[1;34m
COL_PURPLE      = \033[1;35m
COL_WHITE       = \033[1;37m

##################################################
### SOURCES
###################################################

SRC_M_MAIN=\
main.c main_norm.c

SRC_LODEPNG=\
lodepng.c

SRC_COLOR=\
ambiante.c diffuse.c specular.c color_object.c refraction_v2.c\
color_tool.c uv_texturing.c color_picture.c color_procedural.c\
recur_refl.c shadow.c refraction_v2_norm.c uv_texturing_norm.c\
ft_vect3d.c

SRC_DRAW=\
draw.c stock.c

SRC_CALCUL=\
calcul_intersect.c\
calcul_normal.c\
vector_calcul.c\
calcul_rot.c\
vector_calcul2.c\
vector_calcul3.c\
calcul_inter_sphere_other.c\
calcul_id_with_neg.c

SRC_OBJECT=\
hit_object.c\
cylindre.c\
plan.c\
sphere.c\
cone.c\
triangle.c\
rectangle.c\
disk.c\
spheroid.c

SRC_DATA=\
init_cam.c\
init_data.c\
init_light.c\
init_mlx.c\
init_object.c

SRC_ROTATION=\
rotation.c rev_rotation.c

SRC_RT=\
ray.c rt_destroy.c ray_id.c

SRC_M_GENERIC_PARSER=\
parser_extract_begin.c        parser_extract_int.c          parser_extract_vector.c\
parser_extract_double.c       parser_extract_rgb.c          parser_extract_vector_float.c\
parser_extract_float.c        parser_extract_string.c\
parser_extract_dim.c parser_extract_vector2d.c make_triangle_bitch.c malloc_fail.c

SRC_M_PARSER=\
add_pobject_in_all.c        init_all_pobject.c          parser_extract_perlin.c\
add_void_in_pobject.c       main_parser.c               parser_extract_texture.c\
parser_extract_cam.c        parser_extract_verif.c\
field_type.c                parser_extract_generic.c    parser_type_obj.c\
field_type_texture.c        parser_extract_light.c      pobject_create.c\
found_type_obj_to_extract.c parser_extract_obj.c parser_extract_bmp.c parser_extract_png.c\
parser_extract_generic_param.c parser_extract_triangle.c\
parser_extract_rectangle.c parser_extract_square.c parser_extract_spe_object.c\
parser_extract_pyramid.c parser_extract_spheroid.c parser_extract_rectangle2.c\
parser_extract_hypercube.c parser_extract_prism.c parser_extract_prism_hex.c

SRC_M_PERLIN=\
generate_double_alea.c smooth_noise.c turbulence.c\
smooth_texture.c marble_texture.c wood_texture.c\
perlin_texture_generator.c

SRC_M_TEXTURE=\
texture_init.c texture_add_pixel.c texture_get_pixel.c texture_destroy.c\
texture_dup.c

SRC_M_PROCED=\
rgb_damier.c procedural_main.c

SRC_M_TYPE=\
f_vect3d.c f_color_light.c f_cam.c f_generic_param.c f_triangle.c\
f_light.c f_obj.c f_spe_object.c f_cam2.c f_color_light2.c\
f_vect3d2.c f_obj_destroy.c f_color_light_destroy.c\
f_ptexture_dup.c f_obj_redim.c f_light_redim.c\
f_all_pobject.c

SRC_M_SYNTHAX_CHECKER=\
main_checker_sc.c check_cam.c check_light.c check_texture.c\
check_obj.c check_triangle.c check_file_valid_synthax.c\
core_end.c check_rectangle.c check_square.c\
check_spheroid.c check_generic.c

SRC_M_BMP=\
import_bmp.c bmp_debug.c bmp_extract_struct.c bmp_tool.c\
bmp_generate_struct.c bmp_generate_data_file.c bmp_export.c\
bmp_file_verif.c import_png.c

SRC_M_VALUE_CHECKER=\
check_float.c        check_int.c main_value_checker.c

SRC_M_POST_TREATMENT=\
antialia.c sepia.c main_post_treatment.c\
green.c neg.c red.c yellow.c stereo.c

SRC_G_INIT=\
gtk_main.c init_menu.c create_menu.c create_campos.c init_campos.c\
init_addobjects.c create_addobjects.c\
callback_add_objects.c init_addlight.c init_addambiant.c create_addlight.c\
create_addambiant.c init_open.c create_open.c init_render.c create_render.c\
pixbuf.c save_addobjects.c tortoa.c init_menu_norm.c button_press.c\
save_open.c init_labels_addsphere.c init_grid_addsphere.c create_addobjects_norm.c\
copy_in_obj.c verif_entry.c glb_free.c tortoa_norm.c button_press_norm.c\
glb_free_norm.c

#################################################
#### OBJECT
################################################
OBJ_M_MAIN= $(patsubst %.c, %.o, $(SRC_M_MAIN))
OBJ_M_M= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_MAIN))

OBJ_M_LODEPNG= $(patsubst %.c, %.o, $(SRC_LODEPNG))
OBJ_M_LP= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_LODEPNG))

OBJ_M_VALUE_CHECKER= $(patsubst %.c, %.o, $(SRC_M_VALUE_CHECKER))
OBJ_M_V= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_VALUE_CHECKER))

OBJ_M_PARSER= $(patsubst %.c, %.o, $(SRC_M_PARSER))
OBJ_M_P= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_PARSER))

OBJ_COLOR= $(patsubst %.c, %.o, $(SRC_COLOR))
OBJ_C= $(addprefix ./$(OBJ_PATH)/, $(OBJ_COLOR))

OBJ_DRAW= $(patsubst %.c, %.o, $(SRC_DRAW))
OBJ_D= $(addprefix ./$(OBJ_PATH)/, $(OBJ_DRAW))

OBJ_CALCUL= $(patsubst %.c, %.o, $(SRC_CALCUL))
OBJ_CA= $(addprefix ./$(OBJ_PATH)/, $(OBJ_CALCUL))

OBJ_OBJECT= $(patsubst %.c, %.o, $(SRC_OBJECT))
OBJ_OB= $(addprefix ./$(OBJ_PATH)/, $(OBJ_OBJECT))

OBJ_RT= $(patsubst %.c, %.o, $(SRC_RT))
OBJ_RA= $(addprefix ./$(OBJ_PATH)/, $(OBJ_RT))

OBJ_DATA= $(patsubst %.c, %.o, $(SRC_DATA))
OBJ_DA= $(addprefix ./$(OBJ_PATH)/, $(OBJ_DATA))

OBJ_ROTATION= $(patsubst %.c, %.o, $(SRC_ROTATION))
OBJ_ROT= $(addprefix ./$(OBJ_PATH)/, $(OBJ_ROTATION))

OBJ_M_GENERIC_PARSER= $(patsubst %.c, %.o, $(SRC_M_GENERIC_PARSER))
OBJ_M_G= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_GENERIC_PARSER))

OBJ_M_PERLIN= $(patsubst %.c, %.o, $(SRC_M_PERLIN))
OBJ_M_PP= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_PERLIN))

OBJ_M_TEXT= $(patsubst %.c, %.o, $(SRC_M_TEXTURE))
OBJ_M_TT= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_TEXT))

OBJ_M_PROCED= $(patsubst %.c, %.o, $(SRC_M_PROCED))
OBJ_M_PPP= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_PROCED))

OBJ_M_TYPE= $(patsubst %.c, %.o, $(SRC_M_TYPE))
OBJ_M_T= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_TYPE))

OBJ_M_SYNTHAX_CHECKER= $(patsubst %.c, %.o, $(SRC_M_SYNTHAX_CHECKER))
OBJ_M_S= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_SYNTHAX_CHECKER))

OBJ_M_BMP= $(patsubst %.c, %.o, $(SRC_M_BMP))
OBJ_M_B= $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_BMP))

OBJ_M_POST_TREATMENT= $(patsubst %.c, %.o, $(SRC_M_POST_TREATMENT))
OBJ_M_PT = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_POST_TREATMENT))

OBJ_G_INIT= $(patsubst %.c, %.o, $(SRC_G_INIT))
OBJ_G_I= $(addprefix ./$(OBJ_PATH)/, $(OBJ_G_INIT))

OBJ_ALL= $(OBJ_M_LP) $(OBJ_M_PT) $(OBJ_M_G) $(OBJ_M_V) $(OBJ_M_B) $(OBJ_M_PP) $(OBJ_M_TT) $(OBJ_M_PPP) $(OBJ_M_T) $(OBJ_M_S) $(OBJ_M_M) $(OBJ_M_P)  $(OBJ_ROT) $(OBJ_C) $(OBJ_D) $(OBJ_CA) $(OBJ_OB) $(OBJ_RA) $(OBJ_DA) $(OBJ_G_I)

##################################################
### RULES
###################################################

.PHONY: all clean fclean re fcleanlib cleanlib

all: Makefile lib $(NAME)

$(NAME):$(OBJ_M_PT) $(OBJ_M_G) $(OBJ_M_V) $(OBJ_M_B) $(OBJ_M_PP) $(OBJ_M_TT) $(OBJ_M_PPP) \
$(OBJ_M_T) $(OBJ_M_S) $(OBJ_M_P) $(OBJ_M_M) $(OBJ_ROT) $(OBJ_C) $(OBJ_D) $(OBJ_OB) $(OBJ_CA)\
$(OBJ_DA) $(OBJ_RA) $(OBJ_G_I) $(OBJ_M_LP) $(INCTEST)
	make -C $(LIB_PATH)
	$(CC) $(OBJ_ALL) -I lib/lodepng `pkg-config --libs gtk+-3.0` -o $(NAME) -L libft/ -lft -I minilibx_macos/  minilibx_macos/libmlx.a -framework OpenGL -framework Appkit
	@echo "$(COL_PURPLE) ---==== Compil RT ====---"

$(OBJ_M_LP): $(OBJ_PATH)%.o : $(SRC_LIB_PATH)/$(SRC_M_LODEPNG_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [LODEPNG]"

$(OBJ_M_B): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_BMP_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [BMP]"

$(OBJ_M_M): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_MAIN_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [MAIN]"

$(OBJ_M_P): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_PARSER_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [PARSER]"

$(OBJ_C): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_COLOR_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [COLOR]"

$(OBJ_D): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_DRAW_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [DRAW]"

$(OBJ_CA): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_CALCUL_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [CALCUL]"

$(OBJ_ROT): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_ROTATION_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [ROTATION]"

$(OBJ_OB): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_OBJECT_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [OBJECT]"

$(OBJ_RA): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_RT_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [RT]"

$(OBJ_DA): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_DATA_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [DATA_PROCESSING]"

$(OBJ_M_G): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_GENERIC_PARSER_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [GENERIC PARSER]"

$(OBJ_M_PP): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_PERLIN_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [PERLIN]"

$(OBJ_M_TT): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_TEXTURE_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [TEXTURE]"

$(OBJ_M_PPP): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_PROCED_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [PROCEDURAL]"

$(OBJ_M_T): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_TYPE_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [TYPE]"

$(OBJ_M_S): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_SYNTHAX_CHECKER_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [TYPE]"

$(OBJ_M_V): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_VALUE_CHECKER_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [VALUE_CHECKER]"

$(OBJ_M_PT): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_POST_TREATMENT_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [VALUE_CHECKER]"

$(OBJ_G_I): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_G_INIT_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_LODE) -c $< -o $@
	@echo "COMPIL [GTK_INIT]"

cleanlib:
	@cd $(LIB_PATH) && make clean
	@echo "$(COL_WHITE)[ CLEAN LIBFT ]\n"

fcleanlib: cleanlib
	@cd $(LIB_PATH) && make fclean
	@echo "$(COL_WHITE)[ FCLEAN LIBFT ]\n"

lib:
	@cd $(LIB_PATH) && make;

clean: cleanlib
	@rm -f $(OBJ_ALL)
	@echo "[CLEAN]"

fclean: clean fcleanlib
	@rm  -f $(NAME)
	@echo "DELETE [$(NAME)]"

re: fclean $(NAME)
