/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:00:53 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/07/17 16:02:08 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	my_free(void *ptr, const char *file, int line, const char *func)
{
	free(ptr);
	printf("Freed = %s, %i, %s, %p\n", file, line, func, ptr);
}
