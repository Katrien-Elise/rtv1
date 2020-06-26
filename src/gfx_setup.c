/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_setup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 02:00:21 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 20:26:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "gfx_state.h"

int		gfx_state_init(t_gfx_state	*st)
{
	const size_t	window_width = 1280;
	const size_t	window_height = 720;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}
	printf("Successfully initalized SDL with Video\n");
	gfx_sdl_print_version();
	st->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
	if (!st->window)
	{
		printf("Unable to create SDL window: %s\n", SDL_GetError());
		return (1);
	}
	st->screen_surface = SDL_GetWindowSurface(st->window);
	if (!st->screen_surface)
	{
		printf("Unable to get screen surface: %s\n", SDL_GetError());
		return (1);
	}
	st->aspect_ratio = st->screen_surface->w / (double)st->screen_surface->h;
	gfx_init_scene(&st->scene);
	return (0);
}