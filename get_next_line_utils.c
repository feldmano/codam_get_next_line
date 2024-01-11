/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelman <opelman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 19:01:01 by opelman       #+#    #+#                 */
/*   Updated: 2023/12/18 19:26:56 by opelman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_alloc(size_t size)
{
	char	*out;
	size_t	i;

	i = 0;
	out = malloc(size);
	if (out == NULL)
		return (NULL);
	while (i < size)
	{
		out[i] = '\0';
		i++;
	}
	return (out);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	slen;
	size_t	net_size;

	if (dst == NULL || src == NULL)
		return (0);
	slen = ft_strlen(src);
	net_size = size - 1;
	if (size == 0)
		return (slen);
	if (size > slen)
		net_size = slen;
	ft_memmove(dst, src, net_size);
	*(dst + net_size) = '\0';
	return (slen);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;
	size_t			i;

	temp_src = src;
	temp_dest = dest;
	if (src < dest)
	{
		while (n > 0)
		{
			*(temp_dest + n - 1) = *(temp_src + n - 1);
			n--;
		}
	}
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(temp_dest + i) = *(temp_src + i);
			i++;
		}
	}
	return (dest);
}

size_t	ft_strlen(void *c)
{
	size_t	len;
	char	*temp;

	len = 0;
	temp = (char *)c;
	if (temp == NULL)
		return (0);
	while (temp[len] != '\0')
		len ++;
	return (len);
}

char	*ft_strchr(void *s, int c)
{
	char	*a;
	char	c_char;

	if (s == NULL)
		return (NULL);
	a = (char *)s;
	c_char = (char)c;
	if (c_char == '\0')
		return (a + ft_strlen(s));
	while (*a != '\0')
	{
		if (*a == c_char)
			return (a);
		a++;
	}
	return (NULL);
}
