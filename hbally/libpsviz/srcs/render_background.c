/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:02:34 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:02:40 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpsviz.h"
#include "libft.h"
#include "colors.h"

void			draw_background(t_win *win)
{
	int			i;
	int			j;
	int			max_x;
	int			max_y;
	int			color;

	max_x = win->width;
	max_y = win->height;
	color = BACKGROUND_COLOR;
	i = 0;
	while (i < max_y)
	{
		j = 0;
		while (j < max_x)
		{
			ft_memmove(&(win->img.data[i * win->img.line_size + j * 4]),
							&color, 4);
			j++;
		}
		i++;
	}
}
