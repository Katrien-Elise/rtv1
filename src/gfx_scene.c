/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_scene.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 11:19:25 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 00:48:12 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "gfx_scene.h"
#include "gfx_types.h"

static void	gfx_init_world(t_world *world)
{
	world->objects = (t_object*)malloc(sizeof(t_object) * 100);

	/* Temporarliy hardcode objects */
	world->obj_count = 4;
	world->objects[0] = make_plane(mk_vec3(0, -4, 1), mk_vec3(0, 1, 0), mat_diffuse((t_rgb){
		.r = 120,
		.g = 120,
		.b = 120
	}));
	world->objects[1] = make_sphere(mk_vec3(0, 0, 4), 1, mat_diffuse(COLOR_RED));
	world->objects[2] = make_sphere(mk_vec3(2, 0, 2), 0.5, mat_diffuse(COLOR_GREEN));
	world->objects[3] = make_sphere(mk_vec3(2, 0, 10), 5, mat_diffuse(COLOR_GREEN));

	world->lightsources = (t_light*)malloc(sizeof(t_light) * 10);
	world->light_count = 2;
	world->lightsources[0] = ((t_light){
		.p = mk_vec3(0, 100, 0),
		.color = COLOR_WHITE,
		.luminosity = 0.5
	});
	world->lightsources[1] = ((t_light){
		.p = mk_vec3(0, 10, 20),
		.color = COLOR_WHITE,
		.luminosity = 0.2
	});
}

static void	gfx_init_camera(t_camera *cam, t_vec3 origin, double fov)
{
	cam->origin = origin;
	cam->fov = fov;
	cam->rotation = mk_vec3(0, 0, 0);
}

void	gfx_init_scene(t_scene *scn)
{
	gfx_init_camera(&scn->camera, mk_vec3(0, 0, 0), 90);
	gfx_init_world(&scn->world);
}