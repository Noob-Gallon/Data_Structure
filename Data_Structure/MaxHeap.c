#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define HP_LEN 10 // 0번 Index는 사용하지 않으므로, 실제 Heap의 크기는 9이다.

int Heap[HP_LEN];
int heap_size = 0; // 현재 heap의 크기

void enqueue(int _data)
{
	if (heap_size == HP_LEN - 1)
	{
		return;
	}

	heap_size++;
	Heap[heap_size] = _data;

	int me = heap_size;
	int parent = me / 2;

	while (1)
	{
		if (me == 1)
		{
			return;
		}

		if (Heap[me] > Heap[parent])
		{
			int temp = Heap[me];
			Heap[me] = Heap[parent];
			Heap[parent] = temp;

			me = parent;
			parent = me / 2;
		}
		else
		{
			return;
		}
	}
}

int find_Replacer(int _me)
{
	int left = _me * 2;
	int right = left + 1;

	if (left > heap_size)
	{
		return 0;
	}

	if (right > heap_size)
	{
		return left;
	}
	else
	{
		// Max Heap에서는 자신의 자리를 찾아갈 때
		// 자식 중에서 더 큰 것과 비교해야한다.
		// 따라서 자식이 두 개 있다면 그 중 우선순위가 큰 것과 비교.

		if (Heap[left] > Heap[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}

}

int dequeue(void)
{
	if (heap_size == 0)
	{
		return -999;
	}

	int ret = Heap[1];

	// Priority Queue는 반드시
	// 첫 번째 원소가 먼저 dequeue된다.
	// (Max or Min)

	Heap[1] = Heap[heap_size];
	heap_size--;

	int me = 1;

	while (1)
	{
		int replacer = find_Replacer(me);

		if (replacer == 0)
		{
			return ret;
		}

		if (Heap[replacer] > Heap[me])
		{
			int temp = Heap[replacer];
			Heap[replacer] = Heap[me];
			Heap[me] = temp;

			me = replacer;
		}
		else
		{
			return ret;
		}
	}
}

int main(void)
{
	int data;

	while (1)
	{
		scanf("%d", &data);

		if (data < 0)
		{
			break;
		}

		enqueue(data);
	}

	while (heap_size > 0)
	{
		printf("%d ", dequeue());
	}

	return 0;
}
