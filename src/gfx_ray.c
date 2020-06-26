/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_ray.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 11:58:00 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 10:57:34 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_object.h"
#include "gfx_types.h"
#include "gfx_ray.h"
#include "gfx_intersection.h"

int			gfx_ray_intersect(t_gfx_state *st, t_ray *ray, t_object *object, t_intersection *inter)
{
	if (object->type == OBJ_SPHERE)
		return (gfx_ray_sphere_intersect(st, ray, object, inter));
	if (object->type == OBJ_PLANE)
		return (gfx_ray_plane_intersect(st, ray, object, inter));
	return (0);
}