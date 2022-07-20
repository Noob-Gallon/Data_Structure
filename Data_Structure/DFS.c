#include <stdio.h>

#define NV 9

int visited[NV] = { 0 };

int stack[NV];
int top = -1;

void addEdge(int graph[][NV], int v1, int v2)
{
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
}

void push(int _v)
{
	if (top == NV - 1)
		return;

	top++;
	stack[top] = _v;
}

int pop()
{
	if (top == -1)
	{
		return -999;
	}

	int ret = stack[top];
	top--;
	return ret;
}

int inStack(int _v)
{
	for (int i = 0; i <= top; i++)
	{
		if (stack[i] == _v)
		{
			return 1;
		}
	}

	return 0;
}

void Check_Next_Vertex(int graph[][NV], int v)
{
	for (int i = NV-1; i > 0; i--)
	{
		if (graph[v][i] == 1)
		{
			if (inStack(i) == 0 && visited[i] == 0)
			{
				push(i);
			}
		}
	}
}

void DFS(int graph[][NV], int start_vertex)
{
	push(start_vertex);

	while (1)
	{
		int v = pop();

		if (v == -999)
			break;

		visited[v] = 1;
		printf("%d\n", v);
	
		Check_Next_Vertex(graph, v);
	}
}

int main(void)
{
	int graph[NV][NV] = { 0 };

	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 3, 4);
	addEdge(graph, 3, 5);
	addEdge(graph, 4, 5);
	addEdge(graph, 2, 7);
	addEdge(graph, 1, 8);
	addEdge(graph, 7, 8);
	addEdge(graph, 6, 7);

	DFS(graph, 1);

	return 0;
}