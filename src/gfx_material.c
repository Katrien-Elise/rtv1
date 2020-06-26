/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_material.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 21:54:56 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/04 01:33:36 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_object.h"

t_material	mat_diffuse(t_rgb color)
{
	t_material mat;

	mat.color = color;
	mat.mat_type = E_DIFFUSE;
	mat.reflectivity = 0;
	return (mat);
}

t_material	mat_reflective(t_rgb color)
{
	t_material mat;

	mat.color = color;
	mat.mat_type = E_REFLECTIVE;
	mat.reflectivity = 0.8;
	return (mat);
}