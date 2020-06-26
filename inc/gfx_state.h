/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_state.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 01:56:45 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 21:24:10 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_STATE_H
# define GFX_STATE_H

# include <SDL2/SDL.h>

# include "gfx_scene.h"

typedef struct	s_gfx_state
{
	SDL_Window	*window;
	SDL_Surface	*screen_surface;

	double		aspect_ratio;
	int			running;

	t_scene		scene;

	SDL_Keycode	keys_down[512];
}				t_gfx_state;

void	gfx_state_cleanup(t_gfx_state *st);
int		gfx_state_init(t_gfx_state *st);
void	gfx_state_loop(t_gfx_state *st);
void	gfx_state_render(t_gfx_state *st);
void	gfx_state_update(t_gfx_state *st);
void	gfx_sdl_print_version(void);

#endif