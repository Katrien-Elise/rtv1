/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_time.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 10:56:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 10:57:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_TIME_H
# define GFX_TIME_H

long	gfx_get_current_epoch(void);
int		gfx_get_fps(int do_tick);

#endif