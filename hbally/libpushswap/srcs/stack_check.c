/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:59:42 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:11:19 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

uint8_t				is_revsorted(t_stack *stack, size_t len)
{
	t_intlst		*elem;
	size_t			i;

	i = 0;
	elem = stack->start;
	while (elem && i < len)
	{
		if (elem->next == NULL)
			return (1);
		if (elem->next->n > elem->n)
			return (0);
		elem = elem->next;
		i++;
	}
	return (1);
}

uint8_t				is_sorted(t_stack *stack, size_t len)
{
	t_intlst		*elem;
	size_t			i;

	i = 0;
	elem = stack->start;
	while (elem && i < len)
	{
		if (elem->next == NULL)
			return (1);
		if (elem->next->n < elem->n)
			return (0);
		elem = elem->next;
		i++;
	}
	return (1);
}

uint8_t				check_stacks(t_stack *a, t_stack *b)
{
	if (b->start != NULL)
		return (0);
	if (a->start == NULL)
		return (0);
	return (is_sorted(a, a->len));
}
