/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:29:20 by akremer           #+#    #+#             */
/*   Updated: 2019/03/25 11:11:00 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

# define JOULI ___________________________________________________

typedef struct		s_check
{
	int				*a;
	int				*b;
	int				size;
	int				sizea;
	int				sizeb;
	char 			**argv;
	int				nb_ope;
	char			**gnl;
	char			*option;
}					t_check;

void		ft_swap_a_checker(t_check *handle);
void		ft_rotate_a_checker(t_check *handle);
void		ft_reverse_rotate_a_checker(t_check *handle);
void		ft_push_a_checker(t_check *handle);
void		ft_swap_b_checker(t_check *handle);
void		ft_rotate_b_checker(t_check *handle);
void		ft_reverse_rotate_b_checker(t_check *handle);
void		ft_push_b_checker(t_check *handle);
void		ft_print_error_checker(void);
void		ft_fill_argv_checker(t_check *handle);
int			ft_atoi_checker(char *str);
int			ft_is_sort_checker(t_check *handle);
void		ft_print_tab_checker(int *tab, size_t size, char *name);
void		ft_do_op_checker(t_check *handle);

#endif
