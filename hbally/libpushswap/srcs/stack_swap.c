/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:45:56 by hbally            #+#    #+#             */
/*   Updated: 2019/02/25 16:05:51 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static void		swap_action(t_stack *stk)
{
	t_intlst	*elem;
	t_intlst	*start;

	start = stk->start;
	if (stk->start && stk->start->next)
	{
		elem = start->next->next;
		start->next->next = start;
		start->next->prev = NULL;
		start = start->next;
		start->next->next = elem;
		start->next->prev = start;
		if (start->next->next)
			start->next->next->prev = start->next;
		else
			stk->end = start->next;
	}
	stk->start = start;
}

void			swap(t_stack *a, t_stack *b, t_flag flag)
{
	if (flag & EDIT_A)
		swap_action(a);
	if (flag & EDIT_B)
		swap_action(b);
}
