/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smolsort_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:58:31 by hbally            #+#    #+#             */
/*   Updated: 2019/02/07 20:32:02 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "push_swap.h"

int			get_pos(int n, t_stack *a)
{
	if (n == find_min(a->start, AT_START, 0))
		return (1);
	if (n == find_max(a->start))
		return (3);
	else
		return (2);
}

void		reorder(t_data *data, int pos[])
{
	if (pos[0] == 3 && pos[1] == 1)
		cmd_add(data, "ra");
	if (pos[0] == 2 && pos[1] == 3)
		cmd_add(data, "rra");
}

int			sort_three(t_data *data, t_stack *a, t_stack *b)
{
	int		pos[3];
	int		swap;

	if (is_sorted(a, a->len))
		return (0);
	pos[0] = get_pos(a->start->n, a);
	pos[1] = get_pos(a->start->next->n, a);
	pos[2] = get_pos(a->end->n, a);
	if (!((pos[0] == 2 && pos[1] == 3) || (pos[0] == 3 && pos[1] == 1)))
	{
		if (b->start && b->start->n < b->start->next->n)
			cmd_add(data, "ss");
		else
			cmd_add(data, "sa");
		swap = pos[0];
		pos[0] = pos[1];
		pos[1] = swap;
	}
	reorder(data, pos);
	return (0);
}
