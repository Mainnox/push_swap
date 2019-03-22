/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:30:53 by akremer           #+#    #+#             */
/*   Updated: 2019/03/20 16:43:45 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			main(int argc, char **argv)
{
	t_push *handle;

	if (argc == 1)
		return (0);
	handle = ft_fill_struc(argc, argv);
	if (!handle)
		ft_print_error();
	ft_fill_argv(handle);
	// while (ret = gnl(0, &line) > 0)
	// {
	//	traitement;
	//	pas de stockage
	//	et tout benef
	// }
	while (42)
	{
		if(get_next_line(0, handle->gnl) <= 0)
			break ;
	}
	ft_free_handle(handle);
	return (0);
}
