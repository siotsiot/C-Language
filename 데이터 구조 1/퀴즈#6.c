#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int key;
	struct node* link;
} node;

// a번 문제
node* cons_list()
{
	node* head = NULL;
	node* temp;

	srand(time(NULL));

	for (int i = 0; i < 20; i++)
	{
		int random_number = rand() % 10 + 1;

		temp = (node*)malloc(sizeof(node));
		temp->key = random_number;
		temp->link = NULL;

		temp->link = head;
		head = temp;
	}
	return head;
}

// b번 문제
void print_list(node* list)
{
	while (list != NULL)
	{
		printf("%d ", list->key);
		list = list->link;
	}
	printf("\n");
}

// c번 문제
int count(node* list, int key)
{
	int res = 0;
	while (list != NULL)
	{
		if (list->key == key)
			res++;
		list = list->link;
	}
	return res;
}

int main(void)
{
	node* list = cons_list();
	print_list(list);
	
	for (int i = 1; i <= 10; i++)
		printf("%d을 포함한 노드 개수: %d\n", i, count(list, i));

	node* temp;
	while (list != NULL)
	{
		temp = list;
		list = list->link;
		free(temp);
	}

	return 0;
}
