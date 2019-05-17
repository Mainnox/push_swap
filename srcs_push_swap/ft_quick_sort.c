/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:28:48 by akremer           #+#    #+#             */
/*   Updated: 2019/05/17 15:56:46 by akremer          ###   ########.fr       */
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
	if ((handle->sizea - handle->ign) <= handle->nbr_ok)
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

static int					ft_find_mid(int *tab, int size, int ign)
{
	int		*save;
	int		to_find;
	int		i;

	if (size - ign <= handle->nbr_ok)
		return (2147483647);
	else
		i = 0;
	size -= ign;
	to_find = 0;
	if (!(save = (int*)malloc(sizeof(int) * size)))
		ft_print_error();
	save = ft_memcpy(save, tab, size);
	ft_printf("size = %d\n", size);
	ft_print_tab(save, size, "save");
	ft_sort_integer_table(save, size);
	while (i < size / 2)
		i++;
	to_find = save[i];
	free(save);
	return (to_find);
}
*/

/*static int					ft_find_mid(int *tab, int size, int ign)
{
	// Ok alors trouve le size / 2 bigger et voir si le temps et ok 
	int		i;
	int		ret;

	size -= ign;
	if (size <= handle->nbr_ok)
		return (2147483647);
	ret = ft_find_bigger(tab, size);
	i = 0;
	while (i < (size / 2))
	{
		ret = ft_find_n_bigger(tab, size, ret);
		i++;
	}
	return (ret);
}*/

int					ft_how_many_less(int *tab, int size, int nb)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (i < size)
	{
		if (tab[i] < nb)
			ret++;
		i++;
	}
	return (ret);
}

int							ft_find_mid(int *tab, int size, int nbr_ok)
{
	int		i;
	int		less;

	i = 0;
	if (size <= nbr_ok)
		return (2147483647);
	while (i < size)
	{
		less = ft_how_many_less(tab, size, tab[i]);
		if (less == size / 2)
			break ;
		i++;
	}
	return (tab[i]);
}

//static int					ft_find_n(int *tab, int size, int ign, int n)
//{
//	int		*save;
//	int		to_find;
//	int		i;
//
//	size -= ign;
//	i = 0;
//	to_find = 0;
//	if (!(save = (int*)malloc(sizeof(int) * size)))
//		ft_print_error();
//	save = ft_memcpy(save, tab, size);
//	ft_sort_integer_table(save, size);
//	to_find = save[n - 1];
//	free(save);
//	return (to_find);
//}

static void					ft_split_a(t_push *handle)
{
	int		mid;
	int		i;
	int		size;
	int		j;

	i = 0;
	size = handle->sizea - handle->ign;
	handle->mid = ft_find_mid(handle->a, handle->sizea - handle->ign, handle->nbr_ok);
	mid = handle->mid;
	j = ft_how_many_less(handle->a, handle->sizea, mid);
	while (i < size)
	{
		if (handle->a[0] < mid)
		{
			j--;
			ft_push_a(handle);
		}
		else
		{
			ft_rotate_a(handle);
		}
		i++;
		if (j <= 0)
			break ;
	}
}

void						ft_put_b_on_a(t_push *handle, int how_many)
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

static void					ft_split_b(t_push *handle)
{
	int		mid;
	int		i;
	int		size;
	int		j;
	int		progres;

	progres = 0;
	size = handle->sizeb;
	i = 0;
	mid = ft_find_mid(handle->b, handle->sizeb, handle->nbr_ok);
	j = ft_how_many_less(handle->b, handle->sizeb, mid);
//	ft_printf("Mid = %d\n", mid);
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
	while (i < size)
	{
		if (handle->b[0] == handle->low)
		{
			ft_put_b_on_a(handle, 1);
			handle->low = ft_find_low(handle);
			continue ;
		}
		if (handle->b[0] > mid)
		{
			progres++;
			ft_push_b(handle);
			j--;
		}
		else
			ft_rotate_b(handle);
		if (j <= 0)
			break ;
		i++;
	}
	if (progres != 0)
		ft_add_progress(handle, progres);
	if (handle->sizeb > handle->nbr_ok)
	{
		handle->mid = ft_find_bigger(handle->b, handle->sizeb) + 1;
		ft_split_b(handle);
	}
}


