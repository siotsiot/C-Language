#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left, * right;
	int is_thread;
} TreeNode;

TreeNode* make_node(int data, int is_thread)
{
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->is_thread = is_thread;

	return new_node;
}

TreeNode* cons_thread_tree()
{
	TreeNode* root = NULL;
	root = make_node(1, 0);
	root->left = make_node(2, 0);
	root->left->left = make_node(4, 0);
	root->left->left->right = make_node(7, 1);
	root->left->left->right->right = root->left;
	
	root->left->right = make_node(5, 1);
	root->left->right->right = root;
	root->left->right->left = make_node(8, 1);
	root->left->right->left->right = root->left->right;

	root->right = make_node(3, 0);
	root->right->left = make_node(6, 0);
	root->right->left->right = make_node(9, 1);
	root->right->left->right->right = root->right;

	return root;
}

TreeNode* inorder_successor(TreeNode *T)
{
	if (T->is_thread == 1)
		return T->right;
	if (T->right == NULL)
		return NULL;
	else
		T = T->right;
	TreeNode* p = T;
	while (p->left != NULL)
		p = p->left;
	return p;
}

TreeNode* thread_inorder(TreeNode* T)
{
	if (T == NULL) return T;
	TreeNode* p = T;
	while (p->left != NULL)
		p = p->left;
	do
	{
		printf("%d ", p->data);
		p = inorder_successor(p);
	}
	while (p != NULL);
}

int main(void)
{
	TreeNode* T;

	T = cons_thread_tree();
	thread_inorder(T);

	return 0;
}
