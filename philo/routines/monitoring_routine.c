/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*                                                    +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*   By: asari <asari@student.42.fr>                +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*                                                +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*   Created: 2026/04/02 21:23:51 by asari             +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*   Updated: 2026/04/09 02:12:26 by asari            +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../philo.h"

static int	kill_philo(t_data *data, int i)
{
	pthread_mutex_unlock(&data->philosophers[i].meal_lock);
	pthread_mutex_lock(&data->stop_lock);
	data->stop_flag = 1;
	pthread_mutex_unlock(&data->stop_lock);
	pthread_mutex_lock(&data->write_lock);
	printf("%lld %d died\n", get_timestamp_ms() - data->start_time,
		data->philosophers[i].philo_id);
	pthread_mutex_unlock(&data->write_lock);
	return (0);
}

static int	monitor_helper(t_data *data, int *finished_eating)
{
	int	i;

	*finished_eating = 0;
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->philosophers[i].meal_lock);
		if (get_timestamp_ms() - data->philosophers[i].last_meal_time
			> data->time_to_die)
		{
			return (kill_philo(data, i));
		}
		if (data->number_of_times_each_philosopher_must_eat != -1
			&& data->philosophers[i].eat_count
			>= data->number_of_times_each_philosopher_must_eat)
			(*finished_eating)++;
		pthread_mutex_unlock(&data->philosophers[i].meal_lock);
	}
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		finished_eating;

	data = (t_data *)arg;
	while (1)
	{
		if (monitor_helper(data, &finished_eating) == 0)
			return (NULL);
		if (data->number_of_times_each_philosopher_must_eat != -1
			&& finished_eating == data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->stop_lock);
			data->stop_flag = 1;
			pthread_mutex_unlock(&data->stop_lock);
			return (NULL);
		}
		usleep(100);
	}
} 