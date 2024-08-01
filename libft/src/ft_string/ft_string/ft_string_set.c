/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:17:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:35:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_set(t_string *str, const char *new_str)
{
	return (ft_string_set_n(str, new_str, ft_strlen(new_str) + 1));
}

int	ft_string_set_n(t_string *str, const char *new_str, size_t n)
{
	size_t	new_len;

	new_len = ft_strlen(new_str) + 1;
	if (new_len > n)
		new_len = n;
	if (new_len > str->capacity)
	{
		str->str = ft_realloc(str->str, new_len, str->capacity);
		if (str->str == NULL)
			return (0);
		str->capacity = new_len;
	}
	ft_memcpy(str->str, new_str, new_len - 1);
	str->str[new_len - 1] = '\0';
	str->length = new_len - 1;
	return (1);
}

int	ft_string_set_inplace(t_string *str, char *new_str)
{
	size_t	new_len;

	new_len = ft_strlen(new_str);
	str->length = new_len;
	if (str->str)
		free(str->str);
	str->str = new_str;
	str->capacity = new_len + 1;
	return (1);
}
