/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 06:34:46 by eavilov           #+#    #+#             */
/*   Updated: 2022/06/22 07:24:22 by eavilov          ###   ########.fr       */
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

typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

typedef struct s_info {
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	pthread_t		*thread;
	pthread_mutex_t	act;
	int				limit;
	int				philo_count;
	int				argc;
	char			**argv;
}				t_info;

typedef struct s_philo {
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				count;
	int				*ender;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*act;
	uint64_t		time_start;
	uint64_t		last_meal;
}				t_philo;

/*	😊 les fonctions 😊 */

void		ft_action(t_philo *philo, int act);
void		ft_philo_eat(t_philo *philo);
void		ft_philo_sleep(t_philo *philo);
void		ft_philo_think(t_philo *philo);
void		ft_grab_fork(t_philo *philo);
void		ft_usleep(uint64_t time, t_philo *philo);
void		*ft_le_thread(void *args);
void		ft_initialize(t_philo *philo, t_info *inf, int *end);
void		ft_destroy(t_info *inf, t_philo *philo);

uint64_t	ft_gettime(void);

int			ft_check_numerals(int ac, char **av);
int			ft_last_meal(t_philo *philo, t_info *inf);
int			ft_check_args(t_info *inf, int ac, char **av);
int			ft_loop_one(t_philo *philo, t_info *inf);
int			ft_loop_two(t_philo *philo, t_info *inf, int limit);

#endif