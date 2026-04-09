/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_nap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asari <asari>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:09:28 by asari             #+#    #+#             */
/*   Updated: 2026/04/02 18:09:28 by asari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_nap(t_philo *philo)
{
	print_status(philo, "is sleeping");
	sleep_ms(philo->data->time_to_sleep, philo->data);
}
