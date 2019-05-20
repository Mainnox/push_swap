/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:55:51 by hbally            #+#    #+#             */
/*   Updated: 2019/04/08 13:02:14 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libpushswap.h"
#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_data		data;

	ft_bzero(&data, sizeof(t_data));
	get_options(&data, argc, argv, "usage : push_swap [numbers]\n");
	stack_get(&data, &(data.args));
	cmd_loadindex(&data);
	solver(&data, &(data.a), &(data.b));
	cmd_print(&(data.cmds));
	clean_exit(NO_ERROR, &data);
	return (0);
}
