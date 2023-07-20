/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:07:48 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/14 12:21:09 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *a, int i, int y)
{
	int	tmp;

	tmp = a[i];
	a[i] = a[y];
	a[y] = tmp;
}

// compare with before value and swap
void	insert_(int *a, int index)
{
	int	key;
	int	y;

	key = a[index];
	y = index - 1;
	while (y >= 0 && a[y] > key)
	{
		swap(a, y + 1, y);
		key = a[y];
		y = y - 1;
	}
}

void	insertion_sort(int *a, int size_of_array)
{
	int	i;

	i = 1;
	while (i < size_of_array)
	{
		insert_(a, i);
		i ++;
	}
}

void	display(int *a, int size_of_array)
{
	int	i;

	i = 0;
	while (i < size_of_array)
	{
		printf("%d,",a[i]);
		i ++;
	}
	printf("\n");
}

int	main(int argc, char const *argv[])
{
    int	a[] = {2,1,3,9,10,4,5,0};
	int	size_of_array = sizeof(a) / sizeof(a[0]);
	display(a, size_of_array);
	printf("After sort\n");
	insertion_sort(a, size_of_array);
	display(a, size_of_array);
    return 0;
}
