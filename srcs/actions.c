/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 07:03:17 by eavilov           #+#    #+#             */
/*   Updated: 2022/08/07 09:43:44 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_action(t_philo *philo, int act)
{
	pthread_mutex_lock(philo->act);
	if ((*philo->ender) == -1)
	{
		pthread_mutex_lock(philo->act);
		return ;
	}
	if (act == 1)
		ft_grab_fork(&*philo);
	else if (act == 2)
		ft_philo_eat(&*philo);
	else if (act == 3)
		ft_philo_sleep(&*philo);
	else if (act == 4)
		ft_philo_think(&*philo);
	pthread_mutex_unlock(philo->act);
	return ;
}

void	ft_philo_eat(t_philo *philo)
{
	if ((*philo->ender) == -1)
		return ;
	(*philo->ender)++;
	printf("%llu %d is eating\n",
		ft_gettime() - philo->time_start, philo->count);
	philo->last_meal = ft_gettime();
	pthread_mutex_unlock(philo->act);
	ft_usleep(philo->time_to_eat, &*philo);
}

void	ft_philo_sleep(t_philo *philo)
{
	if ((*philo->ender) == -1)
		return ;
	printf("%llu %d is sleeping\n",
		ft_gettime() - philo->time_start, philo->count);
	pthread_mutex_unlock(philo->act);
	ft_usleep(philo->time_to_sleep, &*philo);
}

void	ft_philo_think(t_philo *philo)
{
	if ((*philo->ender) == -1)
		return ;
	printf("%llu %d is thinking\n",
		ft_gettime() - philo->time_start, philo->count);
}

void	ft_grab_fork(t_philo *philo)
{
	if ((*philo->ender) == -1)
		return ;
	printf("%llu %d has taken a fork\n",
		ft_gettime() - philo->time_start, philo->count);
}
