/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:56:07 by akremer           #+#    #+#             */
/*   Updated: 2019/03/20 13:13:34 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

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
}					t_push;

void		ft_swap_a(t_push *handle);
void		ft_rotate_a(t_push *handle);
void		ft_reverse_rotate_a(t_push *handle);
void		ft_push_a(t_push *handle);
void		ft_swap_b(t_push *handle);
void		ft_rotate_b(t_push *handle);
void		ft_reverse_rotate_b(t_push *handle);
void		ft_push_b(t_push *handle);
void		ft_print_error(void);
void		ft_fill_argv(t_push *handle);
int			ft_atoi_push_swap(char *str);
int			ft_is_sort(t_push *handle);
void		ft_print_tab(int *tab, size_t size, char *name);
void		ft_sort_push_swap(t_push *handle);
int			ft_realloc_push_swap(t_push *handle, char *ope, size_t k);

#endif
