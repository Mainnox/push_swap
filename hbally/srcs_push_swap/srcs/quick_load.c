/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:00:45 by hbally            #+#    #+#             */
/*   Updated: 2019/02/07 20:34:57 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "push_swap.h"
#include "libft.h"

void			load_b(t_data *data, t_stack *a, t_stack *b, size_t len)
{
	t_split		split;

	if (len > MIN_LEN)
	{
		ft_bzero(&split, sizeof(t_split));
		quicksplit(data, a, len, &split);
		if (len != data->endlen)
			stack_rewind(data, b, split.remaining);
	}
	else
	{
		while (len > 0)
		{
			a->start->n != data->min ? cmd_add(data, "pb") : movebot(data, a);
			len--;
		}
	}
	unload_b(data, a, b, b->len);
	if (len != 0)
		load_b(data, a, b, split.remaining);
}

void			unload_b(t_data *data, t_stack *a, t_stack *b, size_t len)
{
	t_split		split;

	if (len > MIN_LEN)
	{
		ft_bzero(&split, sizeof(t_split));
		quicksplit(data, b, len, &split);
		unload_b(data, a, b, split.remaining);
		load_b(data, a, b, split.moved);
	}
	else
		deplete_b(data, a, b, len);
}
