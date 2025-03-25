#include <stdio.h>
#include <stdlib.h>

int gcd(int *m, int *n, int *g)
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

void get_equation(int *x1, int *y1, int *x2, int *y2, int *m_nume, int *m_deno, int *b_nume, int *b_deno)
{
    int g, neg, abs_nume, abs_deno;

    //б�� m
    neg = 1;

    //�˜ʹ�ʽ
    *m_nume = *y1 - *y2;
    *m_deno = *x1 - *x2;

    if (*m_nume < 0)
        neg *= -1;

    if (*m_deno < 0)
        neg *= -1;

    //�ҹ���
    abs_nume = abs(*m_nume);
    abs_deno = abs(*m_deno);
    gcd(&abs_nume, &abs_deno, &g);

    //����
    *m_nume = abs(*m_nume) / g * neg;
    *m_deno = abs(*m_deno) / g;

    //==========

    //���� b
    neg = 1;

    //�˜ʹ�ʽ
    *b_nume = (*x2) * (*y1) - (*x1) * (*y2);
    *b_deno = *x2 - *x1;

    if (*b_nume < 0)
        neg *= -1;

    if (*b_deno < 0)
        neg *= -1;

    //�ҹ���
    abs_nume = abs(*b_nume);
    abs_deno = abs(*b_deno);
    gcd(&abs_nume, &abs_deno, &g);

    //����
    *b_nume = abs(*b_nume) / g * neg;
    *b_deno = abs(*b_deno) / g;
}

int main()
{
    int i, n;
    int m_nume, m_deno, b_nume, b_deno;
    int x1, y1, x2 , y2;
    char neg;

    scanf("%d", &n);

    for(i=0;i<n;i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        get_equation(&x1, &y1, &x2, &y2, &m_nume, &m_deno, &b_nume, &b_deno);

        if (b_nume < 0)
            neg = '-';
        else
            neg = '+';

        //printf("%d %d %d %d\n", m_nume, m_deno, b_nume, b_deno);

        if (m_nume == 0) {  //m = 0
            if (b_deno == 1 || b_nume == 0)  //b = 1 or b = 0
                printf("y = %d\n", b_nume);
            else
                printf("y = %d/%d\n", b_nume, b_deno);
        }
        else if (m_deno == 1 && m_nume == 1)  //m = 1
            printf("y = x");
        else if (m_deno == 1 && m_nume == -1)  //m = -1
            printf("y = -x");
        else if (m_deno == 1)  //m = ����
                printf("y = %dx", m_nume);
        else  //m = �֔�
            printf("y = %d/%dx", m_nume, m_deno);

        if (b_nume == 0 && m_nume != 0)  //m \= 0 b = 0
            printf("\n");
        else if (m_nume != 0) {  // m \= 0
            if (b_deno == 1)  //b = ����
                printf(" %c %d\n", neg, abs(b_nume));
            else  //b = �֔�
                printf(" %c %d/%d\n", neg, abs(b_nume), b_deno);
        }
    }

    return 0;
}
