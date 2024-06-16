#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef double element;

typedef struct
{
    element stk[MAX_SIZE];
    int top;
} stack_Type;

typedef struct TreeNode
{
    double data;
    struct TreeNode* left, * right;
} TreeNode;

void init(stack_Type* s)
{
    s->top = -1;
}

int is_empty(stack_Type* s)
{
    return (s->top == -1);
}

int is_full(stack_Type* s)
{
    return (s->top == (MAX_SIZE - 1));
}

void push(stack_Type* s, element value)
{
    if (!is_full(s))
        s->stk[++(s->top)] = value;
    else
    {
        fprintf(stderr, "스택이 가득 찼습니다.\n");
        exit(1);
    }
}

element pop(stack_Type* s)
{
    if (!is_empty(s))
        return s->stk[(s->top)--];
    else
    {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
}

element peek(stack_Type* s)
{
    if (!is_empty(s))
        return s->stk[(s->top)];
    else
    {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
}

int PIS(char op)
{
    switch (op)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int PIE(char op)
{
    switch (op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 4;
        case '(':
            return 5;
    }
    return -1;
}

int is_operator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

char get_token(char exp[], int* pos)
{
    char token = exp[(*pos)++];
    while (isspace(token))
        token = exp[(*pos)++];
    return token;
}

double compute(double x, char op, double y)
{
    switch (op)
    {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '^':
            return pow(x, y);
        default:
            printf("유효하지 않은 연산자입니다.\n");
            return 0;
    }
}

typedef struct Stack
{
    TreeNode* nodes[MAX_SIZE];
    int top;
} Stack;

void InitStack(Stack* stack)
{
    stack->top = -1;
}

int IsEmpty(Stack* stack)
{
    return stack->top == -1;
}

int IsFull(Stack* stack)
{
    return stack->top == MAX_SIZE - 1;
}

void Push(Stack* stack, TreeNode* node)
{
    if (!IsFull(stack))
        stack->nodes[++(stack->top)] = node;
    else
        printf("스택이 포화 상태입니다.\n");
}

TreeNode* Pop(Stack* stack)
{
    if (!IsEmpty(stack))
        return stack->nodes[(stack->top)--];
    else
    {
        printf("스택이 공백 상태입니다.\n");
        return NULL;
    }
}

TreeNode* newNode(double data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void get_exp(char* exp)
{
    printf("식 입력: ");
    fgets(exp, MAX_SIZE, stdin);
}

void postfix(char exp[], char post[])
{
    stack_Type s;
    init(&s);
    int i = 0, j = 0;
    char top_op;
    char token;

    while ((token = get_token(exp, &i)) != '\0')
    {
        if (isdigit(token))
        {
            while (isdigit(token))
            {
                post[j++] = token;
                token = get_token(exp, &i);
            }
            post[j++] = ' ';
            i--;
        }
        else if (is_operator(token))
        {
            while (!is_empty(&s) && PIS(peek(&s)) >= PIE(token))
                post[j++] = pop(&s);
            push(&s, token);
        }
        else if (token == '(' || token == '{' || token == '[')
            push(&s, token);
        else if (token == ')' || token == '}' || token == ']')
        {
            switch (token)
            {
                case ')':
                    top_op = pop(&s);
                    while (!is_empty(&s) && top_op != '(')
                    {
                        post[j++] = top_op;
                        top_op = pop(&s);
                    }
                    break;
                case '}':
                    top_op = pop(&s);
                    while (!is_empty(&s) && top_op != '{')
                    {
                        post[j++] = top_op;
                        top_op = pop(&s);
                    }
                    break;
                case ']':
                    top_op = pop(&s);
                    while (!is_empty(&s) && top_op != '[')
                    {
                        post[j++] = top_op;
                        top_op = pop(&s);
                    }
                    break;
            }
        }
    }

    while (!is_empty(&s))
        post[j++] = pop(&s);
    post[j] = '\0';
}

TreeNode* const_exptree(char post[])
{
    Stack stack;
    InitStack(&stack);
    int length = strlen(post);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(post[i]))
        {
            double num = 0;
            while (i < length && isdigit(post[i]))
            {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            i--;
            Push(&stack, newNode(num));
        }
        else if (is_operator(post[i]))
        {
            TreeNode* node = newNode(post[i]);
            node->right = Pop(&stack);
            node->left = Pop(&stack);
            Push(&stack, node);
        }
    }
    return Pop(&stack);
}

double eval(TreeNode* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;

    double left_val = eval(root->left);
    double right_val = eval(root->right);
    return compute(left_val, root->data, right_val);
}

int main(void)
{
    char exp[MAX_SIZE];
    char post[MAX_SIZE];
    TreeNode* T = NULL;
    double result;

    get_exp(exp);
    exp[strcspn(exp, "\n")] = '\0';
    postfix(exp, post);
    T = const_exptree(post);
    result = eval(T);
    printf("%s = %lf\n", exp, result);

    return 0;
}
