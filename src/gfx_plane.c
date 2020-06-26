/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_plane.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 13:04:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 10:57:55 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "gfx_object.h"
#include "gfx_types.h"
#include "gfx_ray.h"
#include "gfx_intersection.h"

t_object		make_plane(t_vec3 p, t_vec3 n, t_material mat)
{
	t_object	obj;
	t_plane		plane;

	obj.type = OBJ_PLANE;
	plane.p = p;
	plane.n = n;
	obj.material = mat;
	obj.value.as_plane = plane;
	return (obj);
}

int				gfx_ray_plane_intersect(t_gfx_state *st, t_ray *ray, t_object *plane, t_intersection *inter)
{
	(void)ray;
	(void)plane;
	(void)inter;
	const double	dot_dn = dot_vec3(ray->direction, plane->value.as_plane.n);
	double			t;
	double			lum;
	t_vec3			p;

	if (dot_dn == 0.0)
	{
		return (0);
	}
	t = dot_vec3(sub_vec3(plane->value.as_plane.p, ray->origin), plane->value.as_plane.n) / dot_dn;
	if (t < 0.0001)
	{
		return (0);
	}
	p = add_vec3(ray->origin, mult_vec3(ray->direction, inter->t));
	inter->color = ((t_rgb){
		.r = plane->material.color.r * 0.3,
		.g = plane->material.color.g * 0.3,
		.b = plane->material.color.b * 0.3
	});
	(void)lum;
	for (size_t i = 0; i < st->scene.world.light_count; i++)
	{
		lum = dot_vec3(
			normalize_vec3(sub_vec3(st->scene.world.lightsources[i].p, p)),
			plane->value.as_plane.n);
		if (lum < 0.01)
			continue;
		inter->color.r += plane->material.color.r * fmin(lum, 1) * 0.7;
		inter->color.g += plane->material.color.g * fmin(lum, 1) * 0.7;
		inter->color.b += plane->material.color.b * fmin(lum, 1) * 0.7;
	}
	inter->t = t;
	return (1);
}