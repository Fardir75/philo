/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 04:37:27 by eavilov           #+#    #+#             */
/*   Updated: 2022/06/02 23:53:23 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	*thread_1(void *args)
{
	t_philo	*philo;
	t_thread vars;
	int		i;

	philo = args;
	i = 0;
	int o = 0;
	pthread_mutex_lock(philo->mutex);
	if (*philo->ender >= 230)
	{
		pthread_mutex_unlock(philo->mutex);
		printf("Dead thread #%d is returning\n", philo->count);
		return ((int *) 10);
	}
	printf("I am in thread #%d\n", philo->count);
	while (1)
	{ 	
		o = 0;
		if (i == 50)
		{
			pthread_mutex_unlock(philo->mutex);
			printf("Thread #%d iterated end to %d\n", philo->count, *philo->ender);
			return (EXIT_SUCCESS);
		}
		else if (*philo->ender >= 230)
		{
			pthread_mutex_unlock(philo->mutex);
			printf("Thread #%d is returning after iterating end to %d\n", philo->count, *philo->ender);
			return ((int *) 10);
		}
		while (o != 10)
		{
			i++;
			o++;
			(*philo->ender)++;
		}
	}
	return (NULL);
}

int main(void)
{
	pthread_t		*thread;
	pthread_mutex_t	mut;
	t_philo			*philo;
	void *stat = (int *) 0;

	int count = 10;
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
	printf("I'm here for some reason\n");
	pthread_mutex_destroy(&mut);
}
