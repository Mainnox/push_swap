/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:56:07 by akremer           #+#    #+#             */
/*   Updated: 2019/05/17 14:34:40 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

# define NBR_OK 12

typedef struct		s_know
{
	int				how_many;
	struct s_know	*next;
}					t_know;

typedef struct		s_push
{
	int				*a;
	int				*b;
	int				size;
	int				sizea;
	int				sizeb;
	char 			**argv;
	int				nb_ope;
	char			*hack;
	char			**gnl;
	int				ign;
	int				low;
	int				progress;
	int				mid;
	int				nbr_ok;
	int				tour;
	int				*progres;
	int				size_progres;
}					t_push;

typedef struct		s_sol
{
	int				index;
	int				nb_ope;
	char			*sol;
	struct s_sol	*next;
}					t_sol;

void		ft_swap_a(t_push *handle);
void		ft_rotate_a(t_push *handle);
void		ft_reverse_rotate_a(t_push *handle);
void		ft_push_a(t_push *handle);
void		ft_swap_b(t_push *handle);
void		ft_rotate_b(t_push *handle);
void		ft_reverse_rotate_b(t_push *handle);
void		ft_fill_sol(t_push *handle, t_sol **sol);
char		*ft_print_the_best(t_sol **sol);
void		ft_push_b(t_push *handle);
int			ft_find_mid(int *tab, int size, int nbr_ok);
void		ft_print_error(void);
void		ft_fill_argv(t_push *handle);
int			ft_atoi_push_swap(char *str);
int			ft_is_sort(int *tab, int size);
void		ft_print_tab(int *tab, size_t size, char *name);
void		ft_sort_push_swap(t_push *handle, int algo_pass);
int			ft_realloc_push_swap(t_push *handle, char *ope, size_t k);
void		ft_check_reduc(t_push *handle);
void		ft_quick_sort_1(t_push *handle);
void		ft_algo_insert_a(t_push *handle);
void		ft_wich_path(t_push *handle, int where, void (*f)(t_push *handle), void (*ft)(t_push *handle), char pole);
int			ft_find_this(int *tab, int size, int this);
void		ft_algo_insert_b(t_push *handle);
int			ft_find_n_bigger(int *tab, int size, int beforethis);
int			ft_find_bigger(int *tab, int size);
int			ft_find_low(t_push *handle);
void		ft_put_b_on_a(t_push *handle, int how_many);
void		ft_sort_under_5(t_push *handle);
int			ft_how_many_less(int *tab, int size, int nbr);

/*\
 *			Progress's functions
\*/

int			*ft_init_progress(void);
int			ft_realloc_progress(t_push *handle, char wich);
void		ft_add_progress(t_push *handle, int new);

/*\
 *			Know's functions
\*/

//void		ft_free_last(t_know **know);
//int			ft_add_know(t_know **know, int how_many);
//t_know		**ft_init_know(void);
//t_know		*ft_go_to_last_know(t_know **know);
//void		ft_swap_know(t_push *handle, t_know **know);

#endif
