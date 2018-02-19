# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegloff <marvin@42.fr>                      +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/11 18:55:58 by jegloff           #+#    #+#              #
#    Updated: 2017/03/11 18:55:59 by jegloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
### OPTION
##################################################

CC=gcc
CFLAGS= -Wall -Wextra -Werror
NAME=libft.a
SRC_PATH=srcs
SRC_M_LIBFT_PATH=s_ori
SRC_M_POINT_PATH=m_point
SRC_M_3D_PTS_PATH=m_3d_pts
SRC_M_ERROR_PATH=m_error
SRC_M_2D_TAB_PATH=m_2d_tab_char
SRC_M_1D_INT_PATH=m_1d_int
SRC_M_2D_TAB_INT_PATH=m_2d_tab_int
SRC_M_2D_PTS_MAP_PATH=m_2d_pts_map
SRC_M_COMPLEX_PATH=m_complex
SRC_M_RGB_PATH=m_rgb
SRC_M_VECTOR_PATH=vector
SRC_M_TIR_PATH=tab_int_resize
SRC_M_TIDR_PATH=tab_int_double_resize

OBJ_PATH=srcs
INC_PATH=includes
LIB_PATH=libft
INC=libft/includes
INCBITCH=\
includes/ft_1d_int.h        includes/ft_2d_tab_char.h   includes/ft_3d_pts.h        includes/ft_ori.h\
includes/ft_2d_pts_map.h    includes/ft_2d_tab_int.h    includes/ft_gestion_error.h includes/ft_point.h\
includes/complex.h includes/rgb.h includes/vector.h
#################################################
### COLOR
##################################################

