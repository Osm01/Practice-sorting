/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:15:00 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/14 11:30:19 by ouidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *a, int x, int y)
{
	int	tmp;

	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

int	find_min_to_swap(int *a, int start, int end)
{
	int	i;
	int	j;

	i = start;
	j = i;
	while (i < end)
	{
		if (a[i] > a[j])
			j = i;
		i ++;
	}
	return (j);
}

void	select_sort(int *a, int size_of_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size_of_array)
	{
		j = find_min_to_swap(a, i, size_of_array);
		swap(a, i, j);
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
	// test
	int	a[] = {2,1,3,9,10,4,5,0};
	int	size_of_array = sizeof(a) / sizeof(a[0]);
	display(a, size_of_array);
	printf("After sorting \n");
	select_sort(a, size_of_array);
	display(a, size_of_array);
	return 0;
}
