/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:33:53 by astalha           #+#    #+#             */
/*   Updated: 2023/04/14 01:19:53 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	finished(t_philo *lst_philo)
{
	int	i;
	int	meals;

	i = 0;
	while (lst_philo)
	{
		pthread_mutex_lock(&lst_philo->infos->print);
		meals = lst_philo->n_meals;
		pthread_mutex_unlock(&lst_philo->infos->print);
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

void	check_death(t_philo *philo)
{
	time_t	time;

	while (philo)
	{
		pthread_mutex_lock(&philo->infos->print);
		time = current_time(philo->infos->t_start) - philo->lte;
		pthread_mutex_unlock(&philo->infos->print);
		if (time > philo->infos->ttd)
		{
			pthread_mutex_lock(&philo->infos->print);
			printf("%ld %d died\n",
				current_time(philo->infos->t_start), philo->id);
			break ;
		}
		if (finished(philo))
			break ;
	philo = philo->next;
	}
}

void	*philo(void *arg)
{
	int			f;
	t_philo		*lst_philo;

	lst_philo = (t_philo *)(arg);
	f = 1;
	if (lst_philo->id % 2)
		usleep(100);
	while (1)
	{
		if (lst_philo->n_meals == lst_philo->infos->meals)
			break ;
		pthread_mutex_lock(&lst_philo->p_fork);
		forks(lst_philo, "right");
		pthread_mutex_lock(&lst_philo->next->p_fork);
		forks(lst_philo, "left");
		is_eating(lst_philo);
		is_sleeping(lst_philo);
		is_thinking(lst_philo);
	}
	return (NULL);
}
