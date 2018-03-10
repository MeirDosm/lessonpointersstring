#include <stdio.h>
#include <iostream>
#include <time.h>


void PrintMatrix(int(*pt)[2])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			/*printf("z[%d][%d] = %5d (%p) \t",
			i, j, pt[i][j], &pt[i][j]);*/

			printf("z[%d][%d] = %5d (%p) \t",
				i, j, *(*(pt + i) + j), ((pt + i) + j));
		}
		printf("\n");
	}
}

void PrintMatrix(int(*pt)[2], int row, int col)
{
	for (int i = 0; i < (row*col); i++)
	{
		printf("z = %5d (%p) \t", **(pt + i), pt + i);
	}
}

void PrintMatrix(int *p, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d\t", *(p + i*col + j));
		}
		printf("\n");
	}

}

void PrintMatrix(int *p, int col)
{
	for (int i = 0; i < col; i++)
	{
		printf("%d\t", *(p + i));
	}

}

void FillIn(int *p, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(p + i*col + j) = 1 + rand() % 5;
		}
	}
}

void FillIn(int *p, int col)
{
	for (int i = 0; i < col; i++)
	{
		*(p + i) = 1 + rand() % 10;
	}
}

int RandomNumber(int *p, int row, int col)
{
	return *(p + (0 + rand() % (row*col) + 1));
}
char result = -1;
char * ConsistOf(char *p, char *pt)
{
	int i = 0;
	int j = 0;

	while (*p != '\0')
	{
		j = 0;
		while (*pt != '\0')
		{
			if (p[i] == pt[j])
				return &p[j];
			j++;
		}
		i++;
	}

	return &result;
}

int Min(int *p, int row, int col)
{
	int min = *(p + 0 * col + 0);
	int x = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (min > *(p + i * col + j))
			{
				min = *(p + i * col + j);
				x = i;
			}

		}
	}
	return x;
}

int Sum(int *pt, int end)
{
	int sum = 0;
	for (int i = 0; i < end; i++)
	{
		sum += *(pt + i);
	}
	return sum;
}

int *Max(int *p, int col)
{
	int *max = p;
	for (int i = 0; i < col; i++)
	{
		if (*max < *(p + i))
			max = (p + i);
	}
	return max;
}

void swap(int *a, int j) {
	int temp = *(a + j);
	if (*(a + j) < *(a + j - 1)) {
		*(a + j) = *(a + j - 1);
		*(a + j - 1) = temp;
	}
}

void sortArray(int*a, int col) {
	for (int i = 0; i < col; i++) {
		for (int j = col - 1; j > i; j--)
			swap(a, j);
	}
}

int *findCouples(int *a) {
	if (*a == *(a + 1))
		return a;
	else
		return NULL;
}

void word(char *arr) {
	int start = 0, end = 0;
	while (*arr != '\0') {
		if (*arr == ' ') {
			if (compare(arr - end, arr, end) == 1)
				printf("palindrome");
		}
		end++;
		arr++;
	}
}

int compare(char *start, char *end, int count) {
	for (int i = 0; i < count / 2; i++)
	{
		if (*(start + i) == *(end - i)) {
			break;
			return 0;
		}
	}
	return 1;
}