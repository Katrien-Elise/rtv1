/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_cleanup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 02:09:39 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 10:26:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "gfx_state.h"

void	gfx_state_cleanup(t_gfx_state *st)
{
	SDL_DestroyWindow(st->window);
	SDL_Quit();
}