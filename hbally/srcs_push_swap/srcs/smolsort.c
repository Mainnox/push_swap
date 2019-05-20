/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smolsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:21:09 by hbally            #+#    #+#             */
/*   Updated: 2019/02/07 20:43:08 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "push_swap.h"

int				sort_two(t_data *data, t_stack *a, t_stack *b)
{
	if (a->start->n > a->start->next->n)
	{
		if (b->start && b->start->n < b->start->next->n)
			cmd_add(data, "ss");
		else
			cmd_add(data, "sa");
	}
	return (0);
}

void			select_value(t_data *data, t_flag path, t_stack *a, int value)
{
	if (!((path & 0x3) == TRIVIAL))
		while (a->start->n != value)
			cmd_add(data, path & ROTATE ? "ra" : "rra");
	cmd_add(data, "pb");
}

void			smoldeplete(t_data *data, int v1, int v2, t_stack *a)
{
	t_flag		path;

	path = find_shortest(a, v1, v2);
	if (path & TO_MIN)
	{
		select_value(data, path, a, v1);
		path = find_shortest(a, v2, v2);
		select_value(data, path, a, v2);
	}
	else
	{
		select_value(data, path, a, v2);
		path = find_shortest(a, v1, v1);
		select_value(data, path, a, v1);
	}
}

int				smolsort(t_data *data, t_stack *a, t_stack *b)
{
	int			v1;
	int			v2;

	if (a->len == 2)
		return (sort_two(data, a, b));
	if (a->len == 3)
		return (sort_three(data, a, b));
	v1 = find_min(a->start, AT_START, 0);
	v2 = find_min(a->start, NOT_AT_START, v1);
	smoldeplete(data, v1, v2, a);
	a->len == 2 ? sort_two(data, a, b) : sort_three(data, a, b);
	if (b->start->n < b->start->next->n)
		cmd_add(data, "sb");
	cmd_add(data, "pa");
	cmd_add(data, "pa");
	return (0);
}
