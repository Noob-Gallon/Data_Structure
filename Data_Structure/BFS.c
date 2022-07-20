#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element; // -> �̰� �� ��?

typedef struct { // ť Ÿ��
	element  queue[MAX_QUEUE_SIZE]; 
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ť �ʱ�ȭ
void queue_init(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear); // front == rear
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
	// (rear+1) % Queue_Size == front, Circular Queue
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; // �̰� �׳� graph?
} GraphType;

int visited[MAX_VERTICES]; // visited

// �׷��� �ʱ�ȭ 
void graph_init(GraphType* g)
{
	g->n = 0;

	// �׷����� ��� 0���� �ʱ�ȭ.
	for (int i = 0; i < MAX_VERTICES; i++)
		for (int j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = 0;
}
// ���� ���� ����
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}

	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}
void bfs_mat(GraphType* g, int v)
{
	int w;
	QueueType q;

	queue_init(&q);     // ť �ʱ�ȭ
	visited[v] = TRUE;          // ���� v �湮 ǥ�� 
	printf("%d  �湮 -> ", v);
	enqueue(&q, v);			// ���� ������ ť�� ���� 

	while (!is_empty(&q)) { 
		// ť�� ������� ������ �ݺ����� ����

		v = dequeue(&q);		// ť�� ���� ���� 

		for (w = 0; w < g->n; w++)	// ���� ���� Ž��
		{
			if (g->adj_mat[v][w] && !visited[w])
				// dequeue�� vertex v�� ����Ǿ� �ְ�,
				// �� vertex�� �湮���� ���� vertex���,
			{
				visited[w] = TRUE;    // �湮 ǥ��
				printf("%d �湮 -> ", w);
				enqueue(&q, w); 	// �湮�� ������ ť�� ����
			}
		}
	}
}

int main(void)
{
	GraphType* g;
	// GraphType�� Vertex�� ������ graph�� ���� ����ü
	// �����Ҵ��� ���� ������ �������ش�.

	g = (GraphType*)malloc(sizeof(GraphType));

	// GraphType g�� �ʱ�ȭ
	graph_init(g);

	// vertex ���� �߰�
	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);

	// vertex���� Edege �߰�(Undirected)
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

	bfs_mat(g, 0);
	printf("\n");

	free(g);
	return 0;
}