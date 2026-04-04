/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:23:39 by asari             #+#    #+#             */
/*   Updated: 2026/04/04 02:26:09 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_timestamp_ms();
	pthread_mutex_unlock(&philo->meal_lock);
	if (philo->philo_id % 2 == 0)
		usleep(data->time_to_eat * 500);
	while (!is_finished(data))
	{
		take_forks(philo);
		if (data->number_of_philosophers == 1 || is_finished(data))
			break ;
		eat_kebab(philo);
		drop_forks(philo);
		take_nap(philo);
		think(philo);
	}
	return (NULL);
}
