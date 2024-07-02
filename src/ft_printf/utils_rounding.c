/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rounding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:16:44 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/25 21:16:45 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_rounding_digit_index_in_float_buffer(t_options *options,
				t_float_b10 *nbr_b10)
{
	int	rounding_digit_index;

	rounding_digit_index = options->precision;
	if (options->conversion != 'g')
		rounding_digit_index++;
	if (options->conversion == 'f')
		rounding_digit_index += nbr_b10->exponent;
	return (rounding_digit_index);
}

static bool	ft_should_round_up(t_float_b10 *nbr_b10,
				char *float_buffer, int index)
{
	return (0 <= index && index <= nbr_b10->length - 1
		&& (float_buffer[index] > 5
			|| (float_buffer[index] == 5
				&& index < nbr_b10->length - 1)
			|| (BANKERS_ROUNDING
				&& index > 0
				&& float_buffer[index] == 5
				&& index == nbr_b10->length - 1
				&& float_buffer[index - 1] % 2 == 1)));
}

static void	ft_remove_trailing_zeros(t_options *options, t_float_b10 *nbr_b10,
				char *float_buffer, int index)
{
	bool	should_remove_trailing_zeros;

	should_remove_trailing_zeros = (options->conversion == 'g'
			&& !options->flag_hash);
	if (should_remove_trailing_zeros)
	{
		options->precision -= ft_max(index - nbr_b10->length, 0);
		if (index < nbr_b10->length)
		{
			while (index && float_buffer[index - 1] == 0)
			{
				options->precision--;
				index--;
			}
		}
	}
}

static void	ft_round_up_and_remove_trailing_zeros(t_options *options,
				t_float_b10 *nbr_b10, char *float_buffer, int index)
{
	int		shift_distance;
	bool	should_remove_trailing_zeros;

	while (index && float_buffer[index - 1] == 9)
		index--;
	shift_distance = (index == 0);
	nbr_b10->exponent += shift_distance;
	index += shift_distance;
	if (shift_distance)
		float_buffer[index - 1] = 1;
	else
		float_buffer[index - 1]++;
	should_remove_trailing_zeros = (options->conversion == 'g'
			&& !options->flag_hash);
	if (should_remove_trailing_zeros)
		options->precision = index;
	while (index <= nbr_b10->exponent)
		float_buffer[index++] = 0;
	nbr_b10->length = index;
	if (nbr_b10->exponent == 0 && float_buffer[0] && !nbr_b10->integer_part)
		nbr_b10->integer_part = 1;
}

void	ft_round_b10(t_options *options, t_float_b10 *nbr_b10,
			char *float_buffer)
{
	int		index;

	index = ft_get_rounding_digit_index_in_float_buffer(options, nbr_b10);
	if (!ft_should_round_up(nbr_b10, float_buffer, index))
		ft_remove_trailing_zeros(options, nbr_b10, float_buffer, index);
	else
		ft_round_up_and_remove_trailing_zeros(options, nbr_b10, float_buffer,
			index);
}
