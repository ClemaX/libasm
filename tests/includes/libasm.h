/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libasm.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:05:10 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 17:09:20 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <string.h>

size_t	ft_strlen(const char *rdi);
char	*ft_strcpy(const char *rdi, const char *rsi);
char	*ft_strdup(const char *rdi, const char *rsi);
int		ft_strcmp(const char *rdi, const char *rsi);
ssize_t	ft_write(int edi, const void *rsi, int rdx);
ssize_t	ft_read(int edi, void *rsi, int rdx);

#endif