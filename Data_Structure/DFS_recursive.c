#include <stdio.h>

int graph[9][9];
int visited[9];

void DFS(int cur, int n)
{
	visited[cur] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (graph[cur][i] == 1 && visited[i] == 0)
		{
			printf("%d\n", i);
			DFS(i, n);
		}
	}
}

int main(void)
{
	int start = 1;

	graph[1][2] = 1;
	graph[2][1] = 1;

	graph[1][3] = 1;
	graph[3][1] = 1;

	graph[3][4] = 1;
	graph[4][3] = 1;

	graph[3][5] = 1;
	graph[5][3] = 1;

	graph[4][5] = 1;
	graph[5][4] = 1;

	graph[1][8] = 1;
	graph[8][1] = 1;

	graph[2][7] = 1;
	graph[7][2] = 1;

	graph[7][8] = 1;
	graph[8][7] = 1;

	graph[7][6] = 1;
	graph[6][7] = 1;

	printf("%d\n", start);
	DFS(start, 8);

	return 0;
}