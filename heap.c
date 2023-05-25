#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int N, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int rigth = 2 * i +2;

	if (left < N && arr[left] > arr[largest])
		largest = left;
	if (rigth < N && arr[rigth] > arr[largest])
		largest = rigth;
	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		heapify(arr, N, largest);
	}
}

void heapSort(int arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	

	for (int i = N - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);

		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{

    int n = 50000;

    double t = wtime();

    int* array = calloc(n, sizeof(uint32_t));
    for (int i = 0; i < n; i++)
    {
        array[i] = getrand(0, 100000);
    }

	heapSort(array, n);
	printf("Sorted array is \n");
	printArray(array, n);

    t = wtime() - t;

    printf("time = %lf\n", t);
}
