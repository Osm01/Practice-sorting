/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:38:52 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/14 16:16:16 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	display(int *a, int size_of_array)
{
	int	i;

	i = 0;
	while (i < size_of_array)
	{
		printf("%d," ,a[i]);
		i ++;
	}
	printf("\n");
}

void	_merge(int *a, int size_of_array_a, int *left_array, int *right_array)
{
	int	l;
	int	r;
	int	left_size;
	int	right_size;
	int	i;

	i = 0;
	r = 0;
	l = 0;
	left_size = size_of_array_a / 2;
	right_size = size_of_array_a - left_size;
	while (l < left_size && r < right_size)
	{
		if (left_array[l] < right_array[r])
		{
			a[i] = left_array[l];
			i ++;
			l ++;
		}
		else
		{
			a[i] = right_array[r];
			i ++;
			r ++;
		}
	}
	while (l < right_size)
	{
		a[i] = left_array[l];
		i ++;
		l ++;
	}
	while (r < right_size)
	{
		a[i] = left_array[r];
		i ++;
		r ++;
	}
}

void	merge_sort(int *a, int size_of_array)
{
	int	mid;
	int	*left_array;
	int	*right_array;
	int	i;
	int	j;

	if (size_of_array == 1)
		return ;
	i = 0;
	j = 0;
	mid = size_of_array / 2;
	left_array = (int *)malloc(sizeof(int) * mid);
	right_array = (int *)malloc(sizeof(int) * mid);
	while (i < size_of_array)
	{
		if (i < mid)
			left_array[i] = a[i];
		else
		{
			right_array[j] = a[i];
			j ++;
		}
		i ++;
	}
	merge_sort(left_array, mid);
	merge_sort(right_array, mid);
	_merge(a, size_of_array, left_array, right_array);
}

int	main(int argc, char const *argv[])
{
    int	a[] = {2,1,3,9,10,4,5,0};
	int	size_of_array = sizeof(a) / sizeof(a[0]);
	merge_sort(a, size_of_array);
	display(a, size_of_array);
    return 0;
}
