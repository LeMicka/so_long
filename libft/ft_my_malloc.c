/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:59:12 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/17 16:00:31 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*my_malloc(size_t size, const char *file, int line, const char *f)
{
	void	*p;

	p = malloc(size);
	printf("Allocated = %s, %i, %s, %p[%li]\n", file, line, f, p, size);
	return (p);
}
