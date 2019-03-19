/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_ope.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:46:16 by akremer           #+#    #+#             */
/*   Updated: 2019/03/19 14:46:21 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_swap(int *a)
{
	int		tmp;

	if (!a[0] || !a[1])
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = a[0];
}

void		ft_rotate(int *a, int taille)
{
	int start;
	int i;

	i = 0;
	if (taille < 2)
		return ;
	start = a[0];
	while (i < taille - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[taille - 1] = start;
}

void		ft_reverse_rotate(int *a, int taille)
{
	int end;
	int i;

	i = taille - 1;
	if (taille < 2)
		return ;
	end = a[i];
	while (i > 1)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = end;
}

void		ft_push(int *a, int *b, int taille)
{
	int i;

	i = taille;
	while (i > 1)
	{
		a[i] = a[i -1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < taille - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = 0;
}
