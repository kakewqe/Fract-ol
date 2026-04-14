/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:29:34 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/27 23:19:03 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_call_mandel(char **av, int ac, t_data *data)
{
	if (ac != 2)
	{
		ft_error();
		ft_close(data);
	}
	else
	{
		mandelbrot(data);
		data->fractal = ft_strdup(av[1]);
	}
}

int	iterate_mandelbrot(t_data *data)
{
	while (data->n < 100 && data->re * data->re + data->im * data->im < 4)
	{
		data->temp = data->re * data->re - data->im * data->im + data->cons_re;
		data->im = 2 * data->re * data->im + data->cons_im;
		data->re = data->temp;
		data->n++;
	}
	return (data->n);
}

void	mandelbrot(t_data *data)
{
	data->i = 0;
	while (data->i < WIN_SIZE)
	{
		data->j = 0;
		while (data->j < WIN_SIZE)
		{
			data->n = 0;
			data->re = 0;
			data->im = 0;
			data->cons_re = (data->i - WIN_SIZE / 2.0) * data->zoom / WIN_SIZE
				+ data->x;
			data->cons_im = (data->j - WIN_SIZE / 2.0) * data->zoom / WIN_SIZE
				+ data->y;
			if (data->n < 100)
				my_putpixel(data, data->i, data->j, iterate_mandelbrot(data)
					* 0x000f0f / 100);
			data->j++;
		}
		data->i++;
	}
}
