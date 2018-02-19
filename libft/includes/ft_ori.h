/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ori.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 05:03:18 by jegloff           #+#    #+#             */
/*   Updated: 2017/06/15 22:52:01 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ORI_H
# define FT_ORI_H

/*
**	typedef	unsigned long size_t;
*/
# include <string.h>

# define BUFF_SIZE 32

# include "ft_point.h"

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_file
{
	int					fd;
	char				buff[BUFF_SIZE + 1];
	char				*chaine;
}						t_file;

int						*ft_extract_nb_int(char *data, int nb, int *error);

double					*ft_extract_nb_double(char *data, int nb, int *error);

float					*ft_extract_nb_float(char *data, int nb, int *error);

char					**ft_extract_nb_string(char *data, int nb, int *error);

double					ft_atoi_double(const char *str);

double					deg_to_rad(int deg);

int						check_extand(char *str, char *ext);

double					pow2(double nb);

void					ft_usage(char *str);

void					ft_str_delete_after_and_sep(char *str, char sep);

int						ft_str_egal(char *str1, char *str2);

int						ft_is_base16(char *str);

int						ft_is_base10(char *str);

char					***get_next_line_all(char *name_file);

int						ft_nb_word(char *str);

void					ft_file_read(char *name_file);

unsigned int			ft_file_nb_line(char *name_file);

void					ft_putendl2_fd(char *s1, char *s2, int fd);

void					ft_int_tostring_fd(int *tab_int, int len, int fd);

void					ft_2dint_tostring_fd(int **tab_int, int y,\
		int x, int fd);

t_point					*ft_2dint_found_pos_value(int **tab, int y,\
		int x, int to_found);

int						**ft_alloc_2d_int(int y, int x);

void					ft_free_2d_int(int ***tab, int y);

unsigned int			ft_int_found_nb_value(int *tab, int len, int value);

unsigned int			ft_int_found_value_index\
								(int *tab, int size, int value);

void					ft_strarg_free(char ***str, int size);

char					**ft_advanced_split(int argc, char **argv, int *argc2);

int						ft_abs(int a);

int						ft_int_pos_value(int *tab, int len, int value);

int						ft_int_max(int *tab, int len);

int						ft_int_min(int *tab, int len);

int						ft_int_isordon(int *tab, int len);

/*
** 0: no sort | 1: decrois | 2: croiss
*/
int						ft_int_issort(int *tab, int len);

int						ft_int_found_median(int *tab_int, int len);

void					ft_int_mysort(int *tab_int, int len);

void					ft_int_mysort_r(int *tab_int, int len);

void					ft_int_tostring(int *tab_int, int len);

void					ft_int_tostring_fd(int *tab_int, int len, int fd);

void					ft_int_swap_pos(int *tab, int pos1, int pos2);

int						ft_min(int a, int b);

int						ft_max(int a, int b);

int						*ft_intdup(int *tab_1d, int len);

long long int			ft_atoi_long_long_int(const char *str);

char					*ft_str_extract_substring\
							(char *str, int begin, int end);

char					ft_char_is_present_in_str(char *str, char c);

char					*ft_itoa_base(int n, int base);

char					*ft_itoa_base_ui(unsigned int n, int base);

char					*ft_itoa_base_li_uli(long int n, int base);

int						get_next_line(const int fd, char **line);

char					*ft_str_return_extract_line_behind_sep\
						(char *str, char c);

void					ft_str_cut_includ_behind_sep(char *str, char c);

int						ft_str_resize_concat(char **str, char *cp);

int						ft_sqrt(int nb);

char					**ft_strsplit(char const *s, char c);

void					*ft_memset(void *b, int c, size_t len);

void					*ft_memcpy(void *dst, const void *src, size_t n);

void					*ft_memccpy
						(void *dst, const void *src, int c, size_t n);

void					*ft_memchr(const void *s, int c, size_t n);

void					*ft_memmove(void *dst, const void *src, size_t n);

int						ft_memcmp(const void *s1, const void *s2, size_t n);

void					ft_bzero(void *s, size_t n);

void					ft_putchar(char c);

void					ft_putchar_uc(unsigned char c);

void					ft_putchar_all_ascii(unsigned char c);

void					ft_putchar_utf8(int c);

