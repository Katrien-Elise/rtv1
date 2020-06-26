/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_update.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 21:23:52 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 22:23:52 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "gfx_state.h"

void	gfx_state_update(t_gfx_state *st)
{
	int			numkeys;
	const Uint8	*keystate = SDL_GetKeyboardState(&numkeys);

	st->scene.camera.origin.x -= keystate[SDL_SCANCODE_LEFT] * 0.1;
	st->scene.camera.origin.x += keystate[SDL_SCANCODE_RIGHT] * 0.1;
	st->scene.camera.origin.z -= keystate[SDL_SCANCODE_DOWN] * 0.1;
	st->scene.camera.origin.z += keystate[SDL_SCANCODE_UP] * 0.1;
	st->scene.camera.fov += keystate[SDL_SCANCODE_EQUALS];
	st->scene.camera.fov -= keystate[SDL_SCANCODE_MINUS];
}