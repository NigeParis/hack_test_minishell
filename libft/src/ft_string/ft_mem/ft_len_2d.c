/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:41:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 19:18:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_len_2d(const void *const *array)
{
	size_t	len;

	len = 0;
	while (array[len] != NULL)
		len++;
	return (len);
}
