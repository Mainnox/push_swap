/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:45 by akremer           #+#    #+#             */
/*   Updated: 2019/05/20 19:36:31 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void				ft_set_struct(t_push *handle, char **argv)
{
	handle->argv = argv;
	handle->sizea = handle->size;
	handle->sizeb = 0;
	handle->nb_ope = 0;
	handle->ign = 0;
	handle->mid = 0;
	handle->tour = 0;
	handle->progres = ft_init_progress();
	handle->size_progres = 1;
	handle->nbr_ok = 5;
	handle->low = -2147483648;
}

static t_push			*ft_fill_struc(int argc, char **argv)
{
	int		i;
	t_push	*handle;

	i = 0;
	if (!(handle = (t_push*)malloc(sizeof(t_push))))
		return (NULL);
	handle->size = argc - 1;
	if (!(handle->a = (int*)malloc(sizeof(int) * handle->size)))
		return (NULL);
	if (!(handle->b = (int*)malloc(sizeof(int) * handle->size)))
		return (NULL);
	if (!(handle->hack = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	ft_bzero((void*)handle->b, handle->size);
	ft_set_struct(handle, argv);
	return (handle);
}

void					ft_free_handle(t_push *handle)
{
	free(handle->a);
	handle->a = NULL;
	free(handle->b);
	handle->b = NULL;
	free(handle->hack);
	handle->hack = NULL;
	free(handle->progres);
	handle->progres = NULL;
	free(handle);
	handle = NULL;
}

void					ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int						main(int argc, char **argv)
{
	t_push	*handle;
	char	**sol;
	char	algo_pass;
	char	nb_algo;

	algo_pass = 0;
	if (argc == 1)
		return (0);
	nb_algo = (argc < 10) ? 3 : 1;
	sol = ft_init_sol(nb_algo);
	while (algo_pass < nb_algo)
	{
		handle = ft_fill_struc(argc, argv);
		if (!handle)
			ft_print_error();
		ft_fill_argv(handle);
		if (ft_is_sort(handle->a, handle->sizea) == 0)
			ft_sort_push_swap(handle, algo_pass);
		ft_add_sol(sol, handle->hack, algo_pass);
		ft_free_handle(handle);
		algo_pass++;
	}
	ft_printf("%s", ft_print_best_sol(sol, nb_algo));
	ft_free_sol(sol, nb_algo);
	return (0);
}
