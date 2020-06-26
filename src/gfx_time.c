/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 10:56:13 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/03 10:57:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "gfx_time.h"

long	gfx_get_current_epoch(void)
{
	long			ns;
	time_t			s;
	struct timespec	spec;

	clock_gettime(CLOCK_REALTIME, &spec);
	s = spec.tv_sec;
	ns = spec.tv_nsec;
	return (s * 1000 + ns / 1000000);
}

int		gfx_get_fps(int do_tick)
{
	static int	frames;
	static int	preserved_frames;
	static long	last_time;
	long		curr_time;

	if (do_tick)
		frames++;
	curr_time = gfx_get_current_epoch();
	if (last_time + 1000 < curr_time)
	{
		preserved_frames = frames;
		frames = 0;
		last_time = curr_time;
	}
	return (preserved_frames);
}