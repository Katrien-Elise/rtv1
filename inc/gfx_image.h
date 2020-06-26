/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_image.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 10:39:16 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 10:54:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_IMAGE_H
# define GFX_IMAGE_H

# include <SDL2/SDL.h>

void	gfx_put_pixel(SDL_Surface *surface, int x, int y, int color);
void	gfx_fill_surface(SDL_Surface *surface, int color);

#endif