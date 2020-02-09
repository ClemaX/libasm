/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tests.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 06:49:04 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 17:59:51 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <libasm.h>
# include <unistd.h>
# include <diff.h>
# include <units.h>

# define RESET	"\033[0m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define CYAN	"\033[0;36m"
# define TITLE	"\033[1;34m"
# define PASS	GREEN"✔"RESET
# define FAIL	RED"✗"RESET
# define BULLET	CYAN"▶"RESET

int				run_test(char *label, int fw, int (*test)());
void			error(void);

unsigned int	ft_rand(unsigned int min, unsigned int max);
char			*rand_key(int len);
char			*rand_val(int len);
char			**rand_tab_map(int count, int len);

#endif
