/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_vec2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 11:00:55 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 11:01:23 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "gfx_types.h"

t_vec2			mk_vec2(double x, double y)
{
	t_vec2 p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point			demote_vec2(t_vec2 vec)
{
	return (mk_point(floor(vec.x), floor(vec.y)));
}

double			vec2_distance(t_vec2 a, t_vec2 b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}