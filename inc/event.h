/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 21:11:44 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 21:18:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include <SDL2/SDL.h>
# include "gfx_state.h"

void	gfx_keydown(SDL_KeyboardEvent *kbd_evt, t_gfx_state *st);
void	gfx_keyup(SDL_KeyboardEvent *kbd_evt, t_gfx_state *st);

#endif