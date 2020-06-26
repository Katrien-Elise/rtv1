/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_prim.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 10:38:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 10:53:54 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stddef.h>

#include "gfx_image.h"

void	gfx_put_pixel(SDL_Surface *surface, int x, int y, int color)
{
	uint32_t	*pixels_as_i32;
	
	pixels_as_i32 = surface->pixels;
	if (x < 0 || x > surface->w
	 || y < 0 || y > surface->h)
	 	return ;
	pixels_as_i32[x + y * surface->w] = color;
}

void	gfx_fill_surface(SDL_Surface *surface, int color)
{
	int i = 0;
	while (i < surface->w * surface->h)
	{
		gfx_put_pixel(surface, i % surface->w, i / surface->w, color);
		i++;
	}
}