/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:33:53 by astalha           #+#    #+#             */
/*   Updated: 2023/04/15 07:21:48 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	finished(t_philo *lst_philo)
{
	int	i;
	int	meals;

	i = 0;
	while (lst_philo)
	{
		sem_wait(lst_philo->infos->print);
		meals = lst_philo->n_meals;
		sem_post(lst_philo->infos->print);
		if (meals == lst_philo->infos->meals)
			i++;
		if (i == lst_philo->infos->n_philos)
			return (1);
		if (lst_philo->id == 1)
			break ;
		lst_philo = lst_philo->next;
	}
	return (0);
}

void	*check_death(void *arg)
{
	time_t	time;
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
			exit(1);
		}
		if (finished(lst_philo))
			break ;
	usleep(100);
	}
	return (NULL);
}

void	*philo(void *arg)
{
	t_philo		*lst_philo;

	lst_philo = (t_philo *)(arg);
	pthread_create(&lst_philo->t_id, NULL, check_death, (void	*)lst_philo);
	pthread_detach(lst_philo->t_id);
	while (1)
	{
		if (lst_philo->n_meals == lst_philo->infos->meals)
			return NULL;
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
