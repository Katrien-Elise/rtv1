/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rtv1.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 01:26:04 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 02:15:40 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "gfx_state.h"


int	main(void)
{
	t_gfx_state	st;

	gfx_state_init(&st);
	st.running = 1;
	gfx_state_loop(&st);
	gfx_state_cleanup(&st);
	return (0);
}