void					ft_putstr(char const *s);

void					ft_putstr_utf8(int const *tab);

void					ft_putstr_null(char const *s);

void					ft_putnbr(int nb);

void					ft_putnbr_ui(unsigned int nb);

void					ft_putnbr_li(long int nb);

void					ft_putnbr_li_u(unsigned long int nb);

void					ft_putnbr_l(long nb);

void					ft_putnbr_ll(long long nb);

int						ft_atoi(const char *str);

void					ft_swap(int *a, int *b);

size_t					ft_strlen(const char *s);

char					*ft_strdup(const char *s1);

char					*ft_strcpy(char *dst, const char *src);

char					*ft_strncpy(char *dest, const char *src, size_t n);

char					*ft_strncat(char *s1, const char *s2, size_t n);

char					*ft_strcat(char *s1, const char *s2);

size_t					ft_strlcat(char *dst, const char *src, size_t size);

char					*ft_strchr(const char *s, int c);

char					*ft_strrchr(const char *s, int c);

char					*ft_strstr(const char *big, const char *little);

char					*ft_strnstr(const char *big, const char *little,\
						size_t len);

int						ft_strcmp(const char *s1, const char *s2);

int						ft_strncmp(const char *s1, const char *s2, size_t n);

int						ft_isalpha(int c);

int						ft_isdigit(int c);

int						ft_isalnum(int c);

int						ft_isascii(int c);

int						ft_isprint(int c);

int						ft_toupper(int c);

int						ft_tolower(int c);

void					ft_memdel(void **ap);

void					*ft_memalloc(size_t size);

char					*ft_strnew(size_t size);

void					ft_strdel(char **as);

void					ft_strclr(char *s);

void					ft_striter(char *s, void (*f)(char *));

void					ft_striteri(char *s, void (*f)(unsigned int, char *));

void					ft_putchar_fd(char c, int fd);

void					ft_putstr_fd(char const *s, int fd);

void					ft_putendl(char const *s);

void					ft_putendl_fd(char const *s, int fd);

void					ft_putnbr_fd(int n, int fd);

char					*ft_strmap(char const *s, char (*f)(char));

char					*ft_strmapi
						(char const *s, char (*f)(unsigned int, char));

char					*ft_itoa(int n);

int						ft_strequ(char const *s1, char const *s2);

int						ft_strnequ(char const *s1, char const *s2, size_t n);

char					*ft_strsub
						(char const *s, unsigned int start, size_t len);

char					*ft_strjoin(char const *s1, char const *s2);

char					*ft_strtrim(char const *s);

/*
****************
** linked list **
****************
*/

t_list					*ft_lstcreate_elem(void *data);

void					ft_lstpush_back(t_list **begin_list, void *data);

void					ft_lstpush_back_id\
						(t_list **begin_list, void *data, int id);

void					ft_lstpush_front(t_list **begin_list, void *data);

int						ft_lstsize(t_list *begin_list);

t_list					*ft_lstlast(t_list *begin_list);

t_list					*ft_lstlast_last(t_list *begin_list);

t_list					*ft_lstpush_params(int ac, char **av);

void					ft_lstclear(t_list **begin_list);

t_list					*ft_lstfind(t_list *begin_list, void *data_ref,
						int (*cmp)());

t_list					*ft_lstfind_id(t_list *begin_list, size_t id);

void					ft_lstforeach(t_list *begin_list, void (*f)(void *));

void					ft_lstforeach_if(t_list *begin_list, void (*f)(void *)
						, void *data_ref, int (*cmp)());

t_list					*ft_lstextract_elem_id(t_list *begin_list, int id);

void					ft_lstreverse(t_list **begin_list);

t_list					*ft_lstnew(void const *content, size_t content_size);

void					ft_lstdelone
						(t_list **alst, void (*del)(void *, size_t));

void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void					ft_lstadd(t_list **alst, t_list *new);

void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
******************
** GESTION FILE **
******************
*/

int						ft_number_of_line(char *str);

int						ft_file_exist(char *name);

int						ft_file_size(char *name);

int						file_create(char *name);

int						file_concat_end(char *name, unsigned char *str);

int						file_concat_size_end(char *name,\
		unsigned char *str, int size);

char					*ft_file_return_data(char *name);
#endif
