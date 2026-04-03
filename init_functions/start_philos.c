/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:09:35 by asari             #+#    #+#             */
/*   Updated: 2026/04/02 21:22:00 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../philo.h"

void	start_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philosophers[i].thread, NULL,
				philo_routine, &data->philosophers[i]) != 0)
		{
			pthread_mutex_lock(&data->write_lock);
			data->stop_flag = 1;
			pthread_mutex_unlock(&data->write_lock);
			printf("Philos cannot be started %d\n", i + 1);
			break ;
		}
		i++;
	}
	while (--i >= 0)
		pthread_join(data->philosophers[i].thread, NULL);
}
