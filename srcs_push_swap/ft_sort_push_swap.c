/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 06:56:54 by akremer           #+#    #+#             */
/*   Updated: 2019/03/25 11:10:55 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int			ft_find_this(int *tab, int size, int this)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == this)
			return (i);
		i++;
	}
	return (-1);
}

static int			ft_find_bigger(int *tab, int size)
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

static int			ft_find_n_bigger(int *tab, int size, int beforethis)
{
	int i;
	int ret;

	i = 0;
	ret = tab[i];
	while (i < size)
	{
		if (tab[i] > ret && tab[i] < beforethis)
			ret = tab[i];
		i++;
	}
	return (ret);
}

static void			ft_wich_path(t_push *handle, int where, void (*f)(t_push *handle), void (*ft)(t_push *handle), char pole)
{
	int n;

	if (where > handle->size / 2)
	{
		n = handle->size - where - 1;
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

static void			ft_wich_path2(t_push *handle, int where, void (*f)(t_push *handle), void (*ft)(t_push *handle), char pole)
{
	int n;

	if (where > handle->sizeb / 2)
	{
		n = handle->sizeb - where;
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

static void			ft_while_f(t_push *handle, int n, void (*f)(t_push *handle), void(*ft)(t_push *handle))
{
	while (n != 0)
	{
		f(handle);
		n--;
	}
	ft(handle);
}

//LES ZEROS B***** GERE LES !!
//C'est sur les swaps mais je m'en sers pas pour l'instant
//Pour l'algo la pas besoin de faire des courbettes

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
			next = ft_find_n_bigger(handle->b, handle->sizeb, max);
		else
			soothsayer--;
		ft_wich_path2(handle, ft_find_this(handle->b, handle->sizeb, next), &ft_reverse_rotate_b, &ft_rotate_b, 0);
		ft_push_b(handle);
	}
}

static void				ft_algo_perso_1(t_push *handle)
{
	int max;
	int where;

	max = ft_find_bigger(handle->a, handle->size);
	where = ft_find_this(handle->a, handle->size, max);
	ft_wich_path(handle, where, &ft_reverse_rotate_a, &ft_rotate_a ,-1);
	if (!ft_is_sort(handle))
	{
		where = ft_find_this(handle->a, handle->size, ft_find_n_bigger(handle->a, handle->size, max));
		ft_while_f(handle, where, &ft_push_a, &ft_rotate_a);
		ft_while_f(handle, handle->sizea - 2, &ft_push_a, &ft_rotate_a);
		ft_finish_him(handle);
	}
}

static void				ft_is_nsort(t_push *handle, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (handle->a[i] > handle->a[j])
				return (0);
			j++;
		}
		i++;
	}
}

static void				ft_reorder_insert(t_push *handle, int size)
{
		if (handle->a[0] >handle->a[1])
			ft_swap_a(handle);
}

static void				ft_algo_insert(t_push *handle)
{
	int		i;

	i = 2;
	while (i <= handle->sizea)
	{
		if (!ft_is_sort(handle))
			ft_reorder_insert(handle, i);
		if (++i <= handle->sizea)
			ft_reverse_rotate_a(handle);
	}
}

void					ft_sort_push_swap(t_push *handle, int algo_pass)
{
	if (algo_pass == 0)
		ft_algo_perso_1(handle);
	if (algo_pass == 1)
		ft_algo_insert(handle);
}
