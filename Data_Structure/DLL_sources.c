#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;
};

struct node* head = 0;

void main_screen(void)
{
	printf("1 : 노드 생성\n");
	printf("2 : 노드 제거\n");
	printf("3 : 노드 추가\n");
	printf("4 : 노드 출력\n");
	printf("0 : 프로그램 종료(free)\n\n\n");
	printf("원하는 메뉴를 선택하세요. : ");
}

struct node* get_prev_node(struct node* _node)
{
	if (head == _node)
	{
		printf("prev node가 없습니다.(head)\n");
		return;
	}

	struct node* temp = head;

	while (temp != 0)
	{
		if (temp->next == _node)
		{
			break;
		}

		temp = temp->next;
	}

	return temp;
}

struct node* get_last_node(void)
{
	struct node* temp = head;

	if (temp == 0)
	{
		return 0;
	}

	while (temp->next != 0)
	{
		temp = temp->next;
	}

	return temp;
}

void create_node(int _data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _data;
	new_node->next = new_node->prev = 0;

	if (head == 0)
	{
		head = new_node;
	}
	else
	{
		struct node* temp = head;

		while (temp->next != 0)
		{
			temp = temp->next;
		}

		temp->next = new_node;
		new_node->prev = temp;
	}
}

void delete_node(int _data)
{
	if (head == 0)
	{
		printf("DLL에 노드가 없습니다.\n");
		return;
	}

	struct node* temp = head;

	// head->data == _data일 경우
	if (head->data == _data)
	{
		head = head->next;

		if (head != 0)
		{
			head->prev = 0;
		}

		free(temp);
		return;
	}

	// 그게 아닐경우, 탐색한다.
	temp = temp->next;

	while (temp != 0)
	{
		if (temp->data == _data)
		{
			struct node* temp_prev = get_prev_node(temp);
			printf("Check\n");

			temp_prev->next = temp->next;

			if (temp->next != 0)
				temp->next->prev = temp_prev;

			free(temp);
			return;
		}

		temp = temp->next;
	}

	// 여기까지 나왔다는 것은, 지울 노드가 없다는 뜻. 그냥 return 해주면 된다.
	return;
}

void append_node(int _location, int _value)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _value;
	new_node->next = new_node->prev = 0;

	if (head->data == _location)
	{
		new_node->next = head;
		head->prev = new_node;

		head = new_node;
		return;
	}

	struct node* temp = head->next;

	while (temp != 0)
	{
		if (temp->data == _location)
		{
			struct node* temp_prev = get_prev_node(temp);

			temp_prev->next = new_node;
			temp->prev = new_node;

			new_node->next = temp;
			new_node->prev = temp_prev;

			return;
		}

		temp = temp->next;
	}

	// get_last_node() 함수를 이용해서 마지막 노드의 주소를 반환
	// 이를 이용해 _location이 탐색되지 않았을 때 _value 노드를
	// 맨 끝에 추가해준다.

	temp = get_last_node();

	temp->next = new_node;
	new_node->prev = temp;
}

void print_nodes(void)
{
	struct node* temp = head;

	printf("\n");

	while (temp != 0)
	{
		printf("%d->", temp->data);

		temp = temp->next;
	}

	printf("\n\n\n");
}

void destroy_all_nodes(void)
{
	struct node* temp = head;

	while (temp != 0)
	{
		head = head->next;

		if (head != 0)
		{
			head->prev = 0;
		}

		free(temp);
		temp = head;
	}
}