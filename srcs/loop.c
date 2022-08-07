/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:07:50 by eavilov           #+#    #+#             */
/*   Updated: 2022/08/07 09:48:26 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_loop_one(t_philo *philo, t_info *inf)
{
	while (1)
	{
		//pthread_mutex_lock(&inf->mutex);
		if (ft_last_meal(&*philo, &*inf) == -1)
		{
			ft_destroy(&*inf, philo);
			//pthread_mutex_unlock(&inf->mutex);
			printf("Je me casse\n");
			return (0);
		}
		//pthread_mutex_unlock(&inf->mutex);
	}
	return (0);
}

int	ft_loop_two(t_philo *philo, t_info *inf, int limit)
{
	while (1)
	{
		pthread_mutex_lock(&inf->mutex);
		if (ft_last_meal(&*philo, &*inf) == -1 || (*philo->ender) >= limit)
		{
			ft_destroy(&*inf, philo);
			pthread_mutex_unlock(&inf->mutex);
			return (0);
		}
		pthread_mutex_unlock(&inf->mutex);
	}
	return (0);
}
