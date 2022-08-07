/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 07:06:47 by eavilov           #+#    #+#             */
/*   Updated: 2022/08/07 10:23:13 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

uint64_t	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_last_meal(t_philo *philo, t_info *inf)
{
	int			i;
	uint64_t	current;

	i = -1;
	while (++i < inf->philo_count)
	{
		current = ft_gettime();
		if ((current - philo[i].last_meal) > philo[i].time_to_die
			&& (current - philo[i].last_meal) < 9999999)
		{
			pthread_mutex_lock(philo->act);
			printf("%llu %d died\n",
				current - 1 - philo[i].time_start, philo[i].count);
			(*philo->ender) = -1;
			return (-1);
		}
		if ((*philo->ender) >= inf->limit && inf->argc == 6)
		{
			pthread_mutex_lock(philo->act);
			return (-1);
		}
	}
	return (0);
}

void	ft_usleep(uint64_t time, t_philo *philo)
{
	uint64_t	start;

	start = ft_gettime();
	usleep(((time / 100) * 90) * 1000);
	while (ft_gettime() - start < time)
		usleep(500);
}
