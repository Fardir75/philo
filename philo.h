/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 21:26:07 by eavilov           #+#    #+#             */
/*   Updated: 2022/06/07 09:36:26 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*	 🐄 pouin-vach 🐄 	*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"

typedef struct	s_thread {
	pthread_mutex_t mutex;
	int				nb;
	int				i;
	int				count;
	int				end;
}				t_thread;

typedef struct s_philo {
	int				time_to_eat;
	int				time_to_die;
	int				count;
	int				*ender;
	pthread_mutex_t *mutex;
}				t_philo;

#endif