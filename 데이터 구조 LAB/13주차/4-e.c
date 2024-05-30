#include <stdio.h>

void preorder(int T[], int i)
{
    if (i >= 16 || T[i] == 0)
        return;

    printf("%d ", T[i]);
    preorder(T, i * 2);
    preorder(T, i * 2 + 1);
}

void inorder(int T[], int i)
{
    if (i >= 16 || T[i] == 0)
        return;

    inorder(T, i * 2);
    printf("%d ", T[i]);
    inorder(T, i * 2 + 1);
}

void postorder(int T[], int i)
{
    if (i >= 16 || T[i] == 0)
        return;

    postorder(T, i * 2);
    postorder(T, i * 2 + 1);
    printf("%d ", T[i]);
}

int main(void)
{
    int t[16] = { 0, 1, 2, 3, 4, 5, 6, 0, 0, 7, 8, 0, 0, 9, 0, 0 };

    printf("preorder: ");
    preorder(t, 1);
    printf("\n");

    printf("inorder: ");
    inorder(t, 1);
    printf("\n");

    printf("postorder: ");
    postorder(t, 1);
    printf("\n");

    return 0;
}
