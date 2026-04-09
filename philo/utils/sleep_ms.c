/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_ms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:24:27 by asari             #+#    #+#             */
/*   Updated: 2026/04/09 06:13:00 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../philo.h"

void	sleep_ms(long long ms, t_data *data)
{
	long long	start;
	long long	elapsed;

	start = get_timestamp_ms();
	while (!is_finished(data))
	{
		elapsed = get_timestamp_ms() - start;
		if (elapsed >= ms)
			break ;
		if (ms - elapsed > 2)
			usleep(1000);
		else
			usleep(100);
	}
}
