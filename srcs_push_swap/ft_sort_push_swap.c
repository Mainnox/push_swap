/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 06:56:54 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 19:04:22 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int				ft_worst_numbers(t_push *handle)
{
	int		check;
	int		act;
	int		max;

	max = ft_find_bigger(handle->a, handle->sizea);
	check = 0;
	if (ft_find_this(handle->a, handle->sizea, max) == 2)
		check++;
	act = ft_find_n_bigger(handle->a, handle->sizea, max);
	if (ft_find_this(handle->a, handle->sizea, act) == 3)
		check++;
	max = act;
	act = ft_find_n_bigger(handle->a, handle->sizea, max);
	if (ft_find_this(handle->a, handle->sizea, act) == 4)
		check++;
	max = act;
	act = ft_find_n_bigger(handle->a, handle->sizea, max);
	if (ft_find_this(handle->a, handle->sizea, act) == 0)
		check++;
	max = act;
	act = ft_find_n_bigger(handle->a, handle->sizea, max);
	if (ft_find_this(handle->a, handle->sizea, act) == 1)
		check++;
	check = (check == 5) ? 1 : 0;
	return (check);
}

static void				ft_algo_perso_1(t_push *handle)
{
	int max;
	int where;

	if (handle->sizea == 5)
		if (ft_worst_numbers(handle) == 1)
		{
			ft_reverse_rotate_a(handle);
			ft_reverse_rotate_a(handle);
		}
	max = ft_find_bigger(handle->a, handle->size);
	where = ft_find_this(handle->a, handle->size, max);
	ft_wich_path(handle, where, -1);
	if (!ft_is_sort(handle->a, handle->size))
	{
		where = ft_find_this(handle->a, handle->size,
				ft_find_n_bigger(handle->a, handle->size, max));
		ft_while_f(handle, where, &ft_push_a, &ft_rotate_a);
		ft_while_f(handle, handle->sizea - 2, &ft_push_a, &ft_rotate_a);
		ft_finish_him(handle);
	}
}

static int				ft_algo_insert_a_plus(t_push *handle, int *i, int *j)
{
	if (handle->a[0] > handle->a[1])
		ft_swap_a(handle);
	if (!ft_is_nsort(handle->a, *i))
	{
		ft_rotate_a(handle);
		*j = *j + 1;
		*i = *i - 1;
		return (1);
	}
	*i = *i + *j;
	return (0);
}

void					ft_algo_insert_a(t_push *handle)
{
	int		i;
	int		j;

	i = 2;
	j = 0;
	while (i <= handle->sizea)
	{
		if (!ft_is_nsort(handle->a, i))
		{
			if (ft_algo_insert_a_plus(handle, &i, &j))
				continue ;
			while (j > 0)
			{
				ft_reverse_rotate_a(handle);
				j--;
			}
		}
		if (ft_is_sort(handle->a, handle->sizea))
			break ;
		if (i < handle->sizea)
			ft_reverse_rotate_a(handle);
		i++;
	}
}

void					ft_sort_push_swap(t_push *handle, int algo_pass)
{
	if (algo_pass == 0)
		ft_quick_sort_1(handle);
	if (algo_pass == 1)
		ft_algo_perso_1(handle);
	if (algo_pass == 2)
		ft_algo_insert_a(handle);
	if (algo_pass == 3)
		ft_sort_under_5_a(handle);
}
