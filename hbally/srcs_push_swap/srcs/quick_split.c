/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:33:06 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:02:47 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "push_swap.h"

static int		get_median(t_data *data, t_stack *s, size_t len)
{
	int			median;

	stack_dup(data, s, len);
	data->c.start = lst_sort(data->c.start, s->id == 'A' ? SORT_INC : SORT_DEC);
	median = lst_mid(data->c.start)->n;
	free_stack(&(data->c));
	return (median);
}

void			quicksplit(t_data *data, t_stack *s, size_t len, t_split *split)
{
	int			median;
	size_t		i;

	i = 0;
	median = get_median(data, s, len);
	while (i < len)
	{
		if (s->id == 'B' && s->start->n == data->min)
		{
			movebot(data, s);
			split->stashed++;
		}
		else if ((s->id == 'A' && s->start->n > median)
				|| (s->id == 'B' && s->start->n < median))
		{
			cmd_add(data, s->id == 'A' ? "ra" : "rb");
			split->remaining++;
		}
		else
		{
			cmd_add(data, s->id == 'A' ? "pb" : "pa");
			split->moved++;
		}
		i++;
	}
}
