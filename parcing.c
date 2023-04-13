/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:31:43 by astalha           #+#    #+#             */
/*   Updated: 2023/04/13 06:30:04 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_infos(t_data *infos, char **av)
{
	infos->n_philos = ft_atoi(av[1]);
	infos->ttd = ft_atoi(av[2]);
	infos->tte = ft_atoi(av[3]);
	infos->tts = ft_atoi(av[4]);
	if (av[5])
		infos->meals = ft_atoi(av[5]);
	else
		infos->meals = -1;
	if (!check_infos(infos))
		return (0);
	return (1);
}

void	print_err(void)
{
	printf("Usage: ./philo [num_of_philos] [time_to_die] "
		"[time_to_eat] [time_to_sleep] [optional: num_of_times_to_eat]\n");
	return ;
}

int	check_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 4 || ac > 6)
		return (print_err(), 0);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
		{
			print_err();
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_infos(t_data *infos)
{
	if (infos->n_philos <= 0 || infos->n_philos > 200)
		return (printf("Usage : [num_of_philos] should be [0->200]\n"), 0);
	if (infos->ttd <= 0 || infos->tte <= 0 || infos->tts <= 0)
		return (printf("Usage : [time] should be > 0\n"), 0);
	if (infos->meals == 0 || infos->meals < -1)
		return (printf("Usage : [num_of_times_to_eat] should be > 0\n"), 0);
	return (1);
}

t_philo	*make_list(t_data *infos)
{
	t_philo	*lst_philo;
	t_philo	*new;
	t_philo	*last;
	int		i;

	i = 0;
	lst_philo = NULL;
	while (i < infos->n_philos)
	{
		new = ft_lstnew(i + 1);
		if (!new)
			print_err();
		new ->infos = infos;
		ft_lstadd_back(&lst_philo, new);
		i++;
	}
	last = ft_lstlast(lst_philo);
	last->next = lst_philo;
	return (lst_philo);
}
