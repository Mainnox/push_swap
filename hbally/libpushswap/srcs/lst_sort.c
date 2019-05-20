/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:10:14 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:10:34 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

static void			move_elem(t_intlst **dest, t_intlst **source)
{
	(*dest)->next = *source;
	(*source)->prev = *dest;
	*source = (*source)->next;
	*dest = (*dest)->next;
}

static t_intlst		*merge(t_intlst *left, t_intlst *right, int reverse)
{
	t_intlst		dummy;
	t_intlst		*tail;

	tail = &dummy;
	dummy.next = NULL;
	while (1)
	{
		if (!left || !right)
		{
			tail->next = !right ? left : right;
			break ;
		}
		if ((!reverse && left->n < right->n)
				|| (reverse && left->n > right->n))
			move_elem(&tail, &left);
		else
			move_elem(&tail, &right);
	}
	if (dummy.next)
		dummy.next->prev = NULL;
	if (tail->next)
		tail->next->prev = tail;
	return (dummy.next);
}

t_intlst			*lst_sort(t_intlst *start, int reverse)
{
	t_intlst		*right;
	t_intlst		*middle;

	if (start == NULL || start->next == NULL)
		return (start);
	middle = lst_mid(start);
	right = middle->next;
	middle->next = NULL;
	return (merge(lst_sort(start, reverse), lst_sort(right, reverse), reverse));
}
