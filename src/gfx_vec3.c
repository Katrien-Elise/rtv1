/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_vec3.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 10:59:39 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 19:04:28 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "gfx_types.h"

t_vec3	mk_vec3(double x, double y, double z)
{
	t_vec3 v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	add_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3 n;

	n.x = a.x + b.x;
	n.y = a.y + b.y;
	n.z = a.z + b.z;
	return (n);
}

t_vec3	sub_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3 n;

	n.x = a.x - b.x;
	n.y = a.y - b.y;
	n.z = a.z - b.z;
	return (n);
}

t_vec3	normalize_vec3(t_vec3  v)
{
	const double	magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	return ((t_vec3) {
		.x = v.x / magnitude,
		.y = v.y / magnitude,
		.z = v.z / magnitude
	});
}

t_vec3	mult_vec3(t_vec3 v, double mag)
{
	return ((t_vec3) {
		.x = v.x * mag,
		.y = v.y * mag,
		.z = v.z * mag
	}); 
}

double	dot_vec3(t_vec3	v, t_vec3 w)
{
	return (v.x * w.x + v.y * w.y + v.z * w.z);
}

double	mag2_vec3(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vec3	cross_vec3(t_vec3 v, t_vec3 w)
{
	return ((t_vec3){
		.x = v.y * w.z - v.z * w.y,
		.y = v.z * w.x - v.x * w.z,
		.z = v.x * w.y - v.y * w.x
	});
}	