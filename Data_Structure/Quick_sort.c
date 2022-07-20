#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void Quick_sort(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int pivot = start;
	int low = start + 1;
	int high = end;

	while (low <= high)
	{
		// low는 pivot 값보다 큰 것을 체크한다.
		while (arr[pivot] > arr[low] && low <= end)
		{
			low++;
		}

		// high는 pivot 값보다 작은 것을 체크한다.
		while (arr[pivot] < arr[high] && high >= start+1)
		{
			high--;
		}
			
		if (low < high)
		{
			Swap(arr, low, high);
		}
	}

	Swap(arr, pivot, high);

	Quick_sort(arr, start, high - 1);
	Quick_sort(arr, high+1, end);
}

int main(void)
{


	return 0;
}