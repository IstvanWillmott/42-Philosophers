/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:41:29 by iwillmot          #+#    #+#             */
/*   Updated: 2022/08/15 14:41:30 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct	s_philo
{
	int				begin_time;
	int 			alive;
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_eaten;
	int				myfork;
	pthread_mutex_t fork;
	struct s_philo	*next_philo;
}	t_philo;

typedef struct s_brain
{
	int			begin_time;
	pthread_t	*thread_id;
	int			total_philo;
	t_philo		*philos;
	int			alive;
	int			current;
}	t_brain;

int		ft_atoi(const char *str);

void	philo_exec(t_philo *philos);

int		get_time(void);

#endif