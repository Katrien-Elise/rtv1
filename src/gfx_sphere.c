/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_sphere.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 11:37:13 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 11:01:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "gfx_object.h"
#include "gfx_intersection.h"
#include "gfx_ray.h"

t_object		make_sphere(t_vec3 p, double r, t_material mat)
{
	t_object	obj;
	t_sphere	sphere;

	obj.type = OBJ_SPHERE;
	sphere.p = p;
	sphere.r = r;
	obj.material = mat;
	obj.value.as_sphere = sphere;
	return (obj);
}

t_vec3			reflect(t_vec3 i, t_vec3 n)
{
	return (sub_vec3(i, mult_vec3(n, 2 * dot_vec3(i, n))));
}

int				gfx_ray_sphere_intersect(t_gfx_state *st, t_ray *ray, t_object *sphere, t_intersection *inter)
{
	const t_vec3	oc = sub_vec3(ray->origin, sphere->value.as_sphere.p);
	const double	b = 2 * dot_vec3(oc, ray->direction);
	const double	c = dot_vec3(oc, oc) - sphere->value.as_sphere.r * sphere->value.as_sphere.r;
	double			disc; 
	double			t0;
	double			t1;
	t_vec3			p;
	double			lum;
	t_light			light;
	t_vec3			sphere_normal;
	t_vec3			reflect_dir;
	t_rgb			col;

	disc = b * b - 4 * c;
	if (disc > 0)
	{
		disc = sqrt(disc);
		t0 = -b - disc;
		t1 = -b + disc;
		inter->t = (t0 < t1) ? t0 : t1;
		if (inter->t < 0.0001)
			return (0);
		p = add_vec3(ray->origin, mult_vec3(ray->direction, inter->t));
		inter->color = ((t_rgb){
			.r = sphere->material.color.r * 0.3,
			.g = sphere->material.color.g * 0.3,
			.b = sphere->material.color.b * 0.3
		});
		for (size_t i = 0; i < st->scene.world.light_count; i++)
		{
			sphere_normal = normalize_vec3(sub_vec3(p, sphere->value.as_sphere.p));
			light = st->scene.world.lightsources[i];
			reflect_dir = reflect(p, sphere_normal);
			col = cast_ray(st, (t_ray){
				.origin = p,
				.direction = reflect_dir
			});
			inter->color.r += col.r * 0.3;
			inter->color.g += col.g * 0.3;
			inter->color.b += col.b * 0.3;

			lum = dot_vec3(
				normalize_vec3(sub_vec3(light.p, p)),
				sphere_normal
				);
			if (lum < 0)
				continue;
			inter->color.r += sphere->material.color.r * lum * light.luminosity;
			inter->color.g += sphere->material.color.g * lum * light.luminosity;
			inter->color.b += sphere->material.color.b * lum * light.luminosity;
		}
		return (1);
	}
	return (0);
}