COL_BLACK		= \033[1;30m
COL_RED			= \033[1;31m
COL_GREEN		= \033[1;32m
COL_YELLOW		= \033[1;33m
COL_BLUE		= \033[1;34m
COL_PURPLE		= \033[1;35m
COL_WHITE		= \033[1;37m

#################################################
### SOURCES
##################################################

SRC_M_LIBFT=\
check_extand.c deg_to_rad.c\
pow2.c get_next_line_all.c ft_is_base10.c ft_is_base16.c\
ft_abs.c                                ft_lstforeach_if.c                      ft_putstr_utf8.c\
ft_advanced_split.c                     ft_lstiter.c                            ft_sqrt.c\
ft_atoi.c                               ft_lstlast.c                            ft_str_cut_includ_behind_sep.c\
ft_atoi_long_long_int.c                 ft_lstlast_last.c                       ft_str_extract_substring.c\
ft_bzero.c                              ft_lstmap.c                             ft_str_resize_concat.c\
ft_char_is_present_in_str.c             ft_lstnew.c                             ft_str_return_extract_line_behind_sep.c\
ft_file_exist.c                         ft_lstpush_back.c                       ft_str_reverse.c\
ft_file_return_data.c                   ft_lstpush_back_id.c                    ft_strarg_free.c\
ft_file_size.c                          ft_lstpush_front.c                      ft_strcat.c\
ft_int_found_median.c                   ft_lstpush_params.c                     ft_strchr.c\
ft_int_found_nb_value.c                 ft_lstreverse.c                         ft_strclr.c\
ft_int_found_value_index.c              ft_lstsize.c                            ft_strcmp.c\
ft_int_isordon.c                        ft_max.c                                ft_strcpy.c\
ft_int_issort.c                         ft_memalloc.c                           ft_strdel.c\
ft_int_max.c                            ft_memccpy.c                            ft_strdup.c\
ft_int_min.c                            ft_memchr.c                             ft_strequ.c\
ft_int_mysort.c                         ft_memcmp.c                             ft_striter.c\
ft_int_mysort_r.c                       ft_memcpy.c                             ft_striteri.c\
ft_int_pos_value.c                      ft_memdel.c                             ft_strjoin.c\
ft_int_swap_pos.c                       ft_memmove.c                            ft_strlcat.c\
ft_int_tostring.c                       ft_memset.c                             ft_strlen.c\
ft_intdup.c                             ft_min.c                                ft_strmap.c\
ft_isalnum.c                            ft_number_of_line.c                     ft_strmapi.c\
ft_isalpha.c                            ft_putchar.c                            ft_strncat.c\
ft_isascii.c                            ft_putchar_all_ascii.c                  ft_strncmp.c\
ft_isdigit.c                            ft_putchar_fd.c                         ft_strncpy.c\
ft_isprint.c                            ft_putchar_uc.c                         ft_strnequ.c\
ft_itoa.c                               ft_putchar_utf8.c                       ft_strnew.c\
ft_itoa_base.c                          ft_putendl.c                            ft_strnstr.c\
ft_itoa_base_li_uli.c                   ft_putendl_fd.c                         ft_strrchr.c\
ft_itoa_base_ui.c                       ft_putnbr.c                             ft_strsplit.c\
ft_lstadd.c                             ft_putnbr_fd.c                          ft_strstr.c\
ft_lstclear.c                           ft_putnbr_l.c                           ft_strsub.c\
ft_lstcreate_elem.c                     ft_putnbr_li.c                          ft_strtrim.c\
ft_lstdel.c                             ft_putnbr_li_u.c                        ft_swap.c\
ft_lstdelone.c                          ft_putnbr_ll.c                          ft_tolower.c\
ft_lstextract_elem_id.c                 ft_putnbr_ui.c                          ft_toupper.c\
ft_lstfind.c                            ft_putstr.c                             get_next_line.c\
ft_lstfind_id.c                         ft_putstr_fd.c\
ft_lstforeach.c                         ft_putstr_null.c\
ft_alloc_2d_int.c			ft_free_2d_int.c\
ft_int_tostring_fd.c ft_2dint_tostring_fd.c ft_2dint_found_pos_value.c ft_putendl2_fd.c\
ft_file_nb_line.c ft_file_read.c ft_nb_word.c ft_str_delete_after_and_sep.c ft_usage.c\
ft_str_egal.c ft_atoi_double.c ft_extract_nb_int.c ft_extract_nb_double.c\
ft_extract_nb_string.c ft_extract_nb_float.c\
file_create.c file_concat_end.c

SRC_M_POINT=ft_pts_destruct.c ft_pts_get_y.c  ft_pts_is_adj.c ft_pts_set_x_y.c ft_pts_to_string.c \
ft_pts_get_x.c ft_pts_init.c ft_pts_set_x.c  ft_pts_set_y.c ft_pts_tostring_fd.c

SRC_M_3D_PTS=\
my_3d_pts_color_destroy.c my_3d_pts_color_init.c    my_3d_pts_destroy.c       my_3d_pts_init.c

SRC_M_ERROR=ft_g_error_destruct.c ft_g_error_get_msg_with_id.c ft_g_error_set_error_with_id.c \
ft_g_error_display_all.c ft_g_error_init.c ft_g_error_set_msg_with_id.c \
ft_g_error_get_error_with_id.c ft_g_error_nb.c ft_g_error_valid_id.c ft_g_error_display_error_only.c ft_g_error_is_error.c

SRC_M_2D_TAB=ft_2d_tab_char_del_tab.c ft_2d_tab_char_del.c ft_2d_tab_char_destruct.c ft_2d_tab_char_init.c \
ft_2d_tab_char_generate_tab.c ft_2d_tab_char_init_tab_with_value.c ft_2d_tab_char_get_dim.c ft_2d_tab_char_set_dim.c \
ft_2d_tab_char_get_value_x_y.c ft_2d_tab_char_to_string.c ft_2d_tab_char_found_number_type_char.c

SRC_M_2D_TAB_INT=\
ft_2d_tab_int_init.c ft_2d_tab_int_destroy.c ft_2d_tab_int_split_line.c ft_2d_tab_int_split_all_line.c\
ft_2d_tab_int_tostring.c

SRC_M_1D_INT=ft_1d_int_del.c ft_1d_int_get_len.c ft_1d_int_init.c ft_1d_int_malloc_tab.c ft_1d_int_set_value_with_id.c\
ft_1d_int_del_tab.c ft_1d_int_destruct.c ft_1d_int_get_tab.c ft_1d_int_init_values.c ft_1d_int_set_len.c ft_1d_int_to_string.c

SRC_M_2D_PTS_MAP=\
ft_2d_pts_map_init.c ft_2d_pts_map_max_pts.c ft_2d_pts_map_min_pts.c

SRC_M_COMPLEX=\
complex_add.c    complex_square.c make_complex.c

SRC_M_RGB=\
rgb_construct.c p_rgb_construct.c rgb_mult.c rgb_add.c

SRC_M_VECTOR=\
make_vector.c         vector_len.c          vector_substraction.c\
vector_add.c          vector_mult.c\
vector_construct.c    vector_norm.c dot_product.c vector_cross_product.c

SRC_M_TIR=\
tir_init.c tir_push_value.c tir_destroy.c tir_dup.c

SRC_M_TIDR=\
tidr_init.c tidr_destroy.c tidr_set_double.c tidr_dup.c

#################################################
### OBJECT
##################################################

OBJ_M_LIBFT=$(patsubst %.c, %.o, $(SRC_M_LIBFT))
OBJ_M_POINT=$(patsubst %.c, %.o, $(SRC_M_POINT))
OBJ_M_3D_PTS=$(patsubst %.c, %.o, $(SRC_M_3D_PTS))
OBJ_M_ERROR=$(patsubst %.c, %.o, $(SRC_M_ERROR))
OBJ_M_2D_TAB=$(patsubst %.c, %.o, $(SRC_M_2D_TAB))
OBJ_M_2D_TAB_INT=$(patsubst %.c, %.o, $(SRC_M_2D_TAB_INT))
OBJ_M_1D_INT=$(patsubst %c, %o, $(SRC_M_1D_INT))
OBJ_M_2D_PTS_MAP=$(patsubst %c, %o, $(SRC_M_2D_PTS_MAP))
OBJ_M_COMPLEX=$(patsubst %c, %o, $(SRC_M_COMPLEX))
OBJ_M_RGB=$(patsubst %c, %o, $(SRC_M_RGB))
OBJ_M_VECTOR=$(patsubst %c, %o, $(SRC_M_VECTOR))
OBJ_M_TIR= $(patsubst %c, %o, $(SRC_M_TIR))
OBJ_M_TIDR= $(patsubst %c, %o, $(SRC_M_TIDR))

#################################################
### FORMAT PATH
##################################################

SRC_M_L=$(addprefix ./$(SRC_M_LIBFT_PATH)/, $(SRC_M_LIBFT))
SRC_M_P=$(addprefix ./$(SRC_M_POINT_PATH)/, $(SRC_M_POINT))
SRC_M_3=$(addprefix ./$(SRC_M_3D_PTS_PATH)/, $(SRC_M_3d_PTS))
SRC_M_E=$(addprefix ./$(SRC_M_ERROR_PATH)/, $(SRC_M_ERROR))
SRC_M_2=$(addprefix ./$(SRC_2D_TAB_PATH)/, $(SRC_M_2D_TAB))
SRC_M_1=$(addprefix ./$(SRC_1D_M_INT_PATH)/, $(SRC_M_1D_INT))
SRC_M_2D=$(addprefix ./$(SRC_2D_TAB_INT_PATH)/, $(SRC_M_2D_TAB_INT))
SRC_M_2D_MAP=$(addprefix ./$(SRC_2D_PTS_MAP_PATH)/, $(SRC_M_2D_PTS_MAP))
SRC_M_C=$(addprefix ./$(SRC_M_COMPLEX_PATH)/, $(SRC_M_COMPLEX))
SRC_M_R=$(addprefix ./$(SRC_M_RGB_PATH)/, $(SRC_M_RGB))
SRC_M_V=$(addprefix ./$(SRC_M_VECTOR_PATH)/, $(SRC_M_VECTOR))
SRC_M_T=$(addprefix ./$(SRC_M_TIR_PATH)/, $(SRC_M_TIR))
SRC_M_TT=$(addprefix ./$(SRC_M_TIDR_PATH)/, $(SRC_M_TIDR))

OBJ_M_L=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_LIBFT))
OBJ_M_P=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_POINT))
OBJ_M_3D=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_3D_PTS))
OBJ_M_E=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_ERROR))
OBJ_M_2D=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_2D_TAB))
OBJ_M_1D=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_1D_INT))
OBJ_M_2D_INT_MTF=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_2D_TAB_INT))
OBJ_M_2D_MAP=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_2D_PTS_MAP))
OBJ_M_C=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_COMPLEX))
OBJ_M_R=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_RGB))
OBJ_M_V=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_VECTOR))
OBJ_M_T=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_TIR))
OBJ_M_TT=$(addprefix ./$(OBJ_PATH)/, $(OBJ_M_TIDR))

