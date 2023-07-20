/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouidriss <ouidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:32:26 by ouidriss          #+#    #+#             */
/*   Updated: 2023/06/14 11:42:53 by ouidriss         ###   ########.fr       */
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

int	find_max_reverse_mode(int *a, int start)
{
	int	i;
	int	j;

	i = start;
	j = i;
	while (i >= 0)
	{
		if (a[i] > a[j])
			j = i;
		i --;
	}
	return (j);
}

void	select_sort(int *a, int size_of_array)
{
	int	i;
	int	j;

	i = size_of_array - 1;
	j = 0;
	while (i >= 0)
	{
		j = find_max_reverse_mode(a, i);
		swap(a, i, j);
		i --;
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