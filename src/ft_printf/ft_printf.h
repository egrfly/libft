/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:39:29 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/03 00:29:36 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

# include "ft_ctype.h"
# include "ft_stdlib.h"
# include "ft_string.h"

# ifndef UTF8
#  define UTF8 1
# endif
# ifndef MACOS
#  define MACOS 0
# endif
# ifndef BINARY_MODE
#  define BINARY_MODE 1
# endif
# ifndef BANKERS_ROUNDING
#  define BANKERS_ROUNDING 1
# endif

# define C_BUFFER_SIZE 4096
# define C_MAX_FLOAT_DIGITS 11500
# define C_EXPONENT_BIAS 16383

# define C_HEXADECIMAL_BASE 16
# define C_DECIMAL_BASE 10
# define C_OCTAL_BASE 8
# define C_BINARY_BASE 2

# define C_DIGITS "0123456789abcdef"
# define C_OPTIONS "-0 +#*.123456789lhLjtz'$q"
# define C_FLAGS "-0 +#"
# define C_WIDTH_PRECISION "0123456789"
# define C_LENGTH "lhLjtz"

# define C_EMPTY_STR ""
# define C_NULL_STR "(null)"
# define C_NIL_STR "(nil)"
# define C_NAN_STR "nan"
# define C_INF_STR "inf"

# define C_BITS_UINT64_T 64

# define C_BIT_NONFINITE_EXPONENT 0x7FFFU
# define C_BIT_FIRST 0x8000000000000000U
# define C_BIT_SECOND 0x4000000000000000U
# define C_BIT_LAST 0x1U

# define C_BIT_UTF8_1 0x80
# define C_BIT_UTF8_2 0xC0
# define C_BIT_UTF8_3 0xE0
# define C_BIT_UTF8_4 0xF0
# define C_BIT_LAST_6 0x3F

typedef struct s_options
{
	int				count;
	bool			error;
	int				fd;
	bool			flush;
	va_list			arg;
	char			conversion;
	bool			conversion_recognised;
	bool			caps;
	int				base;
	bool			flag_minus;
	bool			flag_zero;
	bool			flag_space;
	bool			flag_plus;
	bool			flag_hash;
	int				width;
	bool			width_active;
	bool			width_error;
	int				precision;
	bool			precision_active;
	bool			length_l;
	bool			length_ll;
	bool			length_h;
	bool			length_hh;
	bool			length_lcap;
	bool			length_j;
	bool			length_t;
	bool			length_z;
	int				length_lcount;
	int				length_hcount;
}					t_options;

typedef union u_float_b2
{
	long double		value;
	struct s_parts
	{
		uint64_t	coefficient : 64;
		uint32_t	exponent : 15;
		uint8_t		sign : 1;
	}				parts;
}					t_float_b2;

typedef struct s_float_b10
{
	char			sign;
	uint64_t		integer_part;
	uint64_t		decimal_part;
	int				exponent;
	int				length;
}					t_float_b10;

/*
** conversion_char.c
*/
void		ft_convert_char(t_options *options, char c);
void		ft_convert_wchar(t_options *options, wchar_t c);

/*
** conversion_float.c
*/
void		ft_convert_float_nonfinite(t_options *options,
				t_float_b2 *nbr_b2);
void		ft_convert_float_scientific(t_options *options,
				t_float_b10 *nbr_b10, char *float_buffer);
void		ft_convert_float_extended(t_options *options,
				t_float_b10 *nbr_b10, char *float_buffer);

/*
** conversion_hex.c
*/
void		ft_convert_float_hexadecimal(t_options *options,
				t_float_b2 *nbr_b2, char *float_buffer);

/*
** conversion_int.c
*/
void		ft_convert_int(t_options *options, int64_t value);

/*
** conversion_str.c
*/
void		ft_convert_str(t_options *options, char *str);
void		ft_convert_wstr(t_options *options, wchar_t *wstr);

/*
** conversion_uint.c
*/
void		ft_convert_uint(t_options *options, uint64_t value);

/*
** main_affixing.c
*/
void		ft_prepend_spaces(t_options *options,
				int chars_before_zeros, int chars_after_zeros);
void		ft_prepend_sign(t_options *options,
				bool is_negative);
void		ft_prepend_base_prefix(t_options *options,
				bool nonzero_value);
void		ft_prepend_zeros(t_options *options,
				int chars_before_zeros, int chars_after_zeros);
