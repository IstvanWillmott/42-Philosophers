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

void	philo_setup(t_brain *brain, int argc, char **argv)
{
	int	i;

	i = 0;
	brain->thread_id = malloc(sizeof(pthread_t) * brain->total_philo);
	brain->current = 0;
	while (i < brain->total_philo)
	{
		brain->philos[i].num = i;
		brain->philos[i].time_to_die = ft_atoi(argv[2]);
		brain->philos[i].time_to_eat = ft_atoi(argv[3]);
		brain->philos[i].time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			brain->philos[i].times_eaten = ft_atoi(argv[5]);
		brain->philos[i].myfork = 1;
		pthread_create(&brain->thread_id[i], NULL,
				(void *_Nullable)philo_exec, &brain->philos[i]);
		pthread_mutex_init(&brain->philos[i].fork, NULL);
		i++;
	}
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
	philo_setup(&brain, argc, argv);
	return (0);
}
