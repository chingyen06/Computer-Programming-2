#include <stdio.h>
/*
    | 0 |
| 4 | 3 | 1 | 2 |
    | 5 |
*/

void rotate_magic(int magic[9], int direction)
{
    int i, j, temp[9];

    if (direction == 0) {  //���ɰw��
        for (i=0;i<9;i++)
            temp[i] = magic[i];

        for (i=0;i<3;i++)
            for (j=0;j<3;j++)
                magic[i*3+j] = temp[2-i+j*3];
    }
    else {  //�f�ɰw��
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
        for (i=position,n=0;i<9;i=i+3)  // 3 �����Ȧs
            temp[n++] = magic[3][i];
        for (i=position;i<9;i=i+3)  // 5 ������� 3 ����
            magic[3][i] = magic[5][i];
        for (i=position;i<9;i=i+3)  // 2 ������� 5 ����
            magic[5][i] = magic[2][8-i];
            /*0 3 6 <= 8 5 2
            1 4 7 <= 7 4 1
            2 5 8 <= 6 3 0*/
        for (i=position;i<9;i=i+3)  // 0 ������� 2 ����
            magic[2][8-i] = magic[0][i];
            //�P�W
        for (i=position,n=0;i<9;i=i+3)  // �Ȧs��(3 ����)��� 0 ����
            magic[0][i] = temp[n++];


        if (s[1] == '0')
            rotate_magic(magic[4], 0);  //���ɰw
        else if (s[1] == '2')
            rotate_magic(magic[1], 1);  //�f�ɰw
    }
    else {
        position = position * 3;

        for (i=position,n=0;i<position+3;i++)  // 3 �����Ȧs
            temp[n++] = magic[3][i];
        for (i=position;i<position+3;i++)  // 1 ������� 3 ����
            magic[3][i] = magic[1][i];
        for (i=position;i<position+3;i++)  // 2 ������� 1 ����
            magic[1][i] = magic[2][i];
        for (i=position;i<position+3;i++)  // 4 ������� 2 ����
            magic[2][i] = magic[4][i];
        for (i=position,n=0;i<position+3;i++)  // �Ȧs��(3 ����)��� 4 ����
            magic[4][i] = temp[n++];

        if (s[1] == '0')
            rotate_magic(magic[0], 1);  //�f�ɰw
        else if (s[1] == '2')
            rotate_magic(magic[5], 0);  //���ɰw
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
