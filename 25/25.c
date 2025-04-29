#include <stdio.h>
#include <string.h>

int straight(int chess[12][12], int y, int x, int mode)
{
    int first, second, first_chess = 0, second_chess = 0, connect = 1;
    int point_first, point_second;

    if (mode == 0) {  //水平方向
        first = x;
        second = x;
    }
    else {  //垂直方向
        first = y;
        second = y;
    }

    while (first_chess != -1 || second_chess != -1) {
        if (first_chess != -1) {
            first--;

            if (mode == 0)
                first_chess = chess[y][first];  //左
            else
                first_chess = chess[first][x];  //上
        }

        if (second_chess != -1) {
            second++;

            if (mode == 0)
                second_chess = chess[y][second];  //右
            else
                second_chess = chess[second][x];  //下
        }

        if (first_chess == -1)
            point_first = 0;
        else
            point_first = first_chess;

        if (second_chess == -1)
            point_second = 0;
        else
            point_second = second_chess;

        connect = connect + point_first + point_second;

        if (first_chess == 0)
            first_chess = -1;

        if (second_chess == 0)
            second_chess = -1;
    }

    if (connect == 5)
        return 1;

    return 0;
}

int slash(int chess[12][12], int y, int x, int mode)
{
    int first[2] = {y, x}, second[2] = {y, x}, first_chess = 0, second_chess = 0, connect = 1;
    int point_first, point_second;

    while (first_chess != -1 || second_chess != -1) {
        if (first_chess != -1) {
            if (mode == 0) {  //左下
                first[0]++;
                first[1]--;
            }
            else {  //右下
                first[0]++;
                first[1]++;
            }

            first_chess = chess[first[0]][first[1]];
        }

        if (second_chess != -1) {
            if (mode == 0) {  //右上
                second[0]--;
                second[1]++;
            }
            else {  //左上
                second[0]--;
                second[1]--;
            }

            second_chess = chess[second[0]][second[1]];
        }

        if (first_chess == -1)
            point_first = 0;
        else
            point_first = first_chess;

        if (second_chess == -1)
            point_second = 0;
        else
            point_second = second_chess;

        connect = connect + point_first + point_second;

        if (first_chess == 0)
            first_chess = -1;

        if (second_chess == 0)
            second_chess = -1;
    }

    if (connect == 5)
        return 1;

    return 0;
}

int main()
{
    int i, j, n = 0, t, min, num, num_min;
    int chess[12][12];
    char five[100][5], temp[5];

    //初始化為 -1
    for (i=0;i<=11;i++)
        for (j=0;j<=11;j++)
            chess[i][j] = -1;
    //

    for (i=1;i<=10;i++)
        for (j=1;j<=10;j++)
            scanf("%d", &chess[i][j]);

    for (i=1;i<=10;i++) {
        for (j=1;j<=10;j++) {
            if (chess[i][j] == 1)  //避免重複落子
                continue;

            t = 0;
            t = t + straight(chess, i, j, 0) + straight(chess, i, j, 1);  //水平 + 垂直
            t = t + slash(chess, i, j, 0) + slash(chess, i, j, 1);  //左斜 + 右斜

            //printf("%d %d | %d\n", i, j, t);

            if (t > 0) {
                five[n][0] = i - 1 + '0';
                five[n][1] = j - 1 + '0';
                five[n][2] = ' ';
                five[n][3] = t + '0';
                five[n][4] = '\0';

                n++;
            }
        }
    }

    //排序
    for (i=0;i<n;i++) {
        min = i;

        for (j=i+1;j<n;j++) {
            if (five[j][3] > five[min][3])
                min = j;
            else if (five[j][3] == five[min][3]) {
                num_min = (five[min][0]-'0') * 10 + (five[min][1]-'0');
                num = (five[j][0]-'0') * 10 + (five[j][1]-'0');

                if (num < num_min)
                    min = j;
            }
        }

        strcpy(temp, five[i]);
        strcpy(five[i], five[min]);
        strcpy(five[min], temp);
    }
    //

    for (i=0;i<n;i++)
        printf("%s\n", five[i]);

    return 0;
}
