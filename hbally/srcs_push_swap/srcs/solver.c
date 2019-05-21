/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:28:49 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:01:26 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "push_swap.h"

t_flag			solver(t_data *data, t_stack *a, t_stack *b)
{
	if (is_sorted(a, a->len))
		return (0);
	if (a->len <= 5)
		smolsort(data, a, b);
	else
	{
		a->id = 'A';
		b->id = 'B';
		a->opp = b;
		b->opp = a;
		data->endlen = a->len;
		data->min = find_min(data->a.start, AT_START, 0);
		load_b(data, a, b, a->len);
	}
	return (0);
}
