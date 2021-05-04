#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	printf("\n In ascending order: \n");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	
	printf("\n");
}

int main()
{
	srand((int)time(0));
	double time_spent = 0.0;
	clock_t start, end;
	start = clock();
	int n = 100;
	int arr[100];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (n * 10);
	}

	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);
	end = clock();
	time_spent += (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n\n Time = %f seconds", (time_spent));
	return 0;
}