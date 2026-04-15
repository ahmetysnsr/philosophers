/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:23:39 by asari             #+#    #+#             */
/*   Updated: 2026/04/15 13:09:42 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_timestamp_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	if (philo->philo_id % 2 == 0)
		usleep(philo->data->time_to_eat * 500);
	while (!is_finished(philo->data))
	{
		take_forks(philo);
		if (philo->data->number_of_philosophers == 1)
			break ;
		if (is_finished(philo->data))
		{
			drop_forks(philo);
			break ;
		}
		eat_kebab(philo);
		drop_forks(philo);
		take_nap(philo);
		think(philo);
	}
	return (NULL);
}
