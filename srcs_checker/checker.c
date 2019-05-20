/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:28:58 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 19:45:56 by akremer          ###   ########.fr       */
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
	int		ope;
	int		slep;

	beautiful_tab = "_________________________________________________";
	if (argc == 1)
		return (0);
	handle = ft_fill_struc_checker(argc, argv);
	if (!handle)
		ft_print_error_checker();
	ft_fill_argv_checker(handle);
	if (handle->option)
	{
		if (ft_strstr(handle->option, "d"))
			slep = ft_atoi(ft_strstr(handle->option, "d") + 1);
		else
			slep = 0;
	}
	if (handle->option)
		if (ft_strstr(handle->option, "s"))
		{
			if (handle->sizea > 0)
			{
			ft_printf("\n\t\tStart::\n%s\n", beautiful_tab);
			ft_print_tab_checker(handle->a, handle->sizea, "tab->a");
			ft_printf("%s\n", beautiful_tab);
			}
		}
	while (get_next_line(0, handle->gnl) > 0)
	{
		ope = ft_do_op_checker(handle);
		if (handle->option)
			if(ft_strstr(handle->option, "v"))
				ft_visualizer(handle, ope, slep);
		free(handle->gnl[0]);
	}
		if (handle->option)
			if (ft_strstr(handle->option, "e"))
			{
				if (handle->sizea > 0)
				{
				ft_printf("\n\t\tPile a:\n_________________________________________________\n");
				ft_print_tab_checker(handle->a, handle->sizea, "tab->a");
				ft_printf("__________________________________________________\n");
				}
				if (handle->sizeb > 0)
				{
				ft_printf("\n\t\tPile b:\n__________________________________________________\n");
				ft_print_tab_checker(handle->b, handle->sizeb, "tab->b");
				ft_printf("__________________________________________________\n");
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
