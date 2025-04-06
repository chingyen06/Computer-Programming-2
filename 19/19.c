#include <stdio.h>
#include <string.h>

void delete_zero(char str[])
{
    int i, t = 0;
    int size = strlen(str);

    for (i=0;i<size;i++) {
        if (str[i] != '0')
            break;
        else
            t++;
    }

    if (i != size)
        memmove(str, str + i, size - i + 1);  //size - i + 1 (+ 1 �O�]���n�ƻs������ '\0')

    if (t == size)
        str[1] = '\0';
}

int big(char str1[], char str2[])
{
    int i;
    int str1_size = strlen(str1), str2_size = strlen(str2);

    if (str1_size > str2_size)
        return 1;
    if (str1_size == str2_size) {
        for (i=0;i<str1_size;i++) {
            if (str1[i] == str2[i])
                continue;
            if (str1[i] > str2[i])
                return 1;
            return 0;
        }
        return 1;
    }

    return 0;
}

void minus(char dividend[], char divisor[], int size)
{
    int i, borrow = 0;
    int num_dividend, num_divisor;

    for (i=size-1;i>=0;i--) {
        num_dividend = dividend[i] - '0';
        num_divisor = divisor[i] - '0';

        if (num_dividend - num_divisor - borrow < 0) {
            dividend[i] = (num_dividend - num_divisor + 10 - borrow) % 10 + '0';
            borrow = 1;
        }
        else {
            dividend[i] = (num_dividend - num_divisor - borrow) % 10 + '0';
            borrow = 0;
        }
    }
}

void reverse(char str[])
{
    char *start = str, *end = str + strlen(str) - 1, temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int fill_zero(char str[], int size)
{
    int i, new_size = strlen(str);

    memmove(str + size, str, new_size + 1);

    for (i=0;i<size;i++)
        str[i] = '0';

    new_size = new_size + size;

    return new_size;
}

void div(char a[], char k[], char q[])
{
    int i, j, n = 0, t, move_size;
    int a_size = strlen(a), k_size = strlen(k), temp_size;
    char temp[41];

    for (i=k_size-1;i<a_size;i++) {  //�q�񰣼Ʀ�Ƥj�}�l
        //�ƻs�e�����r�� (�P���Ƥ�j�p��)
        strcpy(temp, a);
        temp[i+1] = '\0';

        delete_zero(temp);  //�R���h�l�� 0

        temp_size = strlen(temp);  //�O������

        t = 0;  //t �k�s (�ΨӬ����o�@�쪺��)

        while (big(temp, k) == 1 && temp[0] != '0' && t < 10) {  //�ٰ���
            //�зǤƦr�� (�� k�Btemp �r��P��)
            if (temp_size > k_size) {
                move_size = temp_size - k_size;
                k_size = fill_zero(k, move_size);
            }
            else if (temp_size < k_size) {
                move_size = k_size - temp_size;
                temp_size = fill_zero(temp, move_size);
            }

            minus(temp, k, temp_size);  //�N temp ��h k (����ܦh���N�i�H�F���� n �����ĪG)

            //printf("%s\n", temp);

            //�R���h�l�� 0�B���s�O������ �H�Q��j�p
            delete_zero(temp);  //�R���h�l�� 0
            delete_zero(k);  //�R���h�l�� 0
            temp_size = strlen(temp);  //��������
            k_size = strlen(k);  //��������

            t++;  //�O������
        }

        //������
        memmove(q + 1, q, n);  //�W�@�Ӫ��ӥk���@��
        q[0] = t + '0';  //�s���@�쪺��
        n++;

        //�зǤƦr�� (�� temp�Ba �r��P��)
        move_size = i - temp_size + 1;
        temp_size = fill_zero(temp, move_size);

        //�N���᪺ temp ��^�h a
        if (t > 0) {
            for (j=temp_size-1;j>=0;j--)
                a[j] = temp[j];
        }
    }
}

int main()
{
    char a[41], k[41], q[41];
    char store[41];
    memset(q, '0', sizeof(q));
    q[40] = '\0';

    scanf("%s %s", a, k);
    strcpy(store, a);

    delete_zero(a);
    delete_zero(k);

    div(a, k, q);

    reverse(q);
    delete_zero(q);
    delete_zero(a);

    printf("%s\n%s", q, a);

    return 0;
}
