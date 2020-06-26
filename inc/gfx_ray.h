/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_ray.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 11:41:42 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 10:58:26 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_RAY_H
# define GFX_RAY_H

# include "gfx_types.h"
# include "gfx_object.h"
# include "gfx_intersection.h"
# include "gfx_state.h"
# include "gfx_camera.h"

typedef	struct	s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}				t_ray;

int				gfx_ray_intersect(t_gfx_state *st, t_ray *ray, t_object *object, t_intersection *inter);
int				gfx_ray_sphere_intersect(t_gfx_state *st, t_ray *ray, t_object *sphere, t_intersection *inter);
int				gfx_ray_plane_intersect(t_gfx_state *st, t_ray *ray, t_object *plane, t_intersection *inte);
t_ray			make_ray(t_gfx_state *st, t_camera *camera, double x, double y);
t_rgb			cast_ray(t_gfx_state *st, t_ray ray);

#endif