/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:36:53 by astalha           #+#    #+#             */
/*   Updated: 2023/04/13 02:36:53 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_scene(t_philo *lst_philo)
{
	lst_philo->infos->t_start = ms_time();
	while (lst_philo)
	{
		if (pthread_create(&lst_philo->t_id, NULL, philo, (void *)lst_philo))
			return (printf("System Error\n"), 0);
		lst_philo = lst_philo->next;
		if (lst_philo->id == 1)
			break ;
	}
	check_death(lst_philo);
	while (lst_philo)
	{
		pthread_detach(lst_philo->t_id);
		lst_philo = lst_philo->next;
		if (lst_philo->id == 1)
			break ;
	}
	return (1);
}

t_philo	*set_args(t_data *infos, char **av, int ac)
{
	if (!check_input(ac, av) || !get_infos(infos, av))
		return (NULL);
	return (make_list(infos));
}

int	main(int ac, char **av)
{
	t_data	infos;
	t_philo	*lst_philo;

	lst_philo = set_args(&infos, av, ac);
	if (!lst_philo)
		return (0);
	if (pthread_mutex_init(&infos.print, NULL) != 0)
		return (printf("System Error\n"), 0);
	init_scene(lst_philo);
	ft_lstclear(&lst_philo);
}
