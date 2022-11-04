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
	long	sleep_time;

	sleep_time = philos->time_to_sleep + get_time();
	printf("%lims	%i is sleeping\n", get_time() - philos->begin_time, philos->num + 1);
	while (sleep_time > get_time())
		;
	printf("%lims	%i is thinking\n", get_time() - philos->begin_time, philos->num + 1);
	//while (philos->myfork == 0)
	//	;
}

void	eat(t_philo *philos)
{
	long	eat_time;

	//printf("queue: %i(%i)\n", philos->brain->queue, philos->num + 1);
	philos->myfork = 0;
	philos->next_philo->myfork = 0;
	pthread_mutex_lock(&philos->fork);
	pthread_mutex_lock(&philos->next_philo->fork);
	printf("i am %i, i am taking %is fork\n", philos->num + 1, philos->next_philo->num + 1);
	printf("%lims	%i has taken a fork\n", get_time() - philos->begin_time, philos->num + 1);
	printf("%lims	%i has taken a fork\n", get_time() - philos->begin_time, philos->num + 1);
	printf("%lims	%i is eating\n", get_time() - philos->begin_time, philos->num + 1);
	eat_time = philos->time_to_eat + get_time();
	while (eat_time > get_time())
		;
	philos->times_eaten--;
	pthread_mutex_unlock(&philos->fork);
	pthread_mutex_unlock(&philos->next_philo->fork);
	philos->myfork = 1;
	philos->next_philo->myfork = 1;
	//if (philos->brain->queue == philos->brain->total_philo - 1)
	//	philos->brain->queue = 1;
	//else if (philos->brain->queue == philos->brain->total_philo - 2)
	//	philos->brain->queue = 0;
	//else
	//	philos->brain->queue = philos->num + 2;
	philo_sleep(philos);
}

void	philo_exec(t_philo *philos)
{
	long	death_timer;
	int		odd;
	long	wait_time;

	death_timer = philos->time_to_die + get_time();
	odd = philos->brain->total_philo % 2;
	wait_time = philos->time_to_eat/2;
	/*while (philos->alive == 1)
	{
		if (death_timer < get_time())
			break ;
		death_timer = philos->time_to_die + get_time();
		eat(&*philos);
	}*/

	if ((philos->num) % 2 == 1)
	{	
		wait_time = get_time() + wait_time;
		while (wait_time > get_time())
			;
	}
	printf("i am %i\n", philos->num + 1);
	while (1)
		eat(philos);
	//philos->alive = 0;
	printf("%i ded\n", philos->num + 1);
}
