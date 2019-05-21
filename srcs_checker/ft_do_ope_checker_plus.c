/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_ope_checker_plus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:05:58 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 19:38:28 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

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

void		ft_do_ope_checker_plus(t_check *handle, int ope)
{
	if (ope == 8)
		ft_rotate_r_checker(handle);
	else if (ope == 9)
		ft_reverse_rotate_a_checker(handle);
	else if (ope == 10)
		ft_reverse_rotate_b_checker(handle);
	else if (ope == 11)
		ft_reverse_rotate_r_checker(handle);
}
