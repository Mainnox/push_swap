/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 06:56:54 by akremer           #+#    #+#             */
/*   Updated: 2019/03/20 11:40:00 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//static void		ft_test_ope_push_swap(t_push *handle)
//{
//	ft_printf("Test sa:\n");
//	ft_printf("Avant:\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_swap(handle->a);
//	ft_printf("Apres.\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_printf("Test sb:\n");
//	ft_printf("Avant:\n");
//	ft_print_tab(handle->b, handle->size, "handle->b");
//	ft_swap(handle->b);
//	ft_printf("Apres.\n");
//	ft_print_tab(handle->b, handle->size, "handle->b");
//	ft_printf("Test pa:\n");
//	ft_printf("Avant:\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_print_tab(handle->b, handle->size, "handle->b");
//	ft_push(handle->a, handle->b, handle->size);
//	ft_push(handle->a, handle->b, handle->size);
//	ft_push(handle->a, handle->b, handle->size);
//	ft_push(handle->a, handle->b, handle->size);
//	ft_printf("Apres.\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_print_tab(handle->b, handle->size, "handle->b");
//	ft_printf("Test sa:\n");
//	ft_printf("Avant:\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_swap(handle->a);
//	ft_printf("Apres.\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_printf("Test ra:\n");
//	ft_printf("Avant:\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_rotate(handle->a, handle->size);
//	ft_printf("Apres.\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_printf("Test sa:\n");
//	ft_printf("Avant:\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_swap(handle->a);
//	ft_printf("Apres.\n");
//	ft_print_tab(handle->a, handle->size, "handle->a");
//	ft_printf("Test rrb:\n");
//	ft_printf("Avant:\n");
//	ft_print_tab(handle->b, handle->size, "handle->b");
//	ft_reverse_rotate(handle->b, handle->size);
//	ft_printf("Apres.\n");
//	ft_print_tab(handle->b, handle->size, "handle->b");
//}

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

// Pas compliquer nan ?
// Bon en suite
// Le squelette 
// struct ?
// On va voir

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
//	ft_printf("\n\n\n\nret = %d\n\n\n\n", ret);
//	ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");
	return (ret);
}
	//ft_print_tab(handle->a, handle->sizea, "handle->a");
//	ft_print_tab(handle->b, handle->sizeb, "handle->b");

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
		ft_wich_path(handle, ft_find_this(handle->b, handle->sizeb, next), &ft_reverse_rotate_b, &ft_rotate_b, 0);
		ft_push_b(handle);
		max = next;
	}
}

void				ft_sort_push_swap(t_push *handle)
{
	int max;
	int where;

	max = ft_find_bigger(handle->a, handle->size);
	where = ft_find_this(handle->a, handle->size, max);
	ft_wich_path(handle, where, &ft_reverse_rotate_a, &ft_rotate_a ,-1);
	where = ft_find_this(handle->a, handle->size, ft_find_n_bigger(handle->a, handle->size, max));
	ft_while_f(handle, where, &ft_push_a, &ft_rotate_a);
	ft_while_f(handle, handle->sizea - 2, &ft_push_a, &ft_rotate_a);
	ft_printf("FINISH HIM !\n");
	ft_finish_him(handle);
	ft_print_tab(handle->a, handle->sizea, "handle->a");
	ft_print_tab(handle->b, handle->sizeb, "handle->b");
	ft_printf("FATALITY !\n");
}
