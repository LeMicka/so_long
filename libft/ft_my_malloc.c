/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:59:12 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/18 11:34:26 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//# define custom_malloc(X) my_malloc(X, __FILE__, __LINE__, __FUNCTION__)
//# define custom_free(P) my_free(P, __FILE__, __LINE__, __FUNCTION__)

void	*my_malloc(size_t size, const char *file, int line, const char *f)
{
	void	*p;

	p = malloc(size);
	printf("Allocated = %s, %i, %s, %p[%li]\n", file, line, f, p, size);
	return (p);
}
