/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizlst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:12:07 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 09:59:48 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpsviz.h"

static void			move_elem(t_vizlst **dest, t_vizlst **source)
{
	(*dest)->next = *source;
	*source = (*source)->next;
	*dest = (*dest)->next;
}

static t_vizlst		*merge(t_vizlst *left, t_vizlst *right)
{
	t_vizlst		dummy;
	t_vizlst		*tail;

	tail = &dummy;
	dummy.next = NULL;
	while (1)
	{
		if (!left)
		{
			tail->next = right;
			break ;
		}
		if (!right)
		{
			tail->next = left;
			break ;
		}
		if (left->n < right->n)
			move_elem(&tail, &left);
		else
			move_elem(&tail, &right);
	}
	return (dummy.next);
}

t_vizlst			*mid(t_vizlst *start)
{
	t_vizlst	*slow;
	t_vizlst	*fast;

	if (!start)
		return (NULL);
	slow = start;
	fast = start;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}

t_vizlst			*sort(t_vizlst *start)
{
	t_vizlst		*right;
	t_vizlst		*middle;

	if (start == NULL || start->next == NULL)
		return (start);
	middle = mid(start);
	right = middle->next;
	middle->next = NULL;
	return (merge(sort(start), sort(right)));
}
