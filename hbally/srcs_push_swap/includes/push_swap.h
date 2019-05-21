/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:28:04 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:30:04 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ps_types.h"

# define SORT_INC 0
# define SORT_DEC 1

# define AT_START 1
# define NOT_AT_START 0

# define MIN_LEN 20

# define ROTATE 0x2
# define RROTATE 0x1

# define TRIVIAL 0x3
# define TO_MIN 0x8
# define TO_MAX 0x4
# define R_MIN 0xA
# define R_MAX 0x6
# define RR_MIN 0x9
# define RR_MAX 0x5

typedef struct	s_split
{
	size_t		moved;
	size_t		remaining;
	size_t		stashed;
}				t_split;

t_flag			solver(t_data *data, t_stack *a, t_stack *b);
void			load_b(t_data *data, t_stack *a, t_stack *b, size_t len);
void			unload_b(t_data *data, t_stack *a, t_stack *b, size_t len);
void			quicksplit(t_data *data, t_stack *s, size_t len,
								t_split *split);
int				find_min(t_intlst *s, t_flag flag, int floor);
int				find_max(t_intlst *s);
void			movebot(t_data *data, t_stack *stack);
void			stack_rewind(t_data *data, t_stack *b, size_t len);
void			deplete_b(t_data *data, t_stack *a, t_stack *b, int len);
t_flag			find_shortest(t_stack *s, int min, int max);

int				smolsort(t_data *data, t_stack *a, t_stack *b);
int				sort_three(t_data *data, t_stack *a, t_stack *b);

void			cmd_add(t_data *data, char *cmd_str);
void			cmd_print(t_cmds *cmds);

#endif
