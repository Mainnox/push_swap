/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_movebot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:29:11 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:02:55 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "push_swap.h"

int				find_max(t_intlst *s)
{
	size_t		i;
	int			max;
	t_intlst	*node;

	i = 0;
	node = s;
	max = s->n;
	while (node)
	{
		if (node->n > max)
			max = node->n;
		node = node->next;
	}
	return (max);
}

int				find_min(t_intlst *s, t_flag flag, int floor)
{
	size_t		i;
	int			min;
	t_intlst	*node;

	i = 0;
	node = s;
	min = s->n;
	if (flag != AT_START && min == floor && s->next)
		min = s->next->n;
	while (node)
	{
		if (node->n < min)
		{
			if (flag == AT_START || (flag != AT_START && node->n > floor))
				min = node->n;
		}
		node = node->next;
	}
	return (min);
}

void			movebot(t_data *data, t_stack *stack)
{
	if (stack->id == 'B')
		cmd_add(data, "pa");
	cmd_add(data, "ra");
	data->a.end->next = data->b.start;
	data->min = find_min(data->a.start, NOT_AT_START, data->min);
	data->a.end->next = NULL;
}
