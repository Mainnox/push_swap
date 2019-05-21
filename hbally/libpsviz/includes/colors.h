/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 21:09:10 by hbally            #+#    #+#             */
/*   Updated: 2019/02/08 10:05:28 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define START_COLOR 0x64b8d1
# define COLOR_1 0x14719f
# define END_COLOR 0x0f3860

# define BACKGROUND_COLOR 0x212121
# define MOVE_COLOR 0xd43f28
# define TEXT_COLOR 0xF5F5F5

typedef struct		s_color
{
	int16_t			r;
	int16_t			g;
	int16_t			b;
}					t_color;

typedef struct		s_delta
{
	double			r;
	double			g;
	double			b;
}					t_delta;

#endif
