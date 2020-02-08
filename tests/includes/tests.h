/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 06:49:04 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 18:27:21 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <unistd.h>

# define RESET	"\033[0m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define CYAN	"\033[0;36m"
# define TITLE	"\033[1;34m"
# define PASS	GREEN"✔"RESET
# define FAIL	RED"✗"RESET
# define BULLET	CYAN"▶"RESET

int		diff_s(const char *got, const char *expected);
int		diff_p(void *got, void *expected);
int		diff_i(int got, int expected);
int		diff_size(size_t got, size_t expected);
int		diff_ssize(ssize_t got, ssize_t expected);
int		run_test(char *label, int fw, int (*test)());

char	*rand_key(int len);
char	*rand_val(int len);
char	**rand_tab_map(int count, int len);

#endif
