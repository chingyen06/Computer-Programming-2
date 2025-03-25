#include <stdio.h>
#include <math.h>
#include <string.h>

int to_num(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else
        return ch - 'A' + 10;
}

int to_word(int num)
{
    if (num >= 0 && num <= 9)
        return num + '0';
    else
        return num - 10 + 'A';
}

int to_dicemal(int m, char *base_m)
{
    int total = 0, i = strlen(base_m)-1, num;

    while (*base_m) {  //�ഫ�� 10 �i��
        num = to_num(*base_m);
        total += num * pow(m, i);
        base_m++;
        i--;
    }

    return total;
}

int to_base_n(int n, int decimal, char *base_n)
{
    int num;
    char temp;
    char *start = base_n, *end;

    if (decimal == 0) {
        *base_n = '0';
        *(++base_n) = '\0';
        return 0;
    }

    while (decimal > 0) {  //�ഫ�� n �i�� (�Ϫ�)
        num = decimal % n;  //�ഫ���Ʀr���A (10, 11 ...)
        *base_n = to_word(num);  //�ഫ�����T���A (A, B ...)
        decimal = decimal / n;
        base_n++;
    }
    *base_n = '\0';  //�K�[�r�굲���Ÿ�

    end = base_n - 1;

    while (start < end) {  //����r��
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main()
{
    int M, N, decimal;
    char base_m[10], base_n[100];

    scanf("%d %s %d", &M, base_m, &N);

    decimal = to_dicemal(M, base_m);

    to_base_n(N, decimal, base_n);

    printf("%s", base_n);

    return 0;
}