OBJS = $(OBJ_M_V) $(OBJ_M_R) $(OBJ_M_C) $(OBJ_M_2D_MAP) $(OBJ_M_L) $(OBJ_M_P) $(OBJ_M_E) $(OBJ_M_2D) $(OBJ_M_1D) $(OBJ_M_L) $(OBJ_M_3D) $(OBJ_M_2D_INT_MTF) $(OBJ_M_T) $(OBJ_M_TT)

#################################################
### RULES
##################################################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_M_V) $(OBJ_M_R) $(OBJ_M_C) $(OBJ_M_2D_MAP) $(OBJ_M_2D_INT_MTF) $(OBJ_M_P) $(OBJ_M_E) $(OBJ_M_2D) $(OBJ_M_1D) $(OBJ_M_L) $(OBJ_M_3D) $(OBJ_M_T) $(OBJ_M_TT) $(INCBITCH)
	@ar rc $(NAME) $(OBJS)
	@echo {COMPIL LIBFT}

$(OBJ_M_T): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_TIR_PATH)%.c
	@echo "$(COL_YELLOW)[ COMPILE & ASSEMBLE STEPS : TAB_INT_DOUBLE]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_TT): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_TIDR_PATH)%.c
	@echo "$(COL_YELLOW)[ COMPILE & ASSEMBLE STEPS : TAB_INT_DOUBLE_RESIZE]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_V): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_VECTOR_PATH)%.c
	@echo "$(COL_YELLOW)[ COMPILE & ASSEMBLE STEPS : VECTOR]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_R): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_RGB_PATH)%.c
	@echo "$(COL_YELLOW)[ COMPILE & ASSEMBLE STEPS : RGB]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_C): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_COMPLEX_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : COMPLEX NUMBERS]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_2D_MAP): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_2D_PTS_MAP_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : MAP]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_2D_INT_MTF): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_2D_TAB_INT_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : LOULOU]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_L): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_LIBFT_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : LIB ORI]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_P): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_POINT_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : OBJ_M_P]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_3D): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_3D_PTS_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : 3D POINTS ]\n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_M_E): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_ERROR_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : OBJ_M_E ]\n"
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

$(OBJ_M_2D): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_2D_TAB_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : TAB 2D CHAR]\n"
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

$(OBJ_M_1D): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_1D_INT_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : TAB 1D INT]\n"
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

clean:
	@echo "$(COL_YELLOW)[ CLEAN DIRECTORY LIB]\n"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(COL_YELLOW)[ CLEAN DIRECTORY AND $(NAME) ]\n"
	@rm -f $(NAME)

re: fclean all
