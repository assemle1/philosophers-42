/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:33:53 by astalha           #+#    #+#             */
/*   Updated: 2023/04/16 02:19:09 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *arg)
{
	time_t		time;
	t_philo		*lst_philo;

	lst_philo = (t_philo *)(arg);
	while (1)
	{
		sem_wait(lst_philo->infos->print);
		time = current_time(lst_philo->infos->t_start) - lst_philo->lte;
		sem_post(lst_philo->infos->print);
		if (time > lst_philo->infos->ttd)
		{
			sem_wait(lst_philo->infos->print);
			printf("%ld %d died\n",
				current_time(lst_philo->infos->t_start), lst_philo->id);
			exit(0);
		}
		usleep(100);
	}
	return (NULL);
}

void	*philo(void *arg)
{
	t_philo		*lst_philo;

	lst_philo = (t_philo *)(arg);
	if (pthread_create(&lst_philo->t_id, NULL,
			check_death, (void *)lst_philo))
		return (printf("Error System : Failed to create thread\n"),
			exit(0), NULL);
	if (lst_philo->id % 2)
		usleep(200);
	while (1)
	{
		if (lst_philo->n_meals == lst_philo->infos->meals)
		{
			sem_post(lst_philo->infos->print);
			exit(1);
		}
		sem_wait(lst_philo->infos->forks);
		forks(lst_philo, "right");
		sem_wait(lst_philo->infos->forks);
		forks(lst_philo, "left");
		is_eating(lst_philo);
		is_sleeping(lst_philo);
		is_thinking(lst_philo);
	}
	return (NULL);
}
