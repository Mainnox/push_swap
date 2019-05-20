/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push_swap_plus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:03:47 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 18:07:51 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void				ft_wich_path2(t_push *handle, int nb, char pole)
{
	int where;

	where = ft_find_this(handle->b, handle->sizeb, nb);
	if (where > handle->sizeb / 2)
	{
		while (ft_find_this(handle->b, handle->sizeb, nb) != pole)
			ft_reverse_rotate_b(handle);
	}
	else
	{
		while (ft_find_this(handle->b, handle->sizeb, nb) != pole)
			ft_rotate_b(handle);
	}
}

void				ft_while_f(t_push *handle, int n,
		void (*f)(t_push *handle), void (*ft)(t_push *handle))
{
	while (n != 0)
	{
		f(handle);
		n--;
	}
	ft(handle);
}

void				ft_finish_him(t_push *handle)
{
	int max;
	int next;
	int soothsayer;

	soothsayer = 1;
	max = ft_find_bigger(handle->b, handle->sizeb);
	next = max;
	while (handle->sizeb > 0)
	{
		if (soothsayer != 1)
			next = ft_find_n_bigger(handle->b, handle->sizeb, next);
		else
			soothsayer--;
		ft_wich_path2(handle, next, 0);
		ft_push_b(handle);
	}
}
