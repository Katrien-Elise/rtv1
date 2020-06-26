/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_object.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 11:09:19 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 01:33:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_OBJECT_H
# define GFX_OBJECT_H

# include "gfx_types.h"
# include "gfx_color.h"

typedef struct	s_sphere
{
	t_vec3	p;
	double	r;
}				t_sphere;

typedef struct	s_plane
{
	t_vec3	p;
	t_vec3	n;
}				t_plane;

typedef enum	e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
}				t_object_type;

typedef union	u_object_value
{
	t_sphere	as_sphere;
	t_plane		as_plane;
}				t_object_value;

typedef enum	e_material_type
{
	E_DIFFUSE,
	E_REFLECTIVE,
}				t_material_type;

typedef struct	s_material
{
	double			reflectivity;
	t_rgb			color;
	t_material_type	mat_type;
}				t_material;

typedef struct	s_object
{
	t_object_type	type;
	t_object_value	value;
	t_material		material;
}				t_object;

t_object		make_sphere(t_vec3 p, double r, t_material mat);
t_object		make_plane(t_vec3 p, t_vec3 n, t_material mat);
t_material		mat_diffuse(t_rgb color);
t_material		mat_reflective(t_rgb color);


#endif