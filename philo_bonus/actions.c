/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:24:05 by astalha           #+#    #+#             */
/*   Updated: 2023/04/15 07:05:15 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	is_eating(t_philo *lst_philo)
{
	sem_wait(lst_philo->infos->print);
	lst_philo->lte = ms_time() - lst_philo->infos->t_start;
	lst_philo->n_meals++;
	printf("%ld %d is eating\n",
		current_time(lst_philo->infos->t_start), lst_philo->id);
	sem_post(lst_philo->infos->print);
	mssleep(lst_philo->infos->tte);
	sem_post(lst_philo->infos->forks);
	sem_post(lst_philo->infos->forks);
}

void	forks(t_philo *lst_philo, char *fork)
{
	sem_wait(lst_philo->infos->print);
	printf("%ld %d has taken the %s fork\n",
		current_time(lst_philo->infos->t_start), lst_philo->id, fork);
	sem_post(lst_philo->infos->print);
}

void	is_sleeping(t_philo *lst_philo)
{
	sem_wait(lst_philo->infos->print);
	printf("%ld %d is sleeping\n",
		current_time(lst_philo->infos->t_start), lst_philo->id);
	sem_post(lst_philo->infos->print);
	mssleep(lst_philo->infos->tts);
}

void	is_thinking(t_philo *lst_philo)
{
	sem_wait(lst_philo->infos->print);
	printf("%ld %d is thinking\n",
		current_time(lst_philo->infos->t_start), lst_philo->id);
	sem_post(lst_philo->infos->print);
}
