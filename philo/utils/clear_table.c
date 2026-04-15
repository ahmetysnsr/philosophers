/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:59:52 by asari             #+#    #+#             */
/*   Updated: 2026/04/15 14:59:54 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../philo.h"

void	clear_table(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->forks)
	{
		i = -1;
		while (++i < data->number_of_philosophers)
			pthread_mutex_destroy(&data->forks[i].fork_mutex);
		free(data->forks);
	}
	if (data->philosophers)
	{
		i = -1;
		while (++i < data->number_of_philosophers)
			pthread_mutex_destroy(&data->philosophers[i].meal_lock);
		free(data->philosophers);
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->stop_lock);
	free(data);
}
