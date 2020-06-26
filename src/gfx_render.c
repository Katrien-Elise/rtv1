/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_render.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 10:23:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 01:40:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

#include "gfx_state.h"
#include "gfx_time.h"
#include "gfx_intersection.h"
#include "gfx_image.h"
#include "gfx_ray.h"
#include "gfx_color.h"
#include "gfx_math.h"


#include <assert.h>

t_rgb	cast_ray(t_gfx_state *st, t_ray ray)
{
	t_intersection	inter;
	t_intersection	intersections[100] = {};
	t_intersection	*closest;
	size_t			ic;

	ic = 0;
	for (size_t i = 0; i < st->scene.world.obj_count; i++)
	{
		if (gfx_ray_intersect(&st->scene, &ray, &st->scene.world.objects[i], &inter))
		{
			ft_memcpy(&intersections[ic], &inter, sizeof(t_intersection));
			ic++;
		}
	}
	if (ic == 0)
		return ((t_rgb){.r=0,.g=0,.b=0});
	closest = &intersections[0];
	for (size_t i = 0; i < ic; i++)
	{
		if (closest->t > intersections[i].t)
			closest = &intersections[i];
	}
	return (closest->color);
}

// static t_rgb	average_color(t_rgb old, double amt, t_rgb new)
// {
// 	return ((t_rgb){
// 		.r = (old.r * amt + new.r) / (amt + 1),
// 		.g = (old.g * amt + new.g) / (amt + 1),
// 		.b = (old.b * amt + new.b) / (amt + 1)
// 	});
// }

void		gfx_state_render(t_gfx_state *st)
{
	t_rgb		color;
	size_t		i;
	const int	fps = gfx_get_fps(1);
	static double	avg_fps;

	avg_fps = (avg_fps * 100 + fps) / 101;

	printf("Avg fps %lf\n", avg_fps);
	int res = gfx_lerp(avg_fps, 60, 1, 1, 16);
	for (int x = 0; x < st->screen_surface->w; x += res)
	{
		for (int y = 0; y < st->screen_surface->h; y += res)
		{
			i = 1;
			color = cast_ray(st, make_ray(st, &st->scene.camera, x, y));
			color = average_color(color, i++, cast_ray(st, make_ray(st, &st->scene.camera, x - 0.5 * res, y)));
			color = average_color(color, i++, cast_ray(st, make_ray(st, &st->scene.camera, x + 0.5 * res, y)));
			color = average_color(color, i++, cast_ray(st, make_ray(st, &st->scene.camera, x, y + 0.5 * res)));
			color = average_color(color, i++, cast_ray(st, make_ray(st, &st->scene.camera, x, y - 0.5 * res)));
			for (int i = 0; i < res; i++)
				for (int j = 0; j < res; j++)
					gfx_put_pixel(st->screen_surface, x + i, y + j, gfx_color_from_rgb(color));
		}
	}
	SDL_UpdateWindowSurface(st->window);
}