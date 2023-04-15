/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:09:15 by astalha           #+#    #+#             */
/*   Updated: 2023/04/15 07:20:56 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
void	serial_killer(t_philo	*lst_philo)
{
	while (lst_philo)
	{
		kill(lst_philo->pid, 9);
		lst_philo = lst_philo->next;
		if (lst_philo->id == 1)
			return ;
	}
	
}
int	init_scene(t_philo *lst_philo)
{
	int i = 0;
	lst_philo->infos->print = sem_open("/print", O_CREAT, 0644, 1);
	lst_philo->infos->forks = sem_open("/forks", O_CREAT, 0644, lst_philo->infos->n_philos);
	lst_philo->infos->all_eat = sem_open("/all_eat", O_CREAT, 0644, 0);
	lst_philo->infos->t_start = ms_time();
	while (lst_philo)
	{
			lst_philo->pid = fork();
			if (lst_philo->pid == 0)
				philo(lst_philo);
			else 
				{
					lst_philo = lst_philo->next;
					if (lst_philo->id == 1)
						break ;
				}
	}	
	waitpid(-1, NULL, 0);
	serial_killer(lst_philo);
	return(1);
}

t_philo	*set_args(t_data *infos, char **av, int ac)
{

	if (!check_input(ac, av) || !get_infos(infos, av))
		return (NULL);
	return (make_list(infos));
}

int main(int ac, char **av)
{
	t_data  infos;
	t_philo *lst_philo;

	lst_philo = set_args(&infos, av, ac);
	if (!lst_philo)
		return (0);
	sem_unlink("/print");
	sem_unlink("/forks");
	init_scene(lst_philo);
	ft_lstclear(&lst_philo);
}