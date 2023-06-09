/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:24:05 by astalha           #+#    #+#             */
/*   Updated: 2023/04/14 00:52:02 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philo *lst_philo)
{
	pthread_mutex_lock(&lst_philo->infos->print);
	lst_philo->lte = ms_time() - lst_philo->infos->t_start;
	lst_philo->n_meals++;
	printf("%ld %d is eating\n",
		current_time(lst_philo->infos->t_start), lst_philo->id);
	pthread_mutex_unlock(&lst_philo->infos->print);
	mssleep(lst_philo->infos->tte);
	pthread_mutex_unlock(&lst_philo->p_fork);
	pthread_mutex_unlock(&lst_philo->next->p_fork);
}

void	forks(t_philo *lst_philo, char *fork)
{
	pthread_mutex_lock(&lst_philo->infos->print);
	printf("%ld %d has taken the %s fork\n",
		current_time(lst_philo->infos->t_start), lst_philo->id, fork);
	pthread_mutex_unlock(&lst_philo->infos->print);
}

void	is_sleeping(t_philo *lst_philo)
{
	pthread_mutex_lock(&lst_philo->infos->print);
	printf("%ld %d is sleeping\n",
		current_time(lst_philo->infos->t_start), lst_philo->id);
	pthread_mutex_unlock(&lst_philo->infos->print);
	mssleep(lst_philo->infos->tts);
}

void	is_thinking(t_philo *lst_philo)
{
	pthread_mutex_lock(&lst_philo->infos->print);
	printf("%ld %d  is thinking\n",
		current_time(lst_philo->infos->t_start), lst_philo->id);
	pthread_mutex_unlock(&lst_philo->infos->print);
}
