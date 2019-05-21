/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:59:23 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 19:13:05 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int					ft_find_this(int *tab, int size, int this)
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

long					ft_find_bigger(int *tab, int size)
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

int					ft_find_n_bigger(int *tab, int size, int beforethis)
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

void				ft_wich_path(t_push *handle, int where, char pole)
{
	int n;

	if (where > handle->sizea / 2)
	{
		n = handle->sizea - where - 1;
		while (n)
		{
			ft_reverse_rotate_a(handle);
			n--;
		}
	}
	else
	{
		n = where;
		while (n != pole)
		{
			ft_rotate_a(handle);
			n--;
		}
	}
}

int					ft_is_nsort(int *tab, int size)
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
