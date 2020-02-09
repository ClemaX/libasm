/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   diff.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:53:19 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 17:54:43 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DIFF_H
# define DIFF_H

# include <strings.h>

int	diff_s(const char *got, const char *expected);
int	diff_p(void *got, void *expected);
int	diff_i(int got, int expected);
int	diff_size(size_t got, size_t expected);
int	diff_ssize(ssize_t got, ssize_t expected);
int	diff_bool(const char *label, char got, char expected);

#endif