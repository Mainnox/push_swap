/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_ope_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:19:02 by akremer           #+#    #+#             */
/*   Updated: 2019/03/23 21:29:47 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static int		ft_check_ope_checker(t_check *handle)
{
	if (ft_strcmp(handle->gnl[0], "sa\n") == 0)
		return (1);
	else if (ft_strcmp(handle->gnl[0], "sb\n") == 0)
		return (2);
	else if (ft_strcmp(handle->gnl[0], "ss\n") == 0)
		return (3);
	else if (ft_strcmp(handle->gnl[0], "pa\n") == 0)
		return (4);
	else if (ft_strcmp(handle->gnl[0], "pb\n") == 0)
		return (5);
	else if (ft_strcmp(handle->gnl[0], "ra\n") == 0)
		return (6);
	else if (ft_strcmp(handle->gnl[0], "rb\n") == 0)
		return (7);
	else if (ft_strcmp(handle->gnl[0], "rr\n") == 0)
		return (8);
	else if (ft_strcmp(handle->gnl[0], "rra\n") == 0)
		return (9);
	else if (ft_strcmp(handle->gnl[0], "rrb\n") == 0)
		return (10);
	else if (ft_strcmp(handle->gnl[0], "rrr\n") == 0)
		return (11);
	else
		return (0);
}

static void	ft_swap_s_checker(t_check *handle)
{
	ft_swap_a_checker(handle);
	ft_swap_b_checker(handle);
}

static void	ft_rotate_r_checker(t_check *handle)
{
	ft_rotate_a_checker(handle);
	ft_rotate_b_checker(handle);
}

static void	ft_reverse_rotate_r_checker(t_check *handle)
{
	ft_reverse_rotate_a_checker(handle);
	ft_reverse_rotate_b_checker(handle);
}

void		ft_do_op_checker(t_check *handle)
{
	int ope;

	ope = ft_check_ope_checker(handle);
	if (ope == 1)
		ft_swap_a_checker(handle);
	else if (ope == 2)
		ft_swap_b_checker(handle);
	else if (ope == 3)
		ft_swap_s_checker(handle);
	else if (ope == 4)
		ft_push_a_checker(handle);
	else if (ope == 5)
		ft_push_b_checker(handle);
	else if (ope == 6)
		ft_rotate_a_checker(handle);
	else if (ope == 7)
		ft_rotate_b_checker(handle);
	else if (ope == 8)
		ft_rotate_r_checker(handle);
	else if (ope == 9)
		ft_reverse_rotate_a_checker(handle);
	else if (ope == 10)
		ft_reverse_rotate_b_checker(handle);
	else if (ope == 11)
		ft_reverse_rotate_r_checker(handle);
	else
		ft_print_error_checker();
}