static int					ft_replace_head(int *tab, int size, int ign)
{
	int		i;

	i = 0;
	if (ign == 0)
		ign = 1;
	while (i < size)
	{
		if (ft_how_many_less(tab, size, tab[i]) == ign - 1)
			break;
		i++;
	}
//	ft_print_tab(tab, size, "tab");
//	ft_printf("ign = %d\n", ign);
//	ft_printf("i = %d\n", i);
//	sleep(10);
	return (i);
}

int							ft_find_low(t_push *handle)
{
	int		low;
	int		i;

	i = 0;
//	ft_printf("Ici\n");
	low = handle->a[0];
	while (i < handle->sizea - handle->ign)
	{
		if (low > handle->a[i] && handle->a[i] > handle->low)
			low = handle->a[i];
		i++;
	}
	i = 0;
	while (i < handle->sizeb)
	{
		if (low > handle->b[i] && handle->b[i] > handle->low)
			low = handle->b[i];
		i++;
	}
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
//	ft_printf("low = %d\n", low);
//	sleep(2);
	return (low);
}

void						ft_quick_sort_1(t_push *handle)
{
	int		tmp;

	tmp = 0;
	handle->low = ft_find_low(handle);
//	ft_printf("\nDebut de quick_sort\n\n");
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
//	ft_printf("size = %d\n", handle->size_progres);
//	int i = 0;
//	while (i < handle->size_progres)
//	{
//		ft_printf("handle->progress[%d] = %d\n", i, handle->progres[i]);
//		i++;
//	}
//	ft_printf("handle->progres[0] = %d\n", handle->progres[0]);
	if (handle->sizea - handle->ign > 0 && handle->progres[0] <= 0)
		ft_split_a(handle);
//	if (handle->progress)
//	{
//		if (handle->progress > handle->nbr_ok)
//		{
//			tmp = handle->progress;
//			while (tmp > handle->nbr_ok)
//			{
//				tmp = tmp;
//				ft_printf("Hello there\n");
//			}
//			while (tmp)
//			{
//				ft_push_a(handle);
//				tmp--;
//			}
//		}
//	}
//		else
	else
	{
//		ft_printf("handle->progres[handle->size_progres - 1] = %d\n", handle->progres[handle->size_progres - 1]);
		int m = 0;
		while (m < handle->size_progres)
		{
//			ft_printf("progres[%d] = %d\n", m, handle->progres[m]);
			m++;
		}
		while (handle->progres[handle->size_progres - 2])
		{
			ft_push_a(handle);
			handle->progres[handle->size_progres - 2]--;
		}
		ft_realloc_progress(handle, 0);
	}
	if (handle->tour != 0)
		ft_wich_path(handle, ft_replace_head(handle->a, handle->sizea, handle->ign)
				, &ft_reverse_rotate_a, &ft_rotate_a, -1);
//	ft_printf("\nApres 1th wich path !\n\n");
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
	if (handle->sizeb > handle->nbr_ok)
		ft_split_b(handle);
//	ft_printf("progress : %d\n", handle->progress);
//	sleep (2);
//	ft_printf("\nApres split b!\n\n");
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
	if (handle->sizeb <= handle->nbr_ok && handle->sizeb)
		ft_algo_insert_b(handle);
//	ft_printf("\nApres insert !\n\n");
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
//	ft_printf("Gne\n");
	if (handle->sizeb)
		ft_put_b_on_a(handle, handle->sizeb);
//	ft_printf("\nApres put b !\n\n");
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
//	ft_wich_path(handle, ft_find_this(handle->a, handle->sizea
//				, ft_find_n(handle->a, handle->sizea, 0, handle->ign))
//				, &ft_reverse_rotate_a, &ft_rotate_a, -1);
//	ft_printf("\nAvant la recursive !\n\n");
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
//	sleep(7);
//	ft_printf("Tu passe ?\n");
	if (!ft_is_sort(handle->a, handle->sizea) && !handle->sizeb)
	{
		handle->tour++;
//		ft_printf("handle->progress = %d\n", handle->progress);
		int i = 0;
		while (i < handle->size_progres)
		{
//			ft_printf("progres[%d] = %d\n", i, handle->progres[i]);
			i++;
		}

//		if (handle->tour < 2)
		ft_quick_sort_1(handle);
	}
//	ft_printf("Tu sort?\n");
}
