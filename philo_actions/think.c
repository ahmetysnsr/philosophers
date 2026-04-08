/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:09:32 by asari             #+#    #+#             */
/*   Updated: 2026/04/09 01:52:47 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	think(t_philo *philo)
{
	long	time;

	print_status(philo, "is thinking");
	if (philo->data->number_of_philosophers % 2 != 0)
	{
		time = (philo->data->time_to_eat * 2) - philo->data->time_to_sleep;
		if (time < 0)
			time = 0;
		time *= 0.5;
		sleep_ms(time, philo->data);
	}
}
