#include <stdio.h>
#define MAX 100

typedef int element;
typedef struct {
	element data[MAX];
	int size;
} ArrayListType;

void init(ArrayListType* list)
{
	list->size = 0;
}

int is_empty(ArrayListType list)
{
	return list.size == 0;
}

int is_full(ArrayListType list)
{
	return list.size == MAX;
}

void insert_first(ArrayListType* list, int item)
{
	if (!is_full(*list))
	{
		for (int i = list->size; i > 0; i--)
			list->data[i] = list->data[i - 1];
		list->data[0] = item;
		list->size++;
	}
	else
	{
		fprintf(stderr, "리스트가 가득 찼습니다.\n");
		exit(0);
	}
}

void insert(ArrayListType* list, int pos, int item)
{
	if (!is_full(*list) && (pos >= 0) && (pos <= list->size))
	{
		for (int i = list->size; i > pos; i--)
			list->data[i] = list->data[i - 1];
		list->data[pos] = item;
		list->size++;
	}
	else
	{
		fprintf(stderr, "리스트가 가득 찼습니다.\n");
		exit(0);
	}
}

element delete(ArrayListType* list, int pos)
{
	if (!is_empty(*list) && (pos >= 0) && (pos < list->size))
	{
		int temp = list->data[pos];
		for (int i = pos; i < list->size - 1; i++)
			list->data[i] = list->data[i + 1];
		list->size--;
		return temp;
	}
	else
	{
		fprintf(stderr, "리스트가 비었습니다.\n");
		exit(0);
	}
}

element delete_first(ArrayListType* list)
{
	if (!is_empty(*list))
	{
		int temp = list->data[0];
		for (int i = 0; i < list->size; i++)
			list->data[i] = list->data[i + 1];
		list->size--;
		return temp;
	}
	else
	{
		fprintf(stderr, "리스트가 비었습니다.\n");
		exit(0);
	}
}

void print_list(ArrayListType list)
{
	for (int i = 0; i < list.size; i++)
		printf("%d ", list.data[i]);
}

int main(void)
{
	ArrayListType list;

	init(&list); // 리스트 초기화

	insert_first(&list, 10); 
	insert_first(&list, 20); // 리스트의 첫 번째 위치에 항목 추가
	insert_first(&list, 30);
	insert(&list, 0, 40);
	insert(&list, 1, 50);

	delete_first(&list); // 리스트의 첫번째 위치한 항목 삭제
	delete(&list, 1); // 리스트의 인덱스 1에 위치한 항목 삭제

	print_list(list); // 리스트에 포함된 

	return 0;
}
