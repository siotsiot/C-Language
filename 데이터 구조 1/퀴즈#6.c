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
	node* head = NULL; // 초기화
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

int main(void)
{
	node* list = cons_list();
	print_list(list);

	node* temp;
	while (list != NULL)
	{
		temp = list;
		list = list->link;
		free(temp);
	}

	return 0;
}
