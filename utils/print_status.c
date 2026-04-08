/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:24:24 by asari             #+#    #+#             */
/*   Updated: 2026/04/09 01:35:18 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../philo.h"

void	print_status(t_philo *philo, char *status)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->data->write_lock);
	if (!is_finished(philo->data))
	{
		timestamp = get_timestamp_ms() - philo->data->start_time;
		printf("%lld %d %s\n", timestamp, philo->philo_id, status);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}
