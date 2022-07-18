#define _CRT_SECURE_NO_WARNINGS
#define STK_SIZE 10

#include <stdio.h>

int stack[STK_SIZE];
int top = -1;

void push(int _data)
{
	if (top == STK_SIZE - 1)
	{
		return;
	}

	top++;
	stack[top] = _data;
	printf("Enqueued : %d\n", stack[top]);
}

int pop(void)
{
	if (top == -1)
	{
		return -999;
	}

	int ret = stack[top];
	top--;
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

		push(data);
	}

	while (top > -1)
	{
		printf("Dequeued : %d\n", pop());
	}

	return 0;
}