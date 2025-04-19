#include <stdio.h>
/*
    | 0 |
| 4 | 3 | 1 | 2 |
    | 5 |
*/

void rotate_magic(int magic[9], int direction)
{
    int i, j, temp[9];

    if (direction == 0) {  //順時針轉
        for (i=0;i<9;i++)
            temp[i] = magic[i];

        for (i=0;i<3;i++)
            for (j=0;j<3;j++)
                magic[i*3+j] = temp[2-i+j*3];
    }
    else {  //逆時針轉
        for (i=0;i<9;i++)
            temp[i] = magic[i];

        for (i=0;i<3;i++)
            for (j=0;j<3;j++)
                magic[i*3+j] = temp[6+i-j*3];
    }
}

void calculate(int magic[][9], char s[])
{
    int i, n, position = s[1] - '0', temp[3];

    if (s[0] == '1') {
        for (i=position,n=0;i<9;i=i+3)  // 3 號面暫存
            temp[n++] = magic[3][i];
        for (i=position;i<9;i=i+3)  // 5 號面轉到 3 號面
            magic[3][i] = magic[5][i];
        for (i=position;i<9;i=i+3)  // 2 號面轉到 5 號面
            magic[5][i] = magic[2][8-i];
            /*0 3 6 <= 8 5 2
            1 4 7 <= 7 4 1
            2 5 8 <= 6 3 0*/
        for (i=position;i<9;i=i+3)  // 0 號面轉到 2 號面
            magic[2][8-i] = magic[0][i];
            //同上
        for (i=position,n=0;i<9;i=i+3)  // 暫存面(3 號面)轉到 0 號面
            magic[0][i] = temp[n++];


        if (s[1] == '0')
            rotate_magic(magic[4], 0);  //順時針
        else if (s[1] == '2')
            rotate_magic(magic[1], 1);  //逆時針
    }
    else {
        position = position * 3;

        for (i=position,n=0;i<position+3;i++)  // 3 號面暫存
            temp[n++] = magic[3][i];
        for (i=position;i<position+3;i++)  // 1 號面轉到 3 號面
            magic[3][i] = magic[1][i];
        for (i=position;i<position+3;i++)  // 2 號面轉到 1 號面
            magic[1][i] = magic[2][i];
        for (i=position;i<position+3;i++)  // 4 號面轉到 2 號面
            magic[2][i] = magic[4][i];
        for (i=position,n=0;i<position+3;i++)  // 暫存面(3 號面)轉到 4 號面
            magic[4][i] = temp[n++];

        if (s[1] == '0')
            rotate_magic(magic[0], 1);  //逆時針
        else if (s[1] == '2')
            rotate_magic(magic[5], 0);  //順時針
    }
}

int main()
{
    int i, j, k, n;
    int magic[6][9];
    char s[3];

    for (i=0;i<6;i++)
        for (j=0;j<9;j++)
            magic[i][j] = i + 1;

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        scanf(" %s", s);

        calculate(magic, s);
    }

    for (j=0;j<=6;j=j+3)
        printf("%d %d %d\n", magic[3][j], magic[3][j+1], magic[3][j+2]);

    return 0;
}
