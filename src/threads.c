/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:32:53 by iwillmot          #+#    #+#             */
/*   Updated: 2022/09/09 11:32:54 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	death(t_philo *philos)
{
	
}*/

void	philo_sleep(t_philo *philos)
{
	int	sleep_time;
	int	think_time;

	sleep_time = philos->time_to_sleep + get_time();
	printf("%ims	%i is sleeping\n", get_time() - philos->begin_time, philos->num + 1);
	while (sleep_time > get_time())
		;
	think_time = philos->time_to_sleep + get_time();
	printf("%ims	%i is thinking\n", get_time() - philos->begin_time, philos->num + 1);
	while (think_time > get_time())
		;
}

void	eat(t_philo *philos)
{
	int	cur_time;
	int	eat_time;

	cur_time = get_time();
	while (philos->myfork == 0)
		;
	philos->myfork = 0;
	philos->next_philo->myfork = 0;
	pthread_mutex_lock(&philos->fork);
	pthread_mutex_lock(&philos->next_philo->fork);
	printf("%ims	%i has taken a fork\n", get_time() - philos->begin_time, philos->num + 1);
	printf("%ims	%i has taken a fork\n", get_time() - philos->begin_time, philos->num + 1);
	printf("%ims	%i is eating\n", get_time() - philos->begin_time, philos->num + 1);
	eat_time = philos->time_to_eat + get_time() - philos->begin_time;
	while (eat_time > get_time())
		;
	philos->times_eaten--;
	pthread_mutex_unlock(&philos->fork);
	pthread_mutex_unlock(&philos->next_philo->fork);
	philos->myfork = 1;
	philos->next_philo->myfork = 1;
	philo_sleep(philos);
}

void	philo_exec(t_philo *philos)
{
	int	death_timer;

	while (philos->alive == 1 && philos->times_eaten != 0)
	{
		death_timer = philos->time_to_die + get_time();
		if (death_timer < get_time())
			break ;
		eat(philos);
	}
	printf("ded");
}
