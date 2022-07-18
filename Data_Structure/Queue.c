#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define QUE_SZ 5 

// 실제 사이즈는 QUE_SZ - 1. 즉, 이 Queue에는 최대 4개만 저장된다.
// 왜냐하면 현재의 Queue는 Circular Queue이므로,
// (rear+1) % QUE_SZ == front일 경우 enqueue를 return한다.
// 즉, QUE_SZ가 5일 때, 4개의 원소가 저장된 상태에서 rear == 4.
// (4 + 1) % QUE_SZ == front(0)이므로, 원소를 QUE_SZ - 1 만큼 저장가능 하다.

int queue[QUE_SZ];
int front = 0;
int rear = 0;

void enqueue(int _data)
{
	if ((rear + 1) % QUE_SZ == front)
	{
		return;
	}

	queue[rear] = _data;
	rear = (rear + 1) % QUE_SZ;
}

int dequeue(void)
{
	if (front == rear)
	{
		return -999;
	}

	int ret = queue[front];
	front = (front + 1) % QUE_SZ;
	return ret;
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

	while (!(front == rear))
	{
		printf("%d\n", dequeue());
	}

	return 0;
}