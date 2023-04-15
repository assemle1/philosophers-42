/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 02:29:48 by astalha           #+#    #+#             */
/*   Updated: 2023/03/25 02:29:48 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t			print;
	pthread_mutex_t			mutex;
	pthread_mutex_t			mutex2;
	int						n_philos;
	time_t					ttd;
	time_t					tte;
	time_t					tts;
	int						can_print;
	int						meals;
	time_t					t_start;
}									t_data;

typedef struct s_philo
{
	int						id;
	int						n_meals;
	t_data					*infos;
	time_t					lte;
	pthread_t				t_id;
	pthread_mutex_t			p_fork;
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
void	mutex_destroy(t_philo *lst_philo);
void	is_eating(t_philo *lst_philo);
void	forks(t_philo *lst_philo, char *fork);
void	is_sleeping(t_philo *lst_philo);
void	is_thinking(t_philo *lst_philo);
void	ft_lstclear(t_philo **lst_philo);
void	*philo(void *arg);
void	check_death(t_philo *philo);
int		get_infos(t_data *infos, char **av);
int		check_input(int ac, char **av);
int		check_infos(t_data *infos);

#endif