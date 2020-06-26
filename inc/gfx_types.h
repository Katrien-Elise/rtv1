/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_types.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 10:58:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 15:15:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_TYPES_H
# define GFX_TYPES_H

/*
** gfx_types.h
** ---------------------
** This file declares all of the types
** and functions that relate to
** primitve types.
*/

# define GFX_P_ORIGIN (mk_point(0, 0))
# define GFX_V2_ORIGIN (mk_vec2(0, 0))
# define GFX_V3_ORIGIN (mk_vec3(0, 0, 0))

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

t_point			mk_point(int x, int y);
t_point			point_add(t_point a, t_point b);

typedef struct	s_vec2
{
	double x;
	double y;
}				t_vec2;

t_vec2			mk_vec2(double x, double y);
double			vec2_distance(t_vec2 a, t_vec2 b);

/*
** Same as point, but for dimensions
*/
typedef struct	s_dimensions
{
	int width;
	int height;
}				t_dimensions;

t_dimensions	mk_dimensions(int width, int height);

/*
** Demotes a vec2 to a point, removing
** decimal information.
*/
t_point			demote_vec2(t_vec2 vec);

typedef struct	s_line
{
	t_point a;
	t_point b;
}				t_line;

t_line			mk_line(t_point a, t_point b);

typedef struct	s_vec3
{
	double x;
	double y;
	double z;
}				t_vec3;

t_vec3			mk_vec3(double x, double y, double z);
t_vec3			add_vec3(t_vec3 a, t_vec3 b);
t_vec3			sub_vec3(t_vec3 a, t_vec3 b);
t_vec3			normalize_vec3(t_vec3 v);
t_vec3			mult_vec3(t_vec3 v, double mag);
double			dot_vec3(t_vec3 v, t_vec3 w);
double			mag2_vec3(t_vec3 v);
t_vec3			cross_vec3(t_vec3 v, t_vec3 w);

#endif