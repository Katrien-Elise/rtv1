/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_math.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 19:42:37 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 19:44:43 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_math.h"

double	gfx_lerp(double in, double il, double ih, double ol, double oh)
{
	return (((in - il) / (ih - il)) * (oh - ol) + ol);
}