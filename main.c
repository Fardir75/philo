/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 21:32:06 by eavilov           #+#    #+#             */
/*   Updated: 2022/06/07 11:18:09 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(uint64_t time)
{
	uint64_t	start;
	uint64_t	end;

	start = ft_gettime();
	end = ft_gettime();
	while (end - start < time)
	{
		usleep(500);
		end = ft_gettime();
	}
}

void	*thread_1(void *args)
{
	t_philo	*philo;
	t_thread vars;
	uint64_t start;
	int		i;

	philo = args;
	i = 0;
	if ((philo->count % 2) == 0)
		usleep(500);
	start = ft_gettime();
	while (1)
	{
		pthread_mutex_lock(philo->mutex);
		if ((*philo->ender) >= 4000)
		{
			printf("%llu ", ft_gettime() - start);
			printf("Dead thread #%d is exiting the thread\n", philo->count);
			pthread_mutex_unlock(philo->mutex);
			return (NULL);
		}
		while (i != 100)
		{
			i++;
			(*philo->ender)++;
		}
		printf("%llu ", ft_gettime() - start);
		printf("Thread #%d finished adding 100 to end\n", philo->count);
		i = 0;
		pthread_mutex_unlock(philo->mutex);
		ft_usleep(500);
	}
	return (NULL);
}

int main(void)
{
	pthread_t		*thread;
	t_philo			*philo;
	pthread_mutex_t	mut;
	void *stat = (int *) 0;

	int count = 4;
	int i = 0;
	int u = 0;
	int p = 0;
	thread = malloc(sizeof(pthread_t) * count);
	philo = malloc(sizeof(t_philo) * count);
	pthread_mutex_init(&mut, NULL);
	while (++i <= count)
	{
		philo[i].count = i + 0;
		philo[i].mutex = &mut;
		philo[i].ender = &p;
		p = pthread_create(&thread[i], NULL, thread_1, &philo[i]);
	}
	while (++u <= count)
	{
		usleep(500);
		if (stat == (int *) 10)
		{
			printf("I exit the program\n");
			pthread_mutex_destroy(&mut);
			free(thread);
			return (0);
		}
		if (stat == (int *) 0)
			pthread_join(thread[u], &stat);
	}
	printf("END = %d\n", p);
	free(thread);
	free(philo);
	pthread_mutex_destroy(&mut);
}
