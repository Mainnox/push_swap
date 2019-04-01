/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 06:56:54 by akremer           #+#    #+#             */
/*   Updated: 2019/04/01 16:36:06 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			ft_find_this(int *tab, int size, int this)
{
	int i;

	i = 0;
	ft_printf("this = %d\n", this);
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

//	ft_printf("where = %d\n", where);
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
//	ft_printf("next = %d\n", nb);
//	ft_printf("where = %d\n", where);
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
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
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

	i = 2;
	j = 0;
	while (i <= handle->sizeb)
	{
		if (!ft_is_nsort(handle->b, i))
		{
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
}
/*
static t_push			*ft_make_save(t_push *handle)
{
	t_push		*save;

	if (!(save = (t_push*)malloc(sizeof(t_push))))
		ft_print_error();
	if (!(save->a = (int*)malloc(sizeof(int) * handle->size)))
			ft_print_error();
	if (!(save->b = (int*)malloc(sizeof(int) * handle->size)))
		ft_print_error();
	if (!(save->hack = (char*)malloc(sizeof(char) * 1)))
		ft_print_error();
	ft_bzero((void*)save->b, handle->size);
	save->sizea = handle->sizea;
	save->sizeb = handle->sizeb;
	save->nb_ope = 0;
	save->a = ft_memcpy((void*)save->a, (void*)handle->a, handle->sizea);
	save->b = ft_memcpy((void*)save->b, (void*)handle->b, handle->sizeb);
	return (save);
}

static void				ft_sort_a(t_push *handle)
{
//	t_push		*save;

//	save = ft_make_save(handle);
	return ;
}

static int				ft_find_mid(int *tab, int size, int ign)
{
	int		*save;
	int		to_find;
	int		i;

	size -= ign;
	i = 0;
	to_find = 0;
	if (!(save = (int*)malloc(sizeof(int) * size)))
		ft_print_error();
	save = ft_memcpy(save, tab, size);
	ft_sort_integer_table(save, size);
	while (i < size / 2)
		i++;
	to_find = save[i];
	free(save);
	return (to_find);
}

static void				ft_reduc_a_2(t_push *handle)
{
	int		median;
	int		i;
	int		j;

	j = 0;
	i = 0;
	median = ft_find_mid(handle->a, handle->sizea, handle->ign);
	while (i < (handle->sizea - handle->ign))
 	{
		if (handle->a[0] < median)
			ft_push_a(handle);
		else
		{
			ft_rotate_a(handle);
			j++;
		}
		i++;
	}
	while (j)
	{
		ft_reverse_rotate_a(handle);
		j--;
	}
}

static void				ft_reduc_b_2(t_push *handle)
{
	int		median;
	int		i;
	int		j;

	j = 0;
	i = 0;
	median = ft_find_mid(handle->b, handle->sizeb, handle->ign);
	while (i < (handle->sizeb - handle->ign))
 	{
		if (handle->b[0] < median)
			ft_push_b(handle);
		else
		{
			ft_rotate_a(handle);
			j++;
		}
		i++;
	}
	while (j)
	{
		ft_reverse_rotate_a(handle);
		j--;
	}
}

static void				ft_reduc_a(t_push *handle)
{
	int		median;
	int		i;
	int		size;
	int		j;

	j = 0;
	size = handle->sizea - handle->ign;
	i = 0;
	if ((handle->sizea - handle->ign) <= NBR_OK)
		median = ft_find_bigger(handle->a, handle->sizea);
	else
		median = ft_find_mid(handle->a, handle->sizea, handle->ign);
	while (i < size)
 	{
		if (handle->a[0] < median)
			ft_push_a(handle);
		else
		{
			ft_rotate_a(handle);
			j++;
		}
		i++;
	}
	while (j)
	{
		ft_reverse_rotate_a(handle);
		j--;
	}
}

static void				ft_reduc_b(t_push *handle)
{
	int		median;
	int		i;
	int		size;
	int		j;

	j = 0;
	size = handle->sizea - handle->ign;
	i = 0;
	median = ft_find_mid(handle->b, handle->sizeb, handle->ign);
	while (i < size)
	{
		if (handle->b[0] < median)
			ft_push_b(handle);
		else
		{
			ft_rotate_b(handle);
			j++;
		}
		i++;
	}
	while (j)
	{
		ft_reverse_rotate_b(handle);
		j--;
	}
}

static void				ft_quick_sort_1(t_push *handle)
{
	int		i;
	int		j;
	int		check;

	check = 0;
	j = 0;
	i = 0;
	if (handle->sizea <= NBR_OK && !ft_is_sort(handle->a, handle->sizea))
	{
		ft_algo_insert_a(handle);
		check++;
	}
	if (handle->sizeb <= NBR_OK && handle->sizeb)
	{
		ft_algo_insert_b(handle);
		while (handle->sizeb)
		{
			ft_push_b(handle);
			ft_rotate_a(handle);
			i++;
		}
		handle->ign += i;
		i = 0;
	}
	if (check != 0)
	{
		j = handle->ign;
		while (j)
		{
			ft_rotate_a(handle);
			j--;
		}
		check = 0;
	}
	if (handle->sizeb > NBR_OK)
		ft_reduc_b(handle);
	if (handle->sizea > NBR_OK && !ft_is_sort(handle->a, handle->sizea))
		ft_reduc_a(handle);
	if (!ft_is_sort(handle->a, handle->sizea))
		ft_quick_sort_1(handle);
	ft_print_tab(handle->a, handle->sizea, "handle->a");
	ft_print_tab(handle->b, handle->sizeb, "handle->b");
}

static void				ft_quick_sort_2(t_push *handle)
{
	int		i;
	int		j;
	int		check;

	check = 0;
	j = 0;
	i = 0;
	if (handle->sizea <= NBR_OK && !ft_is_sort(handle->a, handle->sizea))
	{
		ft_algo_insert_a(handle);
		check++;
	}
	if (handle->sizeb <= NBR_OK && handle->sizeb)
	{
		ft_algo_insert_b(handle);
		while (handle->sizeb)
		{
			ft_push_b(handle);
			ft_rotate_a(handle);
			i++;
		}
		handle->ign += i;
		i = 0;
	}
	if (check != 0)
	{
		j = handle->ign;
		while (j)
		{
			ft_rotate_a(handle);
			j--;
		}
		check = 0;
	}
	if (handle->sizeb > NBR_OK)
		ft_reduc_b_2(handle);
	if (handle->sizea > NBR_OK && !ft_is_sort(handle->a, handle->sizea))
		ft_reduc_a_2(handle);
	if (!ft_is_sort(handle->a, handle->sizea))
		ft_quick_sort_2(handle);
}*/

void					ft_sort_push_swap(t_push *handle, int algo_pass)
{
	if (algo_pass == 0)
		ft_quick_sort_1(handle);
	if (algo_pass == 1)
		ft_algo_perso_1(handle);
	if (algo_pass == 2)
		ft_algo_insert_a(handle);
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
}
