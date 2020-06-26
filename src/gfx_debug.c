/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_debug.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 02:06:17 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 02:13:14 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "gfx_state.h"

void	gfx_sdl_print_version(void)
{
	SDL_version v;
	SDL_GetVersion(&v);

	printf("Version: %d.%d.%d\n", v.major, v.minor, v.patch);
}