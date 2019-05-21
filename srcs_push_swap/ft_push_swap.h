/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:56:07 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 19:39:05 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct		s_push
{
	int				*a;
	int				*b;
	int				size;
	int				sizea;
	int				sizeb;
	char			**argv;
	int				nb_ope;
	char			*hack;
	char			**gnl;
	int				ign;
	int				low;
	long			mid;
	int				nbr_ok;
	int				tour;
	int				*progres;
	int				size_progres;
}					t_push;

void				ft_swap_a(t_push *handle);
void				ft_rotate_a(t_push *handle);
void				ft_reverse_rotate_a(t_push *handle);
void				ft_push_a(t_push *handle);
void				ft_swap_b(t_push *handle);
void				ft_rotate_b(t_push *handle);
void				ft_reverse_rotate_b(t_push *handle);
void				ft_push_b(t_push *handle);
void				ft_print_error(void);
int					ft_atoi_push_swap(char *str);
void				ft_print_tab(int *tab, size_t size, char *name);
void				ft_sort_push_swap(t_push *handle, int algo_pass);
int					ft_realloc_push_swap(t_push *handle, char *ope, size_t k);
void				ft_quick_sort_1(t_push *handle);
void				ft_algo_insert_a(t_push *handle);
void				ft_wich_path(t_push *handle, int where,
				char pole);
int					ft_find_this(int *tab, int size, int this);
void				ft_algo_insert_b(t_push *handle);
int					ft_find_n_bigger(int *tab, int size, int beforethis);
long				ft_find_bigger(int *tab, int size);
void				ft_sort_under_5(t_push *handle);

int					ft_is_nsort(int *tab, int size);

long				ft_find_mid(int *tab, int size, int nbr_ok);
int					ft_find_low(t_push *handle);
void				ft_put_b_on_a(t_push *handle, int how_many);
int					ft_how_many_less(int *tab, int size, long nbr);
int					ft_replace_head(int *tab, int size, int ign);

void				ft_fill_argv(t_push *handle);
int					ft_is_sort(int *tab, int size);

int					*ft_init_progress(void);
int					ft_realloc_progress(t_push *handle, char wich);
void				ft_add_progress(t_push *handle, int new);

void				ft_free_sol(char **sol, char nb_algo);
char				*ft_print_best_sol(char **sol, char nb_algo);
void				ft_add_sol(char **sol, char *hack, char algo_pass);
char				**ft_init_sol(char nb_algo);

void				ft_wich_path2(t_push *handle, int nb, char pole);
void				ft_while_f(t_push *handle, int n,
		void (*f)(t_push *handle), void (*ft)(t_push*handle));
void				ft_finish_him(t_push *handle);

void				ft_sort_under_5_a(t_push *handle);

#endif
