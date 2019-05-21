/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:01:56 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:04:47 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static void		revrotate_action(t_stack *stk, t_flag flag)
{
	t_intlst	*elem;

	if (stk->start && stk->start->next)
	{
		elem = stk->end->prev;
		stk->end->next = stk->start;
		stk->end->prev->next = NULL;
		stk->end->prev = NULL;
		stk->start->prev = stk->end;
		stk->start = stk->end;
		stk->end = elem;
	}
	else
		swap(stk, stk, flag);
}

void			revrotate(t_stack *a, t_stack *b, t_flag flag)
{
	if (flag & EDIT_A)
		revrotate_action(a, EDIT_A);
	if (flag & EDIT_B)
		revrotate_action(b, EDIT_B);
}

static void		rotate_action(t_stack *stk, t_flag flag)
{
	t_intlst	*elem;

	if (stk->start && stk->start->next)
	{
		elem = stk->start->next;
		stk->end->next = stk->start;
		stk->start->next->prev = NULL;
		stk->start->next = NULL;
		stk->start->prev = stk->end;
		stk->end = stk->start;
		stk->start = elem;
	}
	else
		swap(stk, stk, flag);
}

void			rotate(t_stack *a, t_stack *b, t_flag flag)
{
	if (flag & EDIT_A)
		rotate_action(a, EDIT_A);
	if (flag & EDIT_B)
		rotate_action(b, EDIT_B);
}
