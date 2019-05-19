/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:01:44 by akremer           #+#    #+#             */
/*   Updated: 2019/05/19 18:34:56 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			*ft_init_progress(void)
{
	int		*tab;

	if (!(tab = (int*)malloc(sizeof(int) * 1)))
		return (NULL);
	tab[0]= -1;
	return (tab);
}

int			ft_realloc_progress(t_push *handle, char wich)
{
	int		*tmp;
	int		size;

	if (wich == 1)
	{
		size = handle->size_progres;
		if (!(tmp = (int*)malloc(sizeof(int) * size + 1)))
			return (-1);
		ft_memcpy(tmp, handle->progres, size);
		free(handle->progres);
		handle->progres = tmp;
		handle->size_progres++;
	}
	if (wich == 0)
	{
		size = handle->size_progres;
		if (!(tmp = (int*)malloc(sizeof(int) * size - 1)))
			return (-1);
		ft_memcpy(tmp, handle->progres, size - 1);
		tmp[size - 2] = -1;
		free(handle->progres);
		handle->progres = tmp;
		handle->size_progres--;
	}
	return (1);
}

void		ft_add_progress(t_push *handle, int new)
{
	int where;

	if (!ft_realloc_progress(handle, 1))
		ft_print_error();
	handle->progres[handle->size_progres - 2] = new;
}
