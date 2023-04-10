/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 04:57:46 by astalha           #+#    #+#             */
/*   Updated: 2023/04/10 05:36:48 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	freealloc2(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr[i])
		i++;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_lstclear(t_philo **lst_philo)
{
	t_philo	*philo;

	if (!lst_philo)
		return ;
	philo = *lst_philo;
	while (philo != NULL)
	{
		free(philo);
		philo = philo->next;
	}
	*lst_philo = NULL;
}