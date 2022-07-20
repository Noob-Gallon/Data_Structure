#include <stdio.h>
#include <stdlib.h>

void Do_Merge(int arr[], int start, int mid, int end, int tarray[])
{
	int lstart = start;
	int lend = mid;
	int rstart = mid + 1;
	int rend = end;

	int i = lstart;
	int j = rstart;
	int t = lstart;

	while (1)
	{
		if (i > lend && j > rend)
		{
			break;
		}

		if (i > lend)
		{
			tarray[t++] = arr[j++];
		}
		else if (j > rend)
		{
			tarray[t++] = arr[i++];
		}
		else
		{
			if (arr[i] < arr[j])
			{
				tarray[t++] = arr[i++];
			}
			else
			{
				tarray[t++] = arr[j++];
			}
		}
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = tarray[i];
	}
}

void Merge_sort(int arr[], int start, int end, int tarray[])
{
	if (start == end)
	{
		return;
	}

	Merge_sort(arr, start, (start + end) / 2, tarray);
	Merge_sort(arr, (start+end) / 2 + 1, end, tarray);

	Do_Merge(arr, start, (start + end) / 2, end, tarray);
}

int main(void)
{
	

	return 0;
}