/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:33:02 by sasha             #+#    #+#             */
/*   Updated: 2017/09/19 13:36:57 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "t_list.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define FREE_IFN_NULL(to_free) (to_free) ? free(to_free) : (0);
# define SUCCESS	0
# define FAILURE	1

void				ft_error_exit(char const *error);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelcontent(void *content, size_t content_size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_putchar(char c);
int					ft_putendl(char const *s);
void				ft_putnbr(long long n);
int					ft_putstr(char const *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				**ft_strlst_toarr(t_list *lst);
char				*ft_strdup(const char *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strsplit_free(char **arr);
int					get_next_line(const int fd, char **line);
long long			ft_atoi(const char *str);

#endif
