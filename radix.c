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

int maxInt(int* array, int n) {
	int out = array[0];
	for (int i = 0; i < n; i++){
		if (array[i] > out) {
	      		out = array[i];
	      	}
	}
	return out;
}


void countingSort(int* arr, int n, int exp) {
	int output[n];
	int i, count[10] = {0};

	for(i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
	int m = maxInt(arr,n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countingSort(arr,n,exp);
}


int main() {
	int n = 1000000;

	double t = wtime();

	int* array = calloc(n, sizeof(uint32_t));
	for (int i = 0; i < n; i++)
	{
		array[i] = getrand(0, 100000);
	}
	radixsort(array,n);

	for(int i = 0; i < n; ++i)
	{
		printf("%d ", array[i]); 
	}
	printf("\n");

	t = wtime() - t;

	printf("time = %lf\n", t);

}
