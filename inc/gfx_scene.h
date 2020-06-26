/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_scene.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 11:12:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 22:36:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_SCENE_H
# define GFX_SCENE_H

# include "gfx_camera.h"
# include "gfx_object.h"
# include "gfx_light.h"

typedef struct	s_world
{
	t_object	*objects;
	size_t		obj_count;

	t_light		*lightsources;
	size_t		light_count;
}				t_world;

typedef	struct	s_camera
{
	t_vec3	origin;
	t_vec3	rotation;
	double	fov;
}				t_camera;

typedef struct	s_scene
{
	t_world		world;
	t_camera	camera;
}				t_scene;

void			gfx_init_scene(t_scene *scene);

#endif