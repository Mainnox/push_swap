/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:28:58 by akremer           #+#    #+#             */
/*   Updated: 2019/03/22 14:52:00 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static t_check			*ft_fill_struc_checker(int argc, char **argv)
{
	int i;
	t_check *handle;

	i = 0;
	if (!(handle = (t_check*)malloc(sizeof(t_check))))
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
	if (!(handle->gnl = (char**)malloc(sizeof(char*) * 1)))
		return (NULL);
	ft_bzero((void*)handle->b, handle->size);
	handle->argv = argv;
	handle->sizea = handle->size;
	handle->sizeb = 0;
	handle->nb_ope = 0;
	return (handle);
}

void		ft_print_error_checker(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

static void	ft_free_handle_checker(t_check *handle)
{
	free(handle->a);
	free(handle->b);
	free(handle->gnl);
	free(handle);
}

int			main(int argc, char **argv)
{
	t_check *handle;
	
	if (argc == 1)
		return (0);
	handle = ft_fill_struc_checker(argc, argv);
	if (!handle)
		ft_print_error_checker();
	ft_fill_argv_checker(handle);
	ft_print_tab_checker(handle->a, handle->sizea, "handle->a");
	while (get_next_line(0, handle->gnl) > 0)
	{
		ft_printf("Return de gnl: %s\n", handle->gnl[0]);
		ft_bzero(handle->gnl[0], ft_strlen(handle->gnl[0]));
		ft_printf("Verif bzero: %s\n", handle->gnl[0]);
		ft_do_op_checker(handle);
	}
	if (ft_is_sort_checker(handle))
		ft_putchar_puissant("OK\n");
	else
		ft_putchar_puissant("KO\n");
	ft_print_tab_checker(handle->a, handle->sizea, "handle->a");
	ft_print_tab_checker(handle->b, handle->sizeb, "handle->b");
	ft_free_handle_checker(handle);
	return (0);
}
