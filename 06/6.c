#include<stdio.h>

double to_int(char ch[3][3])
{
    int i;
    double in = 0;

    for (i=0;i<3;i++) {
        if (ch[i][0] >= '2' && ch[i][0] <= '9')  //2 ~ 9
            in += ch[i][0] - '0';
        else if (ch[i][0] == 'A')  //A
            in += 1;
        else if (ch[i][0] == '1' && ch[i][1] == '0')  //10
            in += 10;
        else  //J Q K
            in += 0.5;
    }

    if (in > 10.5)
        in = 0;

    return in;
}

int main()
{
    int i;
    double x, y;
    char X[3][3], Y[3][3];

    scanf("%s %s %s %s %s %s", X[0], X[1], X[2], Y[0], Y[1], Y[2]);

    x = to_int(X);
    y = to_int(Y);

    if (((int) (x*10))%10 == 0)  //X沒有小數點
        printf("%.f\n", x);
    else
        printf("%.1f\n", x);

    if (((int) (y*10))%10 == 0)  //Y沒有小數點
        printf("%.f\n", y);
    else
        printf("%.1f\n", y);

    if (x > y)
        printf("X Win");
    else if (x < y)
        printf("Y Win");
    else
        printf("Tie");

    return 0;
}
