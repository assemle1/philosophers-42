/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:09:34 by astalha           #+#    #+#             */
/*   Updated: 2023/04/16 02:13:25 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_data
{
	sem_t			*print;
	sem_t			*forks;
	sem_t			*all_eat;
	int				n_philos;
	time_t			ttd;
	time_t			tte;
	time_t			tts;
	int				meals;
	time_t			t_start;
}									t_data;

typedef struct s_philo
{
	int						id;
	int						n_meals;
	t_data					*infos;
	time_t					lte;
	int						pid;
	pthread_t				t_id;
	struct s_philo			*next;
}									t_philo;

t_philo	*make_list(t_data *infos);
t_philo	*ft_lstnew(int content);
t_philo	*ft_lstlast(t_philo *lst);
time_t	ms_time(void);
time_t	current_time(time_t s_time);
int		ft_atoi(const char *str);
int		ft_isdigit(char *arg);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	mssleep(time_t t_ms);
void	ft_sem_destroy(t_philo *lst_philo);
void	is_eating(t_philo *lst_philo);
void	forks(t_philo *lst_philo, char *fork);
void	is_sleeping(t_philo *lst_philo);
void	is_thinking(t_philo *lst_philo);
void	ft_lstclear(t_philo **lst_philo);
void	*philo(void *arg);
void	*check_death(void *arg);
int		get_infos(t_data *infos, char **av);
int		check_input(int ac, char **av);
int		check_infos(t_data *infos);

#endif