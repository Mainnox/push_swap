/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:28:58 by akremer           #+#    #+#             */
/*   Updated: 2019/03/25 14:55:17 by akremer          ###   ########.fr       */
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
	handle->option = NULL;
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
	if (handle->option != NULL)
		free(handle->option);
	free(handle);
}

int			main(int argc, char **argv)
{
	t_check *handle;
	char *beautiful_tab;

	beautiful_tab = "_________________________________________________";
	if (argc == 1)
		ft_print_error_checker();
	handle = ft_fill_struc_checker(argc, argv);
	if (!handle)
		ft_print_error_checker();
	ft_fill_argv_checker(handle);
		if (handle->option)
			if (ft_strstr(handle->option, "v"))
			{
				if (handle->sizea > 0)
				{
				ft_printf("\n\t\tLa jolie pile a:\n%s\n", beautiful_tab);
				ft_print_tab_checker(handle->a, handle->sizea, "tab->a");
				ft_printf("%s\n", beautiful_tab);
				}
				if (handle->sizeb > 0)
				{
				ft_printf("\n\t\tLa tres jolie pile b:\n%s\n", beautiful_tab);
				ft_print_tab_checker(handle->b, handle->sizeb, "tab->b");
				ft_printf("%s\n", beautiful_tab);
				}
			}
	while (get_next_line(0, handle->gnl) > 0)
	{
		ft_do_op_checker(handle);
		if (handle->option)
			if (ft_strstr(handle->option, "v"))
			{
				if (handle->sizea > 0)
				{
				ft_printf("\n\t\tLa jolie pile a:\n_________________________________________________\n");
				ft_print_tab_checker(handle->a, handle->sizea, "tab->a");
				ft_printf("__________________________________________________\n");
				}
				if (handle->sizeb > 0)
				{
				ft_printf("\n\t\tLa tres jolie pile b:\n__________________________________________________\n");
				ft_print_tab_checker(handle->b, handle->sizeb, "tab->b");
				ft_printf("__________________________________________________\n");
				}
			}
	}
	if (ft_is_sort_checker(handle))
		ft_putchar_puissant("OK\n");
	else
		ft_putchar_puissant("KO\n");
	if (handle->option)
		if (ft_strstr(handle->option, "n"))
			ft_printf("Nombre d'operation = %d\n", handle->nb_ope);
	ft_free_handle_checker(handle);
	return (0);
}
