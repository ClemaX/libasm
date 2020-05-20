/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libasm.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 17:05:10 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/03/11 16:14:37 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <sys/types.h>
# include <list.h>
# include <stdlib.h>
# include <errno.h>

size_t	ft_strlen(const char *rdi);
char	*ft_strcpy(const char *rdi, const char *rsi);
int		ft_strcmp(const char *rdi, const char *rsi);
ssize_t	ft_write(int edi, const void *rsi, size_t rdx);
ssize_t	ft_read(int edi, void *rsi, size_t rdx);
char	*ft_strdup(const char *rdi);

int		ft_atoi_base(const char *str, const char *base);
int		ft_list_push_front(t_list **lst, void *data);
int		ft_list_size(t_list *lst);
int		ft_list_remove_if(t_list **lst, void *ref, int (*cmp)(), void (*free_fct)(void*));

#endif
