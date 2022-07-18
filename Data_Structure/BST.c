#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* right;
	struct node* left;
};

struct node* root;

void addToBST(int _data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _data;
	new_node->right = new_node->left = 0;

	if (root == 0)
	{
		root = new_node;
	}
	else
	{
		struct node* temp = root;

		while (1)
		{
			if (_data > temp->data)
			{
				if (temp->right == 0)
				{
					temp->right = new_node;
					return;
				}

				temp = temp->right;
			}
			else
			{
				if (temp->left == 0)
				{
					temp->left = new_node;
					return;
				}

				temp = temp->left;
			}
		}
	}
}

void inorder_traversal(struct node* _r)
{
	if (_r == 0)
	{
		return;
	}

	inorder_traversal(_r->left);

	if (_r == root)
	{
		printf("%d(root) ", _r->data);
	}
	else
	{
		printf("%d ", _r->data);
	}

	inorder_traversal(_r->right);
}

void delFromBST(int _data)
{
	struct node* t = root;
	struct node* t_p = 0;

	while (1)
	{
		if (t == 0)
		{
			return;
		}
		else if (t->data == _data)
		{
			if (t->left == 0 && t->right == 0)
			{
				if (t == root)
				{
					root = 0;
					free(t);
					return;
				}

				if (t_p->left == t)
				{
					t_p->left = 0;
				}
				else
				{
					t_p->right = 0;
				}

				free(t);
				return;
			}
			else if (t->left != 0 && t->right == 0)
			{
				if (t == root)
				{
					root = t->left;

					free(t);
					return;
				}

				if (t_p->left == t)
				{
					t_p->left = t->left;
				}
				else
				{
					t_p->right = t->left;
				}

				free(t);
				return;
			}
			else if (t->left == 0 && t->right != 0)
			{
				if (t == root)
				{
					root = t->right;

					free(t);
					return;
				}

				if (t_p->left == t)
				{
					t_p->left = t->right;
				}
				else
				{
					t_p->right = t->right;
				}

				free(t);
				return;
			}
			else // t->left != 0 && t->right != 0
			{
				struct node* r = t->right;
				struct node* r_p = t;

				while (r->left != 0)
				{
					r_p = r;
					r = r->left;
				}

				t->data = r->data;

				if (r_p->left == r)
				{
					r_p->left = r->right;
				}
				else
				{
					r_p->right = r->right;
				}

				free(r);
				return;
			}
		}
		else
		{
			if (_data > t->data)
			{
				t_p = t;
				t = t->right;
			}
			else
			{
				t_p = t;
				t = t->left;
			}
		}
	}
}

int main(void)
{
	addToBST(100);
	addToBST(50);
	addToBST(200);
	addToBST(25);
	addToBST(75);
	addToBST(150);
	addToBST(250);

	inorder_traversal(root);
	printf("\n");

	delFromBST(100);
	delFromBST(25);
	delFromBST(200);

	inorder_traversal(root);
	printf("\n");

	return 0;
}