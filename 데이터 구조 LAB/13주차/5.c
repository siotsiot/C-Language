#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
} TreeNode;

void preorder(TreeNode* root) // 전위 순회
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode* root) // 중위 순회
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);		
	}
}

void postorder(TreeNode* root) // 후위 순회
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int main(void)
{
	TreeNode* n1, * n2, * n3, * n4, * n5, * n6, * n7, * n8, * n9;

	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n6 = (TreeNode*)malloc(sizeof(TreeNode));
	n7 = (TreeNode*)malloc(sizeof(TreeNode));
	n8 = (TreeNode*)malloc(sizeof(TreeNode));
	n9 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 1;
	n1->left = n2;
	n1->right = n3;

	n2->data = 2;
	n2->left = n4;
	n2->right = n5;

	n3->data = 3;
	n3->left = n6;
	n3->right = NULL;

	n4->data = 4;
	n4->left = NULL;
	n4->right = n7;

	n5->data = 5;
	n5->left = n8;
	n5->right = NULL;

	n6->data = 6;
	n6->left = NULL;
	n6->right = n9;

	n7->data = 7;
	n7->left = NULL;
	n7->right = NULL;

	n8->data = 8;
	n8->left = NULL;
	n8->right = NULL;

	n9->data = 9;
	n9->left = NULL;
	n9->right = NULL;

	preorder(n1);
	printf("\n");

	inorder(n1);
	printf("\n");

	postorder(n1);
	printf("\n");

	free(n1); free(n2); free(n3); free(n4); free(n5); free(n6); free(n7); free(n8); free(n9);

	return 0;
}
