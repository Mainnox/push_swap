/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_deplete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:24:41 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:02:30 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "push_swap.h"

t_flag			find_shortest(t_stack *s, int min, int max)
{
	t_intlst	*node_down;
	t_intlst	*node_up;

	node_down = s->start;
	node_up = s->end;
	if (node_down->n == min || node_down->n == max)
		return (node_down->n == min ? TRIVIAL | TO_MIN : TRIVIAL | TO_MAX);
	node_down = node_down->next;
	while (1)
	{
		if (node_down->n == min || node_down->n == max)
			return (node_down->n == min ? R_MIN : R_MAX);
		if (node_up->n == min || node_up->n == max)
			return (node_up->n == min ? RR_MIN : RR_MAX);
		node_down = node_down->next;
		node_up = node_up->prev;
	}
}

void			deplete_b(t_data *data, t_stack *a, t_stack *b, int len)
{
	int			min;
	int			max;
	t_flag		path;

	while (b->start)
	{
		min = find_min(b->start, AT_START, 0);
		max = find_max(b->start);
		path = find_shortest(b, min, max);
		if (!((path & 0x3) == TRIVIAL))
			while (b->start->n != (path & TO_MIN ? min : max))
				cmd_add(data, path & ROTATE ? "rb" : "rrb");
		if (path & TO_MIN)
		{
			movebot(data, b);
			len--;
		}
		else
			cmd_add(data, "pa");
	}
	while (len > 0)
	{
		movebot(data, a);
		len--;
	}
}
