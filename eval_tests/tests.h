/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:37:37 by saaltone          #+#    #+#             */
/*   Updated: 2022/02/28 17:54:34 by saaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# define COLOR_GREEN "\033[0;32m"
# define COLOR_YELLOW "\033[0;33m"
# define COLOR_RED "\033[0;31m"
# define COLOR_PURPLE "\033[0;35m"
# define COLOR_CYAN "\033[0;36m"
# define COLOR_RESET "\033[0m"

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>
# include <string.h>

FILE	*ob;
int		stdout_backup;
va_list va_backup;

int		ft_printf(const char *format, ...);
void	save_input(const char *format, ...);
void	printf_compare();
char	*printf_format;
FILE	*ob_start();
char	*ob_end();
int		return_printf;
int		return_ft_printf;
char	*output_printf;
char	*output_ft_printf;

# define printf_tester(...) \
	save_input(__VA_ARGS__); \
	ob_start(); \
	printf(__VA_ARGS__); \
	output_printf = ob_end(); \
	ob_start(); \
	ft_printf(__VA_ARGS__); \
	output_ft_printf = ob_end(); \
	printf_compare(); \
	free(printf_format); \
	free(output_printf); \
	free(output_ft_printf);
#endif