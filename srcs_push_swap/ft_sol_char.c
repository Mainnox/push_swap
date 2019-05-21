/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sol_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:33:05 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 11:40:03 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char		**ft_init_sol(char nb_algo)
{
	char	**sol;

	if (nb_algo == 1)
	{
		if (!(sol = (char**)malloc(sizeof(char*) * 1)))
			ft_print_error();
		*sol = NULL;
	}
	if (nb_algo == 4)
	{
		if (!(sol = (char**)malloc(sizeof(char*) * 4)))
			ft_print_error();
		*sol = NULL;
	}
	return (sol);
}

void		ft_add_sol(char **sol, char *hack, char algo_pass)
{
	if (!(sol[algo_pass] = (char*)malloc(sizeof(char) * ft_strlen(hack))))
		ft_print_error();
	ft_strcpy(sol[algo_pass], hack);
}

char		*ft_print_best_sol(char **sol, char nb_algo)
{
	char	i;
	int		j;
	int		low;
	int		ret;

	low = 2147483647;
	i = 0;
	ret = 0;
	while (i < nb_algo)
	{
		j = ft_strcount(sol[i], '\n');
		if (low > j)
		{
			low = j;
			ret = i;
		}
		i++;
	}
	return (sol[ret]);
}

void		ft_free_sol(char **sol, char nb_algo)
{
	free(sol[0]);
	sol[0] = NULL;
	if (nb_algo > 1)
	{
		free(sol[1]);
		sol[1] = NULL;
		free(sol[2]);
		sol[2] = NULL;
		free(sol[3]);
		sol[3] = NULL;
	}
	free(sol);
}
