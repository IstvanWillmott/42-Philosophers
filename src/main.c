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

int	main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("Expected:\n./philo <number_of_philosophers"
			"> <time_to_die> <time_to_eat> <time_to_sleep> <"
			"(optional)number_of_times_each_philosopher_"
			"must_eat>\n");
	}
	return (0);
}
