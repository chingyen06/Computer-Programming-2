#include <stdio.h>

/*
因：骰子 "每一面 + 每一面的對面" 的點數 = 7
ex. 1 對面是 6 => 1 + 6 = 7

果：
(1) 骰子向前滾或向右滾都是 7 - 前一面
ex. 原始骰子向右滾 => 新的骰面 = 7 - 2 = 5
ex. 原始骰子向前滾 => 新的骰面 = 7 - 4 = 3

(2) 骰子向前滾或向右滾時，將 "前一面" 改為 轉前的點數
骰子向後滾或向左滾時，將 "前一面" 改為 7 - 轉前的點數
*/

void calculate(int dice[3][4], int n, int command)
{
    int temp;

    if (command <= 2) {
        temp = dice[0][n];

        if (command == 1) {
            dice[0][n] = 7 - dice[1][n];
            dice[1][n] = temp;
        }
        else {
            dice[0][n] = dice[1][n];
            dice[1][n] = 7 - temp;
        }
    }
    else {
        temp = dice[0][n];

        if (command == 3) {
            dice[0][n] = 7 - dice[2][n];
            dice[2][n] = temp;
        }
        else {
            dice[0][n] = dice[2][n];
            dice[2][n] = 7 - temp;
        }
    }
}

int main()
{
    int i, j;
    int n, command, appear_pair = 0, point = 0;
    int appear_max = 0;
    int dice[3][4]={{1,1,1,1},{4,4,4,4},{2,2,2,2}}, same[7]={};
    //dice[0]: 初始點數  dice[1]: 向前滾要減的點數/向後滾的點數  dice[2]: 向右滾要減的點數/向左滾的點數

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        for (j=0;j<4;j++) {
            scanf(" %d", &command);

            calculate(dice, j, command);
        }
        /*for (j=0;j<4;j++)
            printf("%d ", dice[0][j]);
        printf("\n");*/
    }

    //分數計算
    for (i=0;i<4;i++)  //計算點數出現次數
        same[dice[0][i]]++;

    for (i=1;i<=6;i++) {
        if (same[i] == 4)
            point = 18;

        if (same[i] == 2) {
            appear_pair++;  //新增一次兩點同次數
            if (i > appear_max)
                appear_max = i;
        }
    }

    if (appear_pair == 2)  //有兩次兩顆點數相同 (彼此不同)
        point = appear_max * 2;
    else if (appear_pair == 1) {  //有兩顆點數相同，其餘不同
        for (i=1;i<=6;i++)
            if (same[i] == 1)
                point += i;
    }

    //四顆皆不同或三顆同一顆不同 => point = 0 (一開始就有設)

    printf("%d", point);

    return 0;
}
