/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:56:07 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 17:34:32 by akremer          ###   ########.fr       */
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
	char 			**argv;
}					t_push;

void		ft_swap(int *a);
void		ft_rotate(int *a, int taille);
void		ft_reverse_rotate(int *a, int taille);
void		ft_push(int *a, int *b, int taille);
void		ft_print_error(void);
void		ft_fill_argv(t_push *handle);
int			ft_atoi_push_swap(char *str);
int			ft_is_sort(t_push *handle);

#endif
