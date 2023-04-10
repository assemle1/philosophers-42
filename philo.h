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
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_data
{
    pthread_mutex_t     print;
    int               n_philos;
    time_t               ttd;
    time_t                tte;
    time_t                tts;
    int                 can_print;
    int                meals;
    time_t                 t_start;        
}               t_data;

typedef struct s_philo
{
    int              state;
    int              id;
    int               n_meals;
    t_data          *infos;
    time_t                 lte;
    pthread_t       t_id;
    pthread_mutex_t  p_fork;
    struct s_philo  *next;                                          
}               t_philo;

int	ft_atoi(const char *str);
int	ft_isdigit(char *arg);
t_philo	*ft_lstnew(int content);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo	*ft_lstlast(t_philo *lst);
time_t     ms_time();
void    mssleep(time_t t_ms);
time_t  current_time(time_t s_time);
void    mutex_destroy(t_philo   *lst_philo);
void    is_eating(t_philo *lst_philo);
void    forks(t_philo *lst_philo, char  *fork);
void    is_sleeping(t_philo *lst_philo);
void    is_thinking(t_philo *lst_philo);
void	ft_lstclear(t_philo **lst_philo);

#endif