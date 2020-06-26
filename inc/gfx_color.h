/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_color.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 10:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 00:32:28 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_COLOR_H
# define GFX_COLOR_H

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

typedef struct	s_hsl
{
	double h;
	double s;
	double l;
}				t_hsl;

int		gfx_color(int r, int g, int b, int a);
t_rgb	gfx_hsl2rgb(t_hsl hsl);
t_rgb	mk_rgb(unsigned char r, unsigned char g, unsigned char b);
t_hsl	mk_hsl(double h, double s, double l);
int		gfx_color_from_rgb(t_rgb rgb);
t_rgb	average_color(t_rgb old, double amt, t_rgb new);

# define COLOR_WHITE	(mk_rgb(255, 255, 255))
# define COLOR_RED		(mk_rgb(255, 0, 0))
# define COLOR_GREEN	(mk_rgb(0, 255, 0))
# define COLOR_BLUE		(mk_rgb(0, 0, 255))

#endif