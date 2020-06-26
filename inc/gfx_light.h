/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_light.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 22:35:06 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 23:36:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_LIGHT_H
# define GFX_LIGHT_H

# include "gfx_color.h"
# include "gfx_types.h"

typedef struct	s_light
{
	t_vec3	p;
	t_rgb	color;
	double	luminosity;
}				t_light;

#endif