/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:16:10 by maati             #+#    #+#             */
/*   Updated: 2025/02/21 12:43:13 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "get_next_line.h"
# include "ft_printf.h"

// checks if the character is an alphabet
int		ft_isalpha(int c);

// checks if the character is a digit
int		ft_isdigit(int c);

// checks if the character is an alphabet or a digit
int		ft_isalnum(int c);

// checks if the character is an ascii character
int		ft_isascii(int c);

// checks if the character is a printable character
int		ft_isprint(int c);

// converts a lowercase character to uppercase
int		ft_toupper(int chara);

// converts an uppercase character to lowercase
int		ft_tolower(int chara);

// compares two strings
int		ft_strncmp(const char *first, const char *sec, size_t len);

// compares two memory blocks
int		ft_memcmp(const void *p1, const void *p2, size_t size);

// converts a string to an integer
int		ft_atoi(const char *str);

// returns the length of a string
size_t	ft_strlen(const char *s);

// copies a string to another string
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// concatenates two strings
size_t	ft_strlcat(char *dest, const char *src, size_t size);

// writes a character to a file descriptor
void	ft_putchar_fd(char c, int fd);

// writes a string to a file descriptor
void	ft_putstr_fd(char *s, int fd);

// writes a string followed by a newline to a file descriptor
void	ft_putendl_fd(char *s, int fd);

// writes an integer to a file descriptor
void	ft_putnbr_fd(int n, int fd);

// writes zeroes to a memory block
void	ft_bzero(void *s, size_t n);

// applies a function to each character of a string
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// writes a character to a memory block
void	*ft_memset(void *s, int c, size_t n);

// allocates memory and writes zeroes to it
void	*ft_calloc(size_t count, size_t size);

// copies a memory block to another memory block
void	*ft_memcpy(void *dest, const void *src, size_t n);

// copies a memory block to another memory block
void	*ft_memmove(void *dest, const void *src, size_t n);

// searches for a character in a memory block
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);

// searches for a character in a string
char	*ft_strchr(const char *s, int c);

// searches for a character in a string from the end
char	*ft_strrchr(const char *s, int c);

// searches for a string in another string
char	*ft_strnstr(const char *big, const char *lil, size_t len);

// duplicates a string
char	*ft_strdup(const char *s);

// extracts a substring from a string
char	*ft_substr(char const *s, unsigned int start, size_t len);

// concatenates two strings
char	*ft_strjoin(char const *s1, char const *s2);

// trims a string
char	*ft_strtrim(char const *s1, char const *set);

// converts an integer to a string
char	*ft_itoa(int n);

// applies a function to each character of a string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// splits a string into an array of strings
char	**ft_split(char const *s, char c);

#endif
