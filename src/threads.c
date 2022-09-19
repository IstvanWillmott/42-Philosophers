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

void eat(t_philo *philos)
{
	long	cur_time;

	cur_time = get_time();

}

void	philo_exec(t_philo *philos)
{
	long	death_timer;
	int		pn;

	while (philos->alive == 1 && philos->times_eaten != 0)
	{
		if (death_timer < get_time())
			break ;
		eat(&philos);
	}
	philos->alive = 0;
}
