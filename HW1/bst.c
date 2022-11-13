#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node *right, *left;
};

struct Node* createNode(int num)
{
	struct Node *temp = malloc(sizeof(struct Node)); 
	temp->value = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct Node* insert(struct Node* root, int num)
{
	if(root == NULL)
	{
		struct Node *temp = createNode(num);
		return temp;
	}

	else if(num == root->value)
	{
		return root;
	}

	else if(num > root->value)
        {
                root->right = insert(root->right, num);
        }

	else if(num < root->value)
	{
		root->left  = insert(root->left, num);
	}	

	return root;
}

void inorder(struct Node* root)
{
	if(root != 0)
	{
		inorder(root->left);
		//printf("here\n");
		printf("%d\t", root->value);
		//printf("here\n");
		inorder(root->right);
	}
}

void freeTheNode(struct Node* root)
{
	if (root == NULL) 
	{
		return;
	}
	
	struct Node* right = root->right;
	struct Node* left = root->left;
	
	free(root);
	freeTheNode(right);
	freeTheNode(left);
}

int main(int argc, char* argv[])
{
	struct Node* root = NULL;
		
	if(argc != 2)
	{
		printf("error\n");
		return 0;
	}
	
	FILE *fp = fopen(argv[1], "r");

	if(fp == NULL)
        {
                printf("error\n");
                return 0;
        }
	
	while(1)
	{
		int x; 
		char ch;
		int n = fscanf(fp, "%c\t%d\n", &ch, &x);

		
		if(n != 2)
		{		
			break;
		}
		else
		{
			root = insert(root, x);
		}
	}	
	inorder(root);
	fclose(fp);
	freeTheNode(root);
	return 0;
}
