/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:54:48 by astalha           #+#    #+#             */
/*   Updated: 2023/04/13 02:29:38 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ms_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

time_t	current_time(time_t s_time)
{
	return (ms_time() - s_time);
}

void	mssleep(time_t t_ms)
{
	time_t	time;

	time = ms_time();
	usleep(t_ms * 0.8 * 1000);
	while ((ms_time() - time) < t_ms)
		usleep(50);
}
