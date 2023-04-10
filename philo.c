#include "philo.h"

void    get_infos(t_data *infos, char **av)
{
    infos->n_philos = ft_atoi(av[1]);
    infos->ttd = ft_atoi(av[2]);
    infos->tte = ft_atoi(av[3]);
    infos->tts = ft_atoi(av[4]);
    if (av[5])
        infos->meals = ft_atoi(av[5]);
    else 
        infos->meals = -1;
}

void    print_err(void)
{
    printf("error\n");
    exit(1);
}
void    check_input(int ac, char **av)
{
    int i;

    i = 1;
    if (ac < 4 || ac > 6)
        print_err();
    while(av[i])
    {
        if (!ft_isdigit(av[i]))
        {
            puts("ok");
            print_err();
        }
        i++;
    }
}

void    check_infos(t_data *infos)
{
    if (infos->n_philos <= 0 || infos->n_philos > 200)
        print_err();
    if (infos->ttd <= 0 || infos->tte <= 0 || infos->tts <= 0)
        print_err();
    if (infos->meals == 0 || infos->meals < -1)
        print_err();
}


t_philo    *make_list(t_data *infos)
{
    t_philo *lst_philo = NULL;
    t_philo *new;
    t_philo *last;
    int i;

    i = 0;
    while(i < infos->n_philos)
    {
        new =  ft_lstnew(i + 1);
        if (!new)
            print_err();
        new ->infos = infos;
        ft_lstadd_back(&lst_philo, new);
        i++;
    }
    last = ft_lstlast(lst_philo);
    last->next = lst_philo;
    return lst_philo;
}

int     finished(t_philo    *lst_philo)
{
    int i;

    i = 0;
    while(lst_philo)
    {
        if (lst_philo->n_meals == lst_philo->infos->meals)
            i++;
        if (i == lst_philo->infos->n_philos)
            return 1;
        if (lst_philo->id == 1)
            break;
        lst_philo = lst_philo->next;
    }
        return 0;
}
void    check_death(t_philo   *philo)
{
    while(philo)
    {
        if (current_time(philo->infos->t_start) - philo->lte > philo->infos->ttd)
            {
                philo->infos->can_print = 0;
                pthread_mutex_lock(&philo->infos->print);
                printf("%ld %d died\n", current_time(philo->infos->t_start), philo->id);
                pthread_mutex_unlock(&philo->infos->print);
                break;
            }
        if (finished(philo))
            break;
        philo = philo->next;
    }
}

void    *philo(void   *arg)
{
    t_philo *lst_philo = (t_philo *)(arg);
    
    while(1)
    {
        if (!lst_philo->infos->can_print)
            break ;
        if (lst_philo->n_meals == lst_philo->infos->meals)
            break;
        if (lst_philo->id % 2)
            usleep(100);
            pthread_mutex_lock(&lst_philo->p_fork);
            forks(lst_philo, "right");
            pthread_mutex_lock(&lst_philo->next->p_fork);
            forks(lst_philo, "left");
            is_eating(lst_philo);
            is_sleeping(lst_philo);
            is_thinking(lst_philo);
    }
    return NULL;
}

void    init_scene(t_philo *lst_philo)
{
    int i;

    i = 0;
    lst_philo->infos->t_start = ms_time();
    lst_philo->infos->can_print = 1;
    while(lst_philo)
    {
        pthread_create(&lst_philo->t_id, NULL,philo, (void *)lst_philo);
        lst_philo = lst_philo->next;
        if (lst_philo->id == 1)
            break;
    }
    check_death(lst_philo);
    while(lst_philo)
    {
        pthread_detach(lst_philo->t_id);
        lst_philo = lst_philo->next;
         if (lst_philo->id == 1)
            break;
    }
}

t_philo    *set_args(t_data *infos, char **av, int ac)
{
    check_input(ac, av);
    get_infos(infos, av);
    check_infos(infos);
    return(make_list(infos));
}

void    mutex_destroy(t_philo   *lst_philo)
{
    pthread_mutex_destroy(&lst_philo->infos->print);
    while(lst_philo)
    {
        pthread_mutex_destroy(&lst_philo->p_fork);
        lst_philo = lst_philo->next;
        if (lst_philo->id == 1)
            break;
    }
}

int main(int ac, char **av)
{
    t_data infos;
    t_philo *lst_philo;

    lst_philo = set_args(&infos, av, ac);
    pthread_mutex_init(&infos.print, NULL);
    init_scene(lst_philo);
    mutex_destroy(lst_philo);
}