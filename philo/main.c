/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*                                                +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*   By: asari <asari>                              +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*                                                +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*   Created: 2026/04/02 21:24:31 by asari             +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*   Updated: 2026/04/04 01:54:39 by asari            +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	monitor_thread;

	if (!check_arguments_validation(argc, argv))
	{
		printf("Error:Arguments are not valid.\n");
		return (1);
	}
	data = init_data(argc, argv);
	if (!data)
		return (1);
	if (!init_forks(data) || !init_philos(data))
	{
		clear_table(data);
		return (1);
	}
	pthread_create(&monitor_thread, NULL, monitor_routine, data);
	start_philos(data);
	pthread_join(monitor_thread, NULL);
	clear_table(data);
	return (0);
} 