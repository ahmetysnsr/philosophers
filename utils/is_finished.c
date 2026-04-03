/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finished.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:24:20 by asari             #+#    #+#             */
/*   Updated: 2026/04/02 21:25:43 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_finished(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->write_lock);
	stop = data->stop_flag;
	pthread_mutex_unlock(&data->write_lock);
	return (stop);
}