void		ft_append_spaces(t_options *options,
				int chars_before_zeros, int chars_after_zeros);

/*
** main_args.c
*/
wchar_t		ft_get_char_arg(t_options *options);
uintptr_t	ft_get_ptr_arg(t_options *options);
int64_t		ft_get_int_arg(t_options *options);
uint64_t	ft_get_uint_arg(t_options *options);
long double	ft_get_float_arg(t_options *options);

/*
** main_formatting.c
*/
int			ft_parse_flags(t_options *options, const char *str);
void		ft_parse_conversion(t_options *options, char conversion);
void		ft_route_conversion(t_options *options);
void		ft_put_formatted_str(const char *str, t_options *options);

/*
** main_routing.c
*/
void		ft_route_char_conversion(t_options *options,
				wchar_t c);
void		ft_route_str_conversion(t_options *options,
				uintptr_t ptr);
void		ft_route_int_conversion(t_options *options,
				int64_t value);
void		ft_route_uint_conversion(t_options *options,
				uint64_t value);
void		ft_route_float_conversion(t_options *options,
				long double value);

/*
** main_saving.c
*/
void		ft_save_count(t_options *options,
				uintptr_t ptr);

/*
** utils_affixing.c
*/
int			ft_spaces_length(t_options *options,
				int chars_before_zeros, int chars_after_zeros);
int			ft_sign_length(t_options *options,
				bool is_negative);
int			ft_base_prefix_length(t_options *options,
				bool nonzero_value);
int			ft_zeros_length(t_options *options,
				int chars_before_zeros, int chars_after_zeros);

/*
** utils_bit.c
*/
uint64_t	ft_shift_left_and_back(uint64_t nbr, int length);
uint64_t	ft_shift_right(uint64_t nbr, int length);

/*
** utils_float.c
*/
void		ft_float_to_buffer(t_float_b2 *nbr_b2,
				t_float_b10 *nbr_b10, char *float_buffer);

/*
** utils_number.c
*/
void		ft_putnbr_buffered(t_options *options, uint64_t nbr);
void		ft_putnbr_capped(t_options *options, char *buffer, int cap);
int			ft_uint_to_buffer(uint64_t nbr, char *buffer, int base);
int			ft_uint_to_buffer_from_right(uint64_t nbr, char *buffer,
				int base, int offset);

/*
** utils_options.c
*/
void		ft_initialise_options(t_options *options, int fd);
void		ft_reset_options(t_options *options);

/*
** utils_parsing.c
*/
void		ft_set_flag(t_options *options, char c);
int			ft_set_width(t_options *options, const char *str);
int			ft_set_precision(t_options *options, const char *str);
void		ft_set_length(t_options *options, char c);

/*
** utils_precision.c
*/
void		ft_set_int_precision_error(t_options *options,
				int chars_before_zeros);
void		ft_set_float_precision_error(t_options *options,
				int chars_before_decimal_places,
				int chars_after_decimal_places);
void		ft_set_float_precision_before_rounding(t_options *options);

/*
** utils_printing.c
*/
void		ft_putchar_buffered(t_options *options, char c);
void		ft_putchar_case(t_options *options, char c);
void		ft_putchars(t_options *options, char c, int length);
void		ft_flush(t_options *options);

/*
** utils_routing.c
*/
void		ft_round_b10(t_options *options, t_float_b10 *nbr_b10,
				char *float_buffer);
void		ft_route_float_conversion_scientific_or_extended(
				t_options *options, t_float_b10 *nbr_b10,
				char *float_buffer, int precision_before_rounding);

/*
** utils_string.c
*/
int			ft_strlen_capped(char *str, int cap);
void		ft_putstr_buffered(t_options *options, char *str);
void		ft_putstr_capped(t_options *options, char *str, int cap);
void		ft_putstr_case(t_options *options, char *str);

/*
** utils_wchar.c
*/
int			ft_wcharlen(wchar_t c);
void		ft_putwchar(t_options *options, wchar_t c);

/*
** utils_wstr.c
*/
int			ft_wstrlen(wchar_t *wstr);
int			ft_wstrlen_capped(wchar_t *wstr, int cap);
void		ft_putwstr_capped(t_options *options, wchar_t *wstr,
				int cap);

/*
** ft_printf.c
*/
int			ft_printf(const char *str, ...);
int			ft_dprintf(int fd, const char *str, ...);

#endif
