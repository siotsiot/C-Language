#include <stdio.h>

int main(void)
{
    int a[100] = { 0 };
    int b[100] = { 0 };
    int c[100] = { 0 };
    int i, j, num, tmp, k = 0, flag = 0;
    
    printf("입력할 정수의 개수(100개 이내로): ");
    scanf("%d", &num);
    
    for (i = 0; i < num; i++)
    {
        printf("%d번째의 요소를 입력하시오: ", i);
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < num; i++) // a배열에서 중복된 숫자를 제외해서 b배열에 넣기.
    {
        for (j = 0; j < i; j++)
        {
            if (a[i] != b[j])
            {
                flag = 1;
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            b[k] = a[i];
            k++;
        }
        flag = 0;
    }

    for (i = 0; i < k; i++) // b배열 오름차순 정렬.
    {
        for (j = 0; j < k - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                tmp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp;
                tmp = 0;
            }
        }
    }
    
    for (i = 0; i < k; i++) // 빈도를 c배열에 저장.
    {
        for (j = 0; j < num; j++)
        {
            if (b[i] == a[j])
                c[i]++;
        }
    }
    
    for (i = 0; i < k; i++)
    {
        printf("%d 값은 %d 번 등장\n", b[i], c[i]);
    }
    
    return 0;
}
