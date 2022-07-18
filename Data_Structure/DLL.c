#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

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
			printf("���� ����� ���� �Է��ϼ��� : ");
			scanf("%d", &data);
			delete_node(data);
			printf("\n");
			break;
		case 3: // append_node
			printf("������ ��ġ, ���� �Է��ϼ��� : ");
			scanf("%d %d", &location, &data);
			append_node(location, data);
			printf("\n");
			break;
		case 4: // print_nodes
			print_nodes();
			break;
		case 0: // exit
			destroy_all_nodes();
			print_nodes();
			return 0;
		default:
			printf("\nWrong Input\n\n\n");
			break;
		}
	}
}
