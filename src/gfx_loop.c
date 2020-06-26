/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_loop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 02:14:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 21:23:47 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "gfx_state.h"
#include "event.h"

void	gfx_state_loop(t_gfx_state *st)
{
	SDL_Event	event;

	while (st->running)
	{
		 while (SDL_PollEvent(&event))
		 {
			if (event.type == SDL_QUIT)
				st->running = 0;
			if (event.type == SDL_KEYDOWN)
				gfx_keydown(&event.key, st);
			if (event.type == SDL_KEYUP)
				gfx_keyup(&event.key, st);
		}
		gfx_state_update(st);
		gfx_state_render(st);
	}
}