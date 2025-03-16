#include<stdio.h>

void draw_1(int m)
{
    int i, j;
    char word[3]={'A', 'B', 'C'};

    for (i=1;i<=m;i++) {
        for (j=0;j<m-i;j++)  //#
            printf("#");

        for (j=0;j<i-1;j++) {  //*A or *B or *C
            printf("*");  //*
            printf("%c", word[(i-2)%3]);  //A or B or C
        }
        printf("*");  //*

        for (j=0;j<m-i;j++)  //#
            printf("#");

        printf("\n");
    }
}

void draw_2(int m)
{
    int i, j;

    for (i=0;i<m;i++) {
        for (j=i+1;j>=1;j--)  //數字正序
            printf("%d", j);

        for (j=0;j<(m-i)*2;j++)  //*
            printf("*");

        for (j=1;j<=i+1;j++)  //數字倒序
            printf("%d", j);

        printf("\n");
    }
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    if (n < 1 || n > 2 || m < 2 || m > 9) {
        printf("error");
        return 0;
    }

    if (n == 1)
        draw_1(m);
    else
        draw_2(m);

    return 0;
}
