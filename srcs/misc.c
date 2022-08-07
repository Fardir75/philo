/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 07:07:24 by eavilov           #+#    #+#             */
/*   Updated: 2022/08/07 09:29:12 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_destroy(t_info *inf, t_philo *philo)
{
	int	index;

	index = -1;
	free(inf->forks);
	free(philo);
	free(inf->thread);
	pthread_mutex_destroy(&inf->mutex);
}

int	ft_check_numerals(int ac, char **av)
{
	int	index;

	index = -1;
	while (av[1][++index])
		if (ft_isdigit(av[1][index]) == 0)
			return (0);
	index = -1;
	while (av[2][++index])
		if (ft_isdigit(av[2][index]) == 0)
			return (0);
	index = -1;
	while (av[3][++index])
		if (ft_isdigit(av[3][index]) == 0)
			return (0);
	index = -1;
	while (av[4][++index])
		if (ft_isdigit(av[4][index]) == 0)
			return (0);
	index = -1;
	if (ac == 6)
		while (av[5][++index])
			if (ft_isdigit(av[5][index]) == 0)
				return (0);
	return (1);
}

int	ft_check_args(t_info *inf, int ac, char **av)
{
	int	index;

	index = -1;
	if (ac < 5 || ac > 6)
		return (0);
	while (++index < ac)
		if (!ft_strlen(av[index]))
			return (0);
	if (ft_check_numerals(ac, av) == 0)
		return (0);
	inf->argc = ac;
	inf->argv = av;
	inf->philo_count = ft_atoi(av[1]);
	if (ac == 6)
	{
		inf->limit = (ft_atoi(av[5]) * inf->philo_count);
		if (inf->limit <= 0)
			return (0);
	}
	return (1);
}

void	ft_initialize(t_philo *philo, t_info *inf, int *end)
{
	int	i;

	i = 0;
	while (i < inf->philo_count)
	{
		pthread_mutex_init(&inf->forks[i], NULL);
		philo[i].left_fork = &inf->forks[i];
		philo[i].time_to_die = atoi(inf->argv[2]);
		philo[i].time_to_eat = atoi(inf->argv[3]);
		philo[i].time_to_sleep = atoi(inf->argv[4]);
		i++;
		philo[i - 1].right_fork = &inf->forks[i % inf->philo_count];
	}
	i = -1;
	while (++i < inf->philo_count)
	{
		philo[i].act = &inf->act;
		philo[i].count = i + 1;
		philo[i].mutex = &inf->mutex;
		philo[i].time_start = ft_gettime();
		philo[i].ender = end;
		philo[i].last_meal = philo[i].time_start;
		pthread_create(&inf->thread[i], NULL, ft_le_thread, &philo[i]);
	}
}
