/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:08:56 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:09:21 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

size_t				lst_len(t_intlst *start)
{
	t_intlst		*node;
	size_t			len;

	len = 0;
	node = start;
	while (node)
	{
		node = node->next;
		len++;
	}
	return (len);
}

t_intlst			*lst_mid(t_intlst *start)
{
	t_intlst		*slow;
	t_intlst		*fast;

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

t_intlst			*lst_find(int n, t_intlst *start)
{
	t_intlst		*node;

	node = start;
	while (node)
	{
		if (node->n == n)
			return (node);
		node = node->next;
	}
	return (NULL);
}
