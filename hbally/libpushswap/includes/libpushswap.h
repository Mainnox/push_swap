/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:09:07 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:06:54 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include "ps_types.h"

# define NO_ERROR 0
# define MALLOC_ERROR 1
# define GETARG_NOARGS 2
# define GETARG_BADFORMAT 3
# define GETARG_DUP 4
# define CMDINDEX_CONFLICT 5

# define EDIT_A 1
# define EDIT_B 2

void					clean_exit(t_err error, t_data *data);
void					free_arglist(t_arglist *args);
void					free_stack(t_stack *s);

t_intlst				*lst_add(t_data *data, t_stack *stack, int n);
t_intlst				*lst_mid(t_intlst *start);
t_intlst				*lst_sort(t_intlst *start, int reverse);
size_t					lst_len(t_intlst *start);
t_intlst				*lst_find(int n, t_intlst *start);
void					lst_pop_int(t_stack *stack, int n);
void					lst_pop_end(t_stack *stack);

t_cmdlst				*cmdlst_add(t_data *data, t_cmds *cmds, char *cmd);

void					get_options(t_data *data, int argc, char **argv,
										char *msg);
void					stack_get(t_data *data, t_arglist *arg);
void					stack_dup(t_data *data, t_stack *stack, size_t len);

uint8_t					is_sorted(t_stack *stack, size_t len);
uint8_t					is_revsorted(t_stack *stack, size_t len);
uint8_t					check_stacks(t_stack *a, t_stack *b);

void					cmd_loadindex(t_data *data);
void					cmd_apply(t_data *data, char *cmd);
void					cmd_reverse(t_data *data, char *cmd);

void					push(t_stack *a, t_stack *b, t_flag flag);
void					swap(t_stack *a, t_stack *b, t_flag flag);
void					rotate(t_stack *a, t_stack *b, t_flag flag);
void					revrotate(t_stack *a, t_stack *b, t_flag flag);

#endif
