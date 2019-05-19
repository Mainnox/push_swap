/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 06:56:54 by akremer           #+#    #+#             */
/*   Updated: 2019/05/19 18:42:36 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			ft_find_this(int *tab, int size, int this)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == this)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int					ft_find_bigger(int *tab, int size)
{
	int i;
	int ret;

	i = 0;
	ret = tab[i];
	while (i < size)
	{
		if (tab[i] > ret)
			ret = tab[i];
		i++;
	}
	return (ret);
}

int			ft_find_n_bigger(int *tab, int size, int beforethis)
{
	int i;
	int ret;

	i = 0;
	ret = beforethis - 1;
	while (i < size)
	{
		if (tab[i] > ret && tab[i] < beforethis)
			ret = tab[i];
		i++;
	}
	return (ret);
}

void			ft_wich_path(t_push *handle, int where, void (*f)(t_push *handle), void (*ft)(t_push *handle), char pole)
{
	int n;

	if (where > handle->sizea / 2)
	{
		n = handle->sizea - where - 1;
		while (n)
		{
			f(handle);
			n--;
		}
	}
	else
	{
		n = where;
		while (n != pole)
		{
			ft(handle);
			n--;
		}
	}
}

static void			ft_wich_path2(t_push *handle, int nb, void (*f)(t_push *handle), void (*ft)(t_push *handle), char pole)
{
	int where;

	where = ft_find_this(handle->b, handle->sizeb, nb);
	if (where > handle->sizeb / 2)
	{
		while (ft_find_this(handle->b, handle->sizeb, nb) != pole)
			f(handle);
	}
	else
	{
		while (ft_find_this(handle->b, handle->sizeb, nb) != pole)
			ft(handle);
	}
}

static void			ft_while_f(t_push *handle, int n, void (*f)(t_push *handle), void(*ft)(t_push *handle))
{
	while (n != 0)
	{
		f(handle);
		n--;
	}
	ft(handle);
}

static void			ft_finish_him(t_push *handle)
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
		ft_wich_path2(handle, next, &ft_reverse_rotate_b, &ft_rotate_b, 0);
		ft_push_b(handle);
	}
}

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
	if (check == 5)
		return (1);
	return (0);
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
	ft_wich_path(handle, where, &ft_reverse_rotate_a, &ft_rotate_a ,-1);
	if (!ft_is_sort(handle->a, handle->size))
	{
		where = ft_find_this(handle->a, handle->size, ft_find_n_bigger(handle->a, handle->size, max));
		ft_while_f(handle, where, &ft_push_a, &ft_rotate_a);
		ft_while_f(handle, handle->sizea - 2, &ft_push_a, &ft_rotate_a);
		ft_finish_him(handle);
	}
}

static int				ft_is_nsort(int *tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void				ft_algo_insert_a(t_push *handle)
{
	int		i;
	int		j;

	i = 2;
	j = 0;
	while (i <= handle->sizea)
	{
		if (!ft_is_nsort(handle->a, i))
		{
			if (handle->a[0] > handle->a[1])
				ft_swap_a(handle);
			if (!ft_is_nsort(handle->a, i))
			{
				ft_rotate_a(handle);
				j++;
				i--;
				continue ;
			}
			i += j;
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

void				ft_algo_insert_b(t_push *handle)
{
	int		i;
	int		j;
	int		max;
	int		rotate;

	rotate = 0;
	max = ft_find_bigger(handle->b, handle->sizeb);
	i = 2;
	j = 0;
	while (i <= handle->sizeb)
	{
		if (!ft_is_nsort(handle->b, i))
		{
			if (handle->b[0] == max)
			{
				ft_push_b(handle);
				max = ft_find_n_bigger(handle->b, handle->sizeb, max);
				if (i != 2)
					i--;
				rotate++;
				continue ;
			}
			if (handle->b[0] == handle->low)
			{
				ft_put_b_on_a(handle, 1);
				handle->low = ft_find_low(handle);
				if (i != 2)
					i--;
				continue ;
			}
			if (handle->b[0] > handle->b[1])
				ft_swap_b(handle);
			if (!ft_is_nsort(handle->b, i))
			{
				ft_rotate_b(handle);
				j++;
				i--;
				continue ;
			}
			i += j;
			while (j > 0)
			{
				ft_reverse_rotate_b(handle);
				j--;
			}
		}
		if (ft_is_sort(handle->b, handle->sizeb))
			break ;
		if (i < handle->sizeb)
			ft_reverse_rotate_b(handle);
		i++;
	}
	while (handle->sizeb)
		ft_put_b_on_a(handle, 1);
	handle->ign += rotate;
	while (rotate)
	{
		ft_rotate_a(handle);
		rotate--;
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
}
