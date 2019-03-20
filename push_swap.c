/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:45 by akremer           #+#    #+#             */
/*   Updated: 2019/03/20 11:37:58 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_push		*ft_fill_struc(int argc, char **argv)
{
	int i;
	t_push *handle;

	i = 0;
	if (!(handle = (t_push*)malloc(sizeof(t_push))))
		return (NULL);
	handle->size = argc - 1;
	if (!(handle->a = (int*)malloc(sizeof(int) * handle->size)))
	{
		free(handle);
		return (NULL);
	}
	if (!(handle->b = (int*)malloc(sizeof(int) * handle->size)))
	{
		free(handle->a);
		free(handle);
		return (NULL);
	}
	ft_bzero((void*)handle->b, handle->size);
	handle->argv = argv;
	handle->sizea = handle->size;
	handle->sizeb = 0;
	return (handle);
}

static void			ft_free_handle(t_push *handle)
{
	free(handle->a);
	free(handle->b);
	free(handle);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_push	*handle;

	if (argc == 1)
		return (0);
	handle = ft_fill_struc(argc, argv);
	if (!handle)
		ft_print_error();
	ft_fill_argv(handle);
	ft_printf("Avant le tri:\n");
	ft_print_tab(handle->a, handle->size, "handle->a");
	if (ft_is_sort(handle) == 0)
	{
//		ft_printf("Lancement du tri:\n");
		ft_sort_push_swap(handle);
//		ft_printf("Sortie du tri\n");
	}
	else
		ft_printf("Trier\n");
//	ft_printf("Free.\n");
	ft_free_handle(handle);
	ft_printf("Tout clear !\n(Enfin il me semble)\n");
	return (0);
}
