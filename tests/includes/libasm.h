/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libasm.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:05:10 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/03/03 22:24:02 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <list.h>
# include <strings.h>
# include <stdlib.h>

size_t	ft_strlen(const char *rdi);
char	*ft_strcpy(const char *rdi, const char *rsi);
int		ft_strcmp(const char *rdi, const char *rsi);
ssize_t	ft_write(int edi, const void *rsi, int rdx);
ssize_t	ft_read(int edi, void *rsi, int rdx);
char	*ft_strdup(const char *rdi);

int		ft_atoi_base(const char *str, const char *base);
int		ft_list_push_front(t_list **lst, void *data);
int		ft_list_size(t_list *lst);

#endif
