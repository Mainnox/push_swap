/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:59:45 by akremer           #+#    #+#             */
/*   Updated: 2019/05/17 18:30:28 by akremer          ###   ########.fr       */
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
	handle->ign = 0;
	handle->progress = 0;
	handle->mid = 0;
	handle->tour = 0;
	handle->progres = ft_init_progress();
	handle->size_progres = 1;
	if (handle->size <= 250)
		handle->nbr_ok = 5;
	else
		handle->nbr_ok = 5;
	handle->low = -2147483648;
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
	free(handle);
	handle = NULL;
//	ft_memdel((void**)&handle->a);
//	ft_memdel((void**)&handle->b);
//	ft_memdel((void**)&handle->hack);
//	ft_memdel((void**)&handle);
}

static t_sol			**ft_new_t_sol(t_sol **sol)
{
	t_sol	*new;
	t_sol	*tmp;
	int		i;

	i = 1;
	tmp = *sol;
	if (!(new = (t_sol*)malloc(sizeof(t_sol))))
		return (NULL);
	if (tmp)
		while (tmp->next && i++)
			tmp = tmp->next;
	new->index = i;
	new->nb_ope = 0;
	new->sol = NULL;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		tmp = new;
	*sol = tmp;
	return (sol);
}

void					ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

static void				ft_free_sol(t_sol **sol)
{
	t_sol *tmp;
	t_sol *tmp2;

	tmp = *sol;
	while (tmp)
	{
		ft_memdel((void**)&tmp->sol);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
		tmp2 = NULL;
	}
	tmp = NULL;
	free(sol);
}

int						main(int argc, char **argv)
{
	t_push	*handle;
	t_sol	**sol;
	char	algo_pass;
	char	nb_algo;

	algo_pass = 0;
	if (!(sol = (t_sol**)malloc(sizeof(t_sol*))))
		ft_print_error();
	if (!(*sol = (t_sol*)malloc(sizeof(t_sol))))
		ft_print_error();
	sol[0]->next = NULL;
	if (argc == 1)
		return (0);
	if (argc < 10)
		nb_algo = 3;
	else
		nb_algo = 1;
	while (algo_pass < nb_algo)
	{
		handle = ft_fill_struc(argc, argv);
		if (!handle)
			ft_print_error();
		ft_fill_argv(handle);
		if (ft_is_sort(handle->a, handle->sizea) == 0)
			ft_sort_push_swap(handle, algo_pass);
//		ft_check_reduc(handle);
		if (algo_pass != 0)
			sol = ft_new_t_sol(sol);
		if (!sol)
			ft_print_error();
		ft_fill_sol(handle, sol);
		ft_free_handle(handle);
		algo_pass++;
	}
	ft_printf("%s", ft_print_the_best(sol));
	ft_free_sol(sol);
	return (0);
}
