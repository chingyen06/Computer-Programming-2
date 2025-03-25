#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int *m, int *n, int *g)  //����۰��k��̤p���]��
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

void to_fraction(char *ch, int *num_nume, int *num_deno)  //������u�ΰ����� (�Ʀr)
{
    int bring = 0, comm, neg = 1;

    if (strcspn(ch, "(") != strlen(ch))
        sscanf(ch, "%d(%d/%d)", &bring, num_nume, num_deno);  //�N����
    else
        sscanf(ch, "%d/%d", num_nume, num_deno);  //�u����

    if (bring < 0)  //�t��
        neg = -1;

    *num_nume = (*num_nume + abs(bring) * (*num_deno)) * neg;  //�N�����ల����
}

void add(int *num1_nume, int *num1_deno, int *num2_nume, int *num2_deno)
{
    //�q���íp�� (�⧹���ȩ� num1)
    *num1_nume *= *num2_deno;  //num1 ���l�P num2 �����ۭ�
    *num1_nume += (*num2_nume) * (*num1_deno);  //num1 ���l + num2 ���l (num2 ���l�P num1 �����ۭ�)
    *num1_deno *= *num2_deno;  //num1 �����P num2 �����ۭ�
}

void minus(int *num1_nume, int *num1_deno, int *num2_nume, int *num2_deno)
{
    //�q���íp�� (�⧹���ȩ� num1)
    *num1_nume *= *num2_deno;  //num1 ���l�P num2 �����ۭ�
    *num1_nume -= (*num2_nume) * (*num1_deno);  //num1 ���l - num2 ���l (num2 ���l�P num1 �����ۭ�)
    *num1_deno *= *num2_deno;  //num1 �����P num2 �����ۭ�
}

void multiple(int *num1_nume, int *num1_deno, int *num2_nume, int *num2_deno)
{
    //�p�� (�⧹���ȩ� num1)
    *num1_nume *= *num2_nume;  //num1 ���l�P num2 ���l�ۭ�
    *num1_deno *= *num2_deno;  //num1 �����P num2 �����ۭ�
}

void divide(int *num1_nume, int *num1_deno, int *num2_nume, int *num2_deno)
{
    //�p�� (�⧹���ȩ� num1)
    //num1 / num2 = num1 * (1/num2)
    int neg = 1;  //�P�_�t�� (���l�P�����ۭ��A�������i�঳�t��)

    if (*num2_nume < 0)
        neg = -1;

    //printf("%d/%d  %d/%d\n", *num1_nume, *num1_deno, *num2_nume, *num2_deno);

    *num1_nume *= *num2_deno * neg;  //num1 ���l�P num2 �����ۭ�
    *num1_deno *= abs(*num2_nume);  //num1 �����P num2 ���l�ۭ�
}

void simplify(int *bring, int *nume, int *deno)  //��²
{
    int g, abs_nume = abs(*nume), abs_deno = abs(*deno);
    gcd(&abs_nume, &abs_deno, &g);  //�D�̤p���]��

    *bring = 0;
    *nume /= g;
    *deno /= g;

    *bring = (*nume) / (*deno);  //�a����
    *nume %= *deno;  //�Ƭ���²

    if (*bring < 0)  //�t���w�g�Q bring �a��
        *nume = abs(*nume);  //�h���t��
}

int main()
{
    //num_nume ���l,  num_deno ����
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

        simplify(&bring, &num1_nume, &num1_deno);  //��²

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
