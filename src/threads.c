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

void	philo_sleep(t_philo *philos)
{
	long	sleep_time;

	if (philos->brain->alive == 0)
		return ;
	sleep_time = philos->time_to_sleep + get_time();
	printf("%lims	%i is sleeping\n", get_time()
		- philos->begin_time, philos->num + 1);
	while (sleep_time > get_time())
		;
	if (philos->brain->alive == 0)
		return ;
	printf("%lims	%i is thinking\n", get_time()
		- philos->begin_time, philos->num + 1);
}

void	eat(t_philo *philos)
{
	long	eat_time;

	if (philos->brain->alive == 0)
		return ;
	pthread_mutex_lock(&philos->fork);
	pthread_mutex_lock(&philos->next_philo->fork);
	philos->myfork = 0;
	philos->next_philo->myfork = 0;
	printf("%lims	%i has taken a fork\n", get_time()
		- philos->begin_time, philos->num + 1);
	printf("%lims	%i has taken a fork\n", get_time()
		- philos->begin_time, philos->num + 1);
	printf("%lims	%i is eating\n", get_time()
		- philos->begin_time, philos->num + 1);
	eat_time = philos->time_to_eat + get_time();
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
	long	death_timer;
	long	wait_time;

	wait_time = philos->time_to_eat / 2;
	death_timer = philos->time_to_die + get_time();
	if ((philos->num) % 2 == 1)
	{	
		wait_time = get_time() + wait_time;
		while (wait_time > get_time())
			;
	}
	while (death_timer > get_time() && philos->brain->alive == 1 && philos->times_eaten != 0)
	{
		death_timer = philos->time_to_die + get_time();
		eat(philos);
	}
	philos->alive = 0;
	if (philos->brain->alive == 0)
		printf("%lims	%i died\n", get_time()
			- philos->begin_time, philos->num + 1);
	philos->brain->alive = 0;
	pthread_cancel(philos->brain->thread_id[philos->num]);
}
