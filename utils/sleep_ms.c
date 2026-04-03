/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_ms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:24:27 by asari             #+#    #+#             */
/*   Updated: 2026/04/02 21:26:57 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../philo.h"

void	sleep_ms(long long milisec, t_data *data)
{
	long long	start;

	start = get_timestamp_ms();
	while ((get_timestamp_ms() - start) < milisec && !is_finished(data))
		usleep(100);
}
