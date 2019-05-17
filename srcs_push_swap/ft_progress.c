/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:01:44 by akremer           #+#    #+#             */
/*   Updated: 2019/05/17 12:27:12 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			*ft_int_progress(void)
{
	int		*tab;

	if (!(tab = (int*)malloc(sizeof(int) * 1)))
		return (NULL);
	tab[0]= -1;
	return (tab);
}

int			ft_reallloc_progress(int *tab, char wich)
{
	int		*tmp;
	int		size;

	if (wich == 1)
	{
		size = ft_tablen(tab, -1);
		if (!(tmp = (int*)malloc(sizeof(int) * size + 1)))
			return (-1);
		ft_memcpy(tmp, tab, size);
		tmp[size - 2] = 0;
		tmp[size - 1] = -1;
		free(tab);
		tab = tmp;
	}
	if (wich == 0)
	{
		size = ft_tablen(tab, -1);
		if (!(tmp = (int*)malloc(sizeof(int) * size)))
			return (-1);
		ft_memcpy(tmp, tab, size - 1);
		tmp[size - 1] = -1;
		free(tab);
		tab = tmp;
	}
	return (1);
}

void		ft_add_progress(int *tab, int new)
{
	int where;

	if (!ft_realloc_progress(tab, 1))
		ft_print_error();
	where = ft_tablen(tab, 0) - 1;
	tab[where] = new;
}
