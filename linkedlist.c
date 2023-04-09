/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:27:43 by astalha           #+#    #+#             */
/*   Updated: 2023/03/26 01:27:43 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*lastlst;

	if (!*lst && new)
	{
		*lst = new;
		return ;
	}

	lastlst =  ft_lstlast (*lst);
	lastlst->next = new;
}

void	ft_lstadd_front(t_philo **lst, t_philo *new)
{	
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_philo *lst)
{
	int		i;
	t_philo	*plst;

	i = 0;
	if (!lst)
		return (0);
	plst = lst;
	while (plst != NULL)
	{
		i++;
		plst = plst->next;
	}
	return (i);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	t_philo	*plst;

	if (!lst)
		return (NULL);
	plst = lst;
	while (plst->next != NULL)
		plst = plst->next;
	return (plst);
}

t_philo	*ft_lstnew(int content)
{
	t_philo	*new;

	new = (t_philo *) malloc (sizeof (t_philo));
	if (!new)
		return (NULL);
	new->state = 0;
	new->id = content;
	new->n_meals = 0;
	new->lte = 0;
	pthread_mutex_init(&new->p_fork, NULL);
	new->next = NULL;
	return (new);
}