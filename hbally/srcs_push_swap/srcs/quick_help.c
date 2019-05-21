/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:28:15 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:28:09 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			stack_rewind(t_data *data, t_stack *b, size_t len)
{
	int			max;

	max = find_max(b->start);
	while (len > 0)
	{
		if (b->start->n != max)
			cmd_add(data, "rrr");
		else
			cmd_add(data, "rra");
		len--;
	}
}
