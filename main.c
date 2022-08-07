/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 21:32:06 by eavilov           #+#    #+#             */
/*   Updated: 2022/06/22 09:53:27 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_le_thread(void *args)
{
	t_philo	*philo;

	philo = args;
	if ((philo->count % 2) == 0)
		usleep(2000);
	while ((*philo->ender) != -1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_action(&*philo, 1);
		pthread_mutex_lock(philo->right_fork);
		ft_action(&*philo, 1);
		ft_action(&*philo, 2);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_action(&*philo, 3);
		ft_action(&*philo, 4);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_philo			*philo;
	t_info			inf;
	int				end;

	end = 0;
	pthread_mutex_init(&inf.mutex, NULL);
	pthread_mutex_init(&inf.act, NULL);
	if (!ft_check_args(&inf, ac, av))
		return (0);
	inf.thread = malloc(sizeof(pthread_t) * inf.philo_count);
	inf.forks = malloc(sizeof(pthread_mutex_t) * inf.philo_count);
	philo = malloc(sizeof(t_philo) * inf.philo_count);
	ft_initialize(&*philo, &inf, &end);
	if (ac == 5)
		return (ft_loop_one(&*philo, &inf));
	else if (ac == 6)
		return (ft_loop_two(&*philo, &inf, inf.limit));
}
