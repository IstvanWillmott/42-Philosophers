/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:41:40 by iwillmot          #+#    #+#             */
/*   Updated: 2022/08/15 14:41:41 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_start(t_brain *brain)
{
	int		i;
	int		odd;
	long	wait_time;

	i = 1;
	odd = (brain->total_philo % 2);
	wait_time = brain->philos[i].time_to_eat;
	while (i < brain->total_philo)
	{
		while (brain->philos[i].myfork == 0)
			;
		pthread_create(&brain->thread_id[i], NULL, 
			(void *_Nullable)philo_exec, &brain->philos[i]);
		if (i == brain->total_philo - 1 - odd)
		{
			i = 0;
			wait_time = wait_time + get_time();
			while (wait_time > get_time())
				;
		}
		else
			i += 2;
	}
}

void	philo_setup(t_brain *brain, int argc, char **argv)
{
	int	i;

	i = 0;
	brain->thread_id = malloc(sizeof(pthread_t) * brain->total_philo);
	brain->current = 0;
	while (i < brain->total_philo)
	{
		brain->philos[i].begin_time = brain->begin_time;
		brain->philos[i].alive = 1;
		brain->philos[i].num = i;
		brain->philos[i].time_to_die = ft_atoi(argv[2]);
		brain->philos[i].time_to_eat = ft_atoi(argv[3]);
		brain->philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			brain->philos[i].times_eaten = ft_atoi(argv[5]);
		else
			brain->philos[i].times_eaten = -1;
		brain->philos[i].myfork = 1;
		if (i == brain->total_philo - 1)
			brain->philos[i].next_philo = &brain->philos[0];
		else
			brain->philos[i].next_philo = &brain->philos[i + 1];
		brain->philos[i].brain = brain;
		pthread_mutex_init(&brain->philos[i].fork, NULL);
		i++;
	}
	philo_start(brain);
}

int	main(int argc, char *argv[])
{
	t_brain brain;

	if (argc != 5 && argc != 6)
	{
		printf("Expected:\n./philo <number_of_philosophers"
			"> <time_to_die> <time_to_eat> <time_to_sleep> <"
			"(optional)number_of_times_each_philosopher_"
			"must_eat>\n");
		return (1);
	}
	brain.total_philo = ft_atoi(argv[1]);
	brain.philos = malloc(sizeof(t_philo) * brain.total_philo);
	brain.alive = 1;
	brain.begin_time = get_time();
	brain.queue = 1;
	philo_setup(&brain, argc, argv);
	return (0);
}
