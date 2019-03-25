/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:45 by akremer           #+#    #+#             */
/*   Updated: 2019/03/25 07:26:13 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_push				*ft_fill_struc(int argc, char **argv)
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
	if (!(handle->hack = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	ft_bzero((void*)handle->b, handle->size);
	handle->argv = argv;
	handle->sizea = handle->size;
	handle->sizeb = 0;
	handle->nb_ope = 0;
	return (handle);
}

static void				ft_free_handle(t_push *handle)
{
	free(handle->a);
	free(handle->b);
	free(handle->hack);
	free(handle);
}

static t_sol			**ft_new_t_sol(t_sol **sol)
{
	t_sol *new;
	t_sol *tmp;

	if (!sol)
		if (!(sol = (t_sol**)malloc(sizeof(t_sol*))))
			return (NULL);
	tmp = *sol;
	if (!(new = (t_sol*)malloc(sizeof(t_sol))))
		return (NULL);
	if (!tmp)
	{
		tmp = new;
		return (sol);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	*sol = tmp;
	return(sol);
}

void					ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int						main(int argc, char **argv)
{
	t_push	*handle;
	t_sol	**sol;

	sol = NULL;
	if (argc == 1)
		return (0);
	handle = ft_fill_struc(argc, argv);
	if (!handle)
		ft_print_error();
	ft_fill_argv(handle);
	if (ft_is_sort(handle) == 0)
		ft_sort_push_swap(handle);
	ft_check_reduc(handle);
	sol = ft_new_t_sol(sol);
	if (!sol)
		ft_print_error();
	ft_printf("%s", handle->hack);
	ft_free_handle(handle);
	return (0);
}
