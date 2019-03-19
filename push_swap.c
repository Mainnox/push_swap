/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:45 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 15:09:51 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int		ft_fill_struc(t_push handle, int argc, char **argv)
{
	int i;

	i = 0;
	handle.size = argc - 1;
	if (!(handle.a = (int*)malloc(sizeof(int) * handle.size)))
		return (-12);
	if (!(handle.b = (int*)malloc(sizeof(int) * handle.size)))
		return (-12);
	handle.argv = argv;
	return (1);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_push	handle;

	handle.size = 0;
	if (argc == 1)
		return (0);
	if (!ft_fill_struc(handle, argc, argv))
		ft_print_error();
	if (!ft_check_argv(handle))
		ft_print_error();
	return (0);
}
