/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 08:06:14 by akremer           #+#    #+#             */
/*   Updated: 2019/05/21 15:44:01 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static char	*ft_wich_ope(int ope)
{
	if (ope == 1)
		return ("sa");
	else if (ope == 2)
		return ("sb");
	else if (ope == 3)
		return ("ss");
	else if (ope == 4)
		return ("pb");
	else if (ope == 5)
		return ("pa");
	else if (ope == 6)
		return ("ra");
	else if (ope == 7)
		return ("rb");
	else if (ope == 8)
		return ("rr");
	else if (ope == 9)
		return ("rra");
	else if (ope == 10)
		return ("rrb");
	else if (ope == 11)
		return ("rrr");
	return ("prob");
}

static void	ft_print_visu(t_check *handle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < handle->sizea || j < handle->sizeb)
	{
		ft_printf("| ");
		if (i < handle->sizea)
			ft_printf("A[%d] = %-*d |",
					i, 15 - ft_nbrlen(i, 0, 10), handle->a[i]);
		else
			ft_printf("                      |");
		ft_printf("          | ");
		if (j < handle->sizeb)
			ft_printf("B[%d] = %-*d |",
					j, 15 - ft_nbrlen(j, 0, 10), handle->b[j]);
		else
			ft_printf("                      |");
		ft_printf("\n");
		i++;
		j++;
	}
	return ;
}

void		ft_visualizer(t_check *handle, int ope, int slep)
{
	int		i;

	i = 0;
	system("clear");
	ft_printf("H----------------------------------------------------------H\n");
	ft_printf("|            A          | %5s    |           B           |\n",
			ft_wich_ope(ope));
	ft_printf("H----------------------------------------------------------H\n");
	ft_print_visu(handle);
	ft_printf("H----------------------------------------------------------H\n");
	sleep(slep);
}
