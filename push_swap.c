/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:45 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 17:34:28 by akremer          ###   ########.fr       */
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
		return (NULL);
	if (!(handle->b = (int*)malloc(sizeof(int) * handle->size)))
		return (NULL);
	handle->argv = argv;
	return (handle);
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
	if (!ft_is_sort(handle))
		ft_printf("Pas trier\n");
	else
		ft_printf("Trier\n");
	return (0);
}
