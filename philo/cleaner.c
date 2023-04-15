/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 04:57:46 by astalha           #+#    #+#             */
/*   Updated: 2023/04/14 01:38:43 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroy(t_philo *lst_philo)
{
	pthread_mutex_destroy(&lst_philo->infos->print);
	while (lst_philo)
	{
		pthread_mutex_destroy(&lst_philo->p_fork);
		lst_philo = lst_philo->next;
		if (lst_philo->id == 1)
			break ;
	}
}

void	ft_lstclear(t_philo **lst_philo)
{
	t_philo	*philo;
	t_philo	*tmp;

	mutex_destroy(*lst_philo);
	mssleep(300);
	if (!lst_philo)
		return ;
	philo = *lst_philo;
	while (1)
	{
		if (philo->id == philo->infos->n_philos)
		{
			free(philo);
			break ;
		}
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
	*lst_philo = NULL;
}
