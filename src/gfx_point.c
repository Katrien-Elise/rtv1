/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_point.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 11:01:59 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 11:02:42 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_types.h"

t_point			mk_point(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

t_point			point_add(t_point a, t_point b)
{
	return (mk_point(a.x + b.x, a.y + b.y));
}

t_line			mk_line(t_point a, t_point b)
{
	t_line l;

	l.a = a;
	l.b = b;
	return (l);
}