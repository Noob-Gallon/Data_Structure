#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define QUE_SZ 5 

// ���� ������� QUE_SZ - 1. ��, �� Queue���� �ִ� 4���� ����ȴ�.
// �ֳ��ϸ� ������ Queue�� Circular Queue�̹Ƿ�,
// (rear+1) % QUE_SZ == front�� ��� enqueue�� return�Ѵ�.
// ��, QUE_SZ�� 5�� ��, 4���� ���Ұ� ����� ���¿��� rear == 4.
// (4 + 1) % QUE_SZ == front(0)�̹Ƿ�, ���Ҹ� QUE_SZ - 1 ��ŭ ���尡�� �ϴ�.

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