/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:18:51 by hbally            #+#    #+#             */
/*   Updated: 2019/02/01 14:49:06 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static uint8_t		push_action(t_stack *stk1, t_stack *stk2)
{
	t_intlst		*elem;

	if (stk2->start != NULL)
	{
		elem = stk2->start->next;
		stk2->start->next = stk1->start;
		stk2->start->prev = NULL;
		if (stk1->start)
			stk1->start->prev = stk2->start;
		else
			stk1->end = stk2->start;
		stk1->start = stk2->start;
		stk2->start = elem;
		if (stk2->start)
			stk2->start->prev = NULL;
		else
			stk2->end = NULL;
		return (1);
	}
	return (0);
}

void				push(t_stack *a, t_stack *b, t_flag flag)
{
	if (flag & EDIT_A)
		if (push_action(a, b))
		{
			a->len++;
			b->len--;
		}
	if (flag & EDIT_B)
		if (push_action(b, a))
		{
			a->len--;
			b->len++;
		}
}
