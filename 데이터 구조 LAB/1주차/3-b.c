#include <stdio.h>
#define SIZE 10
void swap(int *pa, int *pb);

int main(void)
{
    int i, j, r, min;
    int num[SIZE] = { 89, 45, 33, 56, 91, 12, 7, 1, 61, 20 };
    
    printf("선택정렬 전 : ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", num[i]);
    printf("\n");
    
    for (i = 0; i < SIZE; i++)
    {
        min = num[i]; // 최솟값을 배열의 시작하는 값(i)으로 설정(ex. i = 0일 때는 num[0]이 최솟값, i = 1일 때는 num[1]이 최솟값 ...)
        r = i; // 최솟값 인덱스를 시작하는 값(i)으로 변경
        
        for (j = i; j < SIZE; j++)
        {
            if (num[j] < min) // min보다 크지 않다면
            {
                min = num[j]; // 해당 값을 min에 넣기
                r = j; // 최솟값의 인덱스 기록
            }
        }
        swap(&num[i], &num[r]); // 함수 swap을 통해서 i번째 값과, 최솟값의 위치를 서로 변경
    }
    
    printf("선택정렬 후 : ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", num[i]);
    printf("\n");
    
    return 0;
}

void swap(int *pa, int *pb)
{
    int tmp;
    
    tmp = *pb;
    *pb = *pa;
    *pa = tmp;
}
