#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int x, y, i, j, computer_x, computer_y, already = 0, flag = 0, round = 1;
    int board[3][3] = { 0 };
    
    while(1)
    {
        printf("= 사용자 차례 =\n(x, y) 좌표: ");
        scanf("%d %d", &x, &y);
        
        if (board[x][y] == 'X' || board[x][y] == 'O')
        {
            printf("이미 놓여져 있습니다.\n");
            already = 1;
        }
        else
        {
            if (round % 2 == 1) // 홀수 라운드면 X
                board[x][y] = 'X';
            else // 짝수 라운드면 O
                board[x][y] = 'O';
            
            for (i = 0; i < 3; i++)
            {
                printf("---|---|---\n");
                for (j = 0; j < 3; j++)
                {
                    if (board[i][j] == 0) // 배열의 값이 0이면 공백 출력
                        board[i][j] = ' ';
                    else if (board[i][j] == 'O')
                        board[i][j] = 'O';
                    else if (board[i][j] == 'X')
                        board[i][j] = 'X';
                    printf(" %c ", board[i][j]);
                    if (j <= 1)
                        printf("|");
                }
                printf("\n");
            }
            printf("---|---|---\n");
            
            for (i = 0; i < 3; i++)
            {
                if (((board[i][0] == 'X') && (board[i][1] == 'X') && (board[i][2] == 'X')) // 가로가 모두 X일 때
                    || ((board[i][0] == 'O') && (board[i][1] == 'O') && (board[i][2] == 'O'))) // 가로가 모두 Y일 때
                {
                    flag = 1;
                    break;
                }
                else if (((board[0][i] == 'X') && (board[1][i] == 'X') && (board[2][i] == 'X')) // 세로가 모두 X일 때
                         || ((board[0][i] == 'O') && (board[1][i] == 'O') && (board[2][i] == 'O')))// 세로가 모두 X일 때
                {
                    flag = 1;
                    break;
                }
            }
            
            if (already == 0)
                round++;
            
            srand(time(NULL));
            
            printf("= 컴퓨터 차례 =\n");
            do {
                computer_x = rand() % 3;
                computer_y = rand() % 3;
                x = computer_x;
                y = computer_y;
            } while (board[x][y] == 'X' || board[x][y] == 'O');
            
            if (round % 2 == 1) // 홀수 라운드면 X
                board[x][y] = 'X';
            else // 짝수 라운드면 O
                board[x][y] = 'O';
            
            for (i = 0; i < 3; i++)
            {
                printf("---|---|---\n");
                for (j = 0; j < 3; j++)
                {
                    if (board[i][j] == 0) // 배열의 값이 0이면 공백 출력
                        board[i][j] = ' ';
                    else if (board[i][j] == 'O')
                        board[i][j] = 'O';
                    else if (board[i][j] == 'X')
                        board[i][j] = 'X';
                    printf(" %c ", board[i][j]);
                    if (j <= 1)
                        printf("|");
                }
                printf("\n");
            }
            printf("---|---|---\n");
            
            for (i = 0; i < 3; i++)
            {
                if (((board[i][0] == 'X') && (board[i][1] == 'X') && (board[i][2] == 'X')) // 가로가 모두 X일 때
                    || ((board[i][0] == 'O') && (board[i][1] == 'O') && (board[i][2] == 'O'))) // 가로가 모두 Y일 때
                {
                    flag = 2;
                    break;
                }
                else if (((board[0][i] == 'X') && (board[1][i] == 'X') && (board[2][i] == 'X')) // 세로가 모두 X일 때
                         || ((board[0][i] == 'O') && (board[1][i] == 'O') && (board[2][i] == 'O')))// 세로가 모두 X일 때
                {
                    flag = 2;
                    break;
                }
            }
            if (((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X')) // 우하향 대각선이 모두 X일 때
                || ((board[0][2] == 'X') && (board[1][1] == 'X') && (board[2][0] == 'X')) // 우상향 대각선이 모두 X일 때
                || ((board[0][2] == 'O') && (board[1][1] == 'O') && (board[2][0] == 'O')) // 우하향 대각선이 모두 Y일 때
                || ((board[0][2] == 'O') && (board[1][1] == 'O') && (board[2][0] == 'O'))) // 우하향 대각선이 모두 Y일 때
                break;
            if (flag == 2)
                break;
        }
        
        if (already == 0)
            round++;
    }
    
    if (flag == 1)
        printf("사용자 승!\n");
    else if (flag == 2)
        printf("컴퓨터 승!\n");
    
   return 0;
}
