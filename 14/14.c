#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int *m, int *n, int *g)  //輾轉相除法找最小公因數
{
    int temp;

    if (*n == 0) {
        *g = *m;
        return 0;
    }

    temp = *m % *n;
    *m = *n;
    *n = temp;

    gcd(m, n, g);
}

void to_fraction(char *ch, int *num_nume, int *num_deno)  //全部轉真或假分數 (數字)
{
    int bring = 0, comm, neg = 1;

    if (strcspn(ch, "(") != strlen(ch))
        sscanf(ch, "%d(%d/%d)", &bring, num_nume, num_deno);  //代分數
    else
        sscanf(ch, "%d/%d", num_nume, num_deno);  //真分數

    if (bring < 0)  //負號
        neg = -1;

    *num_nume = (*num_nume + abs(bring) * (*num_deno)) * neg;  //代分數轉假分數
}

void add(int *num1_nume, int *num1_deno, int *num2_nume, int *num2_deno)
{
    //通分並計算 (算完的值放 num1)
    *num1_nume *= *num2_deno;  //num1 分子與 num2 分母相乘
    *num1_nume += (*num2_nume) * (*num1_deno);  //num1 分子 + num2 分子 (num2 分子與 num1 分母相乘)
    *num1_deno *= *num2_deno;  //num1 分母與 num2 分母相乘
}

void minus(int *num1_nume, int *num1_deno, int *num2_nume, int *num2_deno)
{
    //通分並計算 (算完的值放 num1)
    *num1_nume *= *num2_deno;  //num1 分子與 num2 分母相乘
    *num1_nume -= (*num2_nume) * (*num1_deno);  //num1 分子 - num2 分子 (num2 分子與 num1 分母相乘)
    *num1_deno *= *num2_deno;  //num1 分母與 num2 分母相乘
}

void multiple(int *num1_nume, int *num1_deno, int *num2_nume, int *num2_deno)
{
    //計算 (算完的值放 num1)
    *num1_nume *= *num2_nume;  //num1 分子與 num2 分子相乘
    *num1_deno *= *num2_deno;  //num1 分母與 num2 分母相乘
}

void divide(int *num1_nume, int *num1_deno, int *num2_nume, int *num2_deno)
{
    //計算 (算完的值放 num1)
    //num1 / num2 = num1 * (1/num2)
    int neg = 1;  //判斷負號 (分子與分母相乘，分母有可能有負號)

    if (*num2_nume < 0)
        neg = -1;

    //printf("%d/%d  %d/%d\n", *num1_nume, *num1_deno, *num2_nume, *num2_deno);

    *num1_nume *= *num2_deno * neg;  //num1 分子與 num2 分母相乘
    *num1_deno *= abs(*num2_nume);  //num1 分母與 num2 分子相乘
}

void simplify(int *bring, int *nume, int *deno)  //化簡
{
    int g, abs_nume = abs(*nume), abs_deno = abs(*deno);
    gcd(&abs_nume, &abs_deno, &g);  //求最小公因數

    *bring = 0;
    *nume /= g;
    *deno /= g;

    *bring = (*nume) / (*deno);  //帶分數
    *nume %= *deno;  //化為最簡

    if (*bring < 0)  //負號已經被 bring 帶走
        *nume = abs(*nume);  //去除負號
}

int main()
{
    //num_nume 分子,  num_deno 分母
    int bring, num1_nume, num1_deno, num2_nume, num2_deno;
    char ch1[10], ch2[10], operate, continuee = 'y';

    while (continuee == 'y') {
        scanf("%s %c %s %c", ch1, &operate, ch2, &continuee);

        to_fraction(ch1, &num1_nume, &num1_deno);
        to_fraction(ch2, &num2_nume, &num2_deno);

        //printf("%d/%d  %d/%d\n", num1_nume, num1_deno, num2_nume, num2_deno);

        if (num1_deno == 0 || num2_deno == 0) {
            printf("Error\n");
            continue;
        }

        if (operate == '+')
            add(&num1_nume, &num1_deno, &num2_nume, &num2_deno);
        else if (operate == '-')
            minus(&num1_nume, &num1_deno, &num2_nume, &num2_deno);
        else if (operate == '*')
            multiple(&num1_nume, &num1_deno, &num2_nume, &num2_deno);
        else
            divide(&num1_nume, &num1_deno, &num2_nume, &num2_deno);

        //printf("%d/%d\n", num1_nume, num1_deno);

        if (num1_deno == 0) {
            printf("Error\n");
            continue;
        }

        simplify(&bring, &num1_nume, &num1_deno);  //化簡

        if (bring) {
            if (num1_nume == 0)
                printf("%d\n", bring);
            else
                printf("%d(%d/%d)\n", bring, num1_nume, num1_deno);
        }

        else {
            if (num1_nume == 0)
                printf("0\n");
            else
                printf("%d/%d\n", num1_nume, num1_deno);
        }
    }

    return 0;
}
