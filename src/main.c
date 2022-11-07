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

void	simple_setup(t_brain *brain, int argc, char **argv, int i)
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
}

void	philo_setup(t_brain *brain, int argc, char **argv)
{
	int	i;

	i = 0;
	brain->thread_id = malloc(sizeof(pthread_t) * brain->total_philo);
	brain->current = 0;
	while (i < brain->total_philo)
	{
		simple_setup(brain, argc, argv, i);
		brain->philos[i].myfork = 1;
		if (brain->total_philo >= 2)
		{
			if (i == brain->total_philo - 1)
				brain->philos[i].next_philo = &brain->philos[0];
			else
				brain->philos[i].next_philo = &brain->philos[i + 1];
		}
		brain->philos[i].brain = brain;
		pthread_mutex_init(&brain->philos[i].fork, NULL);
		pthread_create(&brain->thread_id[i], NULL,
			(void *_Nullable)philo_exec, &brain->philos[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_brain	brain;

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
	philo_setup(&brain, argc, argv);
	while (brain.alive)
		;
	int	i = 0;
	while (i < brain.total_philo)
	{
		pthread_cancel(brain.thread_id[i]);
		i++;
	}
	//usleep(10000);
	return (0);
}
