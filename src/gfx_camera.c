/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_camera.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 15:29:13 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 00:05:16 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_state.h"
#include "gfx_ray.h"

t_ray	make_ray(t_gfx_state *st, t_camera *camera, double x, double y)
{
	t_ray	ray;
	const double px = (2 * ((x + 0.5) / st->screen_surface->w) - 1)
		* tan(camera->fov / 2 * M_PI / 180) * st->aspect_ratio;
	const double py = (1 - 2 * ((y + 0.5) / st->screen_surface->h))
		* tan(camera->fov / 2 * M_PI / 180);
	ray.origin = (t_vec3){
		.x = camera->origin.x,
		.y = camera->origin.y,
		.z = camera->origin.z
	};
	ray.direction = normalize_vec3((t_vec3){
		.x = px,
		.y = py,
		.z = 1
	});

	return (ray);
}