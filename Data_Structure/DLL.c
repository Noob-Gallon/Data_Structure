#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;
};

struct node* head = 0;

void main_screen(void);
struct node* get_prev_node(struct node* _node);
void create_node(int _data);
void delete_node(int _data);
void append_node(int _location, int _value);
void print_nodes(void);
void destroy_all_nodes(void);

int main(void)
{
	int flag = 0;
	int data;
	int location;

	while (1)
	{
		main_screen();

		scanf("%d", &flag);

		switch (flag)
		{
		case 1: // create_node
			printf("���� �Է��ϼ��� : ");
			scanf("%d", &data);
			create_node(data);
			printf("\n");
			break;
		case 2: // delete_node
			scanf("%d", &data);
			delete_node(data);
			printf("\n");
			break;
		case 3: // append_node
			scanf("%d %d", &location, &data);
			append_node(location, data);
			printf("\n");
			break;
		case 4: // print_nodes
			print_nodes();
			break;
		case 0: // exit
			destroy_all_nodes();
			return 0;
		default:
			printf("\nWrong Input\n\n\n");
			break;
		}
	}
}

void main_screen(void)
{
	printf("1 : ��� ����\n");
	printf("2 : ��� ����\n");
	printf("3 : ��� �߰�\n");
	printf("4 : ��� ���\n");
	printf("0 : ���α׷� ����(free)\n\n\n");
	printf("���ϴ� �޴��� �����ϼ���. : ");
}

struct node* get_prev_node(struct node* _node)
{
	if (head == _node)
	{
		printf("prev node�� �����ϴ�.(head)\n");
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
		printf("DLL�� ��尡 �����ϴ�.\n");
		return;
	}

	struct node* temp = head;

	// head->data == _data�� ���
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

	// �װ� �ƴҰ��, Ž���Ѵ�.

	temp = temp->next;

	while (temp != 0)
	{
		if (temp->data == _data)
		{
			struct node* temp_prev = get_prev_node(temp);
			
			temp_prev->next = temp->next;
			temp->next->prev = temp_prev;

			free(temp);
			return;
		}

		temp = temp->next;
	}

	// ������� ���Դٴ� ����, ���� ��尡 ���ٴ� ��.

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
