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


void oddEvenSort(int arr[], int n)
{
	int isSorted = 0;

	while (isSorted == 0)
	{
		isSorted = 1;

		for (int i = 1; i <= n-2; i=i+2)
		{
			if (arr[i] > arr[i+1])
			{
				int tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				isSorted = 0;
			}
		}

		for (int i = 0; i<=n-2; i=i+2)
		{
			if(arr[i] > arr[i+1])
			{
				int tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				isSorted = 0;
			}
		}

	}

	return;
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++){
		printf("%d\n", arr[i]);
    }

}

int main()
{
    int n = 350000;

    double t = wtime();

    int* array = calloc(n, sizeof(uint32_t));
    for (int i = 0; i < n; i++)
    {
        array[i] = getrand(0, 100000);
    }
    printf("1");


	oddEvenSort(array, n);
	printArray(array, n);

    t = wtime() - t;

    printf("time = %lf\n", t);

}

