/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:33:05 by hbally            #+#    #+#             */
/*   Updated: 2019/01/29 13:40:24 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpsviz.h"
#include "libpushswap.h"
#include "mlx.h"

static void		create_img(t_data *data, t_win *win, t_img *img)
{
	img->self_id = mlx_new_image(win->mlx_id, win->width, win->height);
	if (img->self_id == NULL)
		exit_window(data, win, MALLOC_ERROR);
	img->data = mlx_get_data_addr(img->self_id, &(img->bpp), &(img->line_size),
									&(img->endian));
	if (!img->data)
		exit_window(data, win, MALLOC_ERROR);
}

void			start_window(t_data *data, t_win *win)
{
	if ((win->mlx_id = mlx_init()) == NULL)
		exit_window(data, win, MALLOC_ERROR);
	win->self_id = mlx_new_window(win->mlx_id, win->width, win->height, "ps");
	if (win->self_id == NULL)
		exit_window(data, win, MALLOC_ERROR);
	create_img(data, win, &(win->img));
}
