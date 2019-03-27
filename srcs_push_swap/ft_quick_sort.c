/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:28:48 by akremer           #+#    #+#             */
/*   Updated: 2019/03/27 15:55:25 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

/*static void				ft_reduc_a(t_push *handle)
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
*/
static int					ft_find_mid(int *tab, int size, int ign)
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

static void					ft_split_a(t_push *handle)
{
	int		mid;
	int		i;
	int		size;

	i = 0;
	size = handle->sizea - handle->ign;
	mid = ft_find_mid(handle->a, handle->sizea, handle->ign);
	while (i < size)
	{
		if (handle->a[0] < mid)
			ft_push_a(handle);
		else
			ft_rotate_a(handle);
		i++;
	}
}

static void					ft_split_b(t_push *handle)
{
	int		mid;
	int		i;

	i = 0;
	mid = ft_find_mid(handle->b, handle->sizeb, 0);
	while (i < handle->sizeb)
	{
		if (handle->b[0] < mid)
			ft_push_b(handle);
		else
			ft_rotate_b(handle);
		i++;
	}
	if (handle->sizeb > NBR_OK)
		ft_split_b(handle);
}

static void					ft_put_b_on_a(t_push *handle, int how_many)
{
	int		i;

	i = 0;
	while (i < how_many)
	{
		ft_push_b(handle);
		ft_rotate_a(handle);
		i++;
	}
	handle->ign += i;
}

static void					ft_replace_head(t_push *handle)
{
	int		i;

	i = 0;
	while (handle->a[0] > handle->a[handle->sizea])
		ft_rotate_a(handle);
}

void						ft_quick_sort_1(t_push *handle)
{
	if (handle->sizea > NBR_OK)
		ft_split_a(handle);
	if (handle->sizeb > NBR_OK)
		ft_split_b(handle);
	if (handle->sizea <= NBR_OK)
		ft_algo_insert_a(handle);
	if (handle->sizeb <= NBR_OK && handle->sizeb)
		ft_algo_insert_b(handle);
	if (handle->sizeb)
		ft_put_b_on_a(handle, handle->sizeb);
	if (ft_is_sort(handle->a, handle->sizea - handle->ign))
		ft_replace_head(handle);
	ft_print_tab(handle->b, handle->sizeb, "handle->b");
//	if (!ft_is_sort(handle->a, handle->sizea) && !handle->sizeb)
//		ft_quick_sort_1(handle);
}

/*static void				ft_quick_sort_1(t_push *handle)
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
}*/
