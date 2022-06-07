/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:19:08 by eavilov           #+#    #+#             */
/*   Updated: 2022/06/07 07:26:08 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_puttstr(char *s)
{
	if (!s)
		{
			write (1, "(null)", 6);
			return ;
		}
	while (*s)
		write (1, s++, 1);
}

uint64_t	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int main(int ac, char **av)
{
	struct timeval start;
	uint64_t st = ph_get_time();
	uint64_t end = ph_get_time();
	while (end - st < 60)
	{
		usleep(500);
		end = ph_get_time();
	}
	printf("%llu millisecond(s) expired\n", end - st);
}