/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   evt_keys.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 21:11:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 21:19:44 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void	gfx_keydown(SDL_KeyboardEvent *kbd_evt, t_gfx_state *st)
{
	if (kbd_evt->keysym.sym == SDLK_ESCAPE)
	{
		st->running = 0;
	}
}

void	gfx_keyup(SDL_KeyboardEvent *kbd_evt, t_gfx_state *st)
{
	(void)kbd_evt;
	(void)st;
}