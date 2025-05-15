#include <stdio.h>
#include <string.h>

int calculate(char s[], int k)
{
    int i, j, l;
    int before, big, ch, error, len, max_len;

    max_len = 0;  //�̤j�l�r�����

    for (i=0;i<strlen(s)-k;i++) {
        before = -1;

        for (j=i;j<strlen(s);j=j+k) {
            if (s[j] <= 'Z')
                big = 1;  //�j�g
            else
                big = 0;  //�p�g

            error = 0;  //��l�����ۦP

            if (before == big)  //�P�e���ۦP
                error = 1;

            for (l=j+1;l<j+k;l++) {
                if (s[l] <= 'Z')
                    ch = 1;
                else
                    ch = 0;

                if (ch != big) {
                    error = 1;  //�j�p�g���P
                    break;
                }
            }

            before = big;  //��s���o�@�ӳs�򬰤j�Τp�g

            if (error == 1 || (j == strlen(s) - k && error == 0)) {
                //���~�H�P�����l�r��ֿn(�� > k�A�ܤ֥���@��)�Χ�������
                if (error == 0 || j - i > k)
                    len = j - i;
                else
                    len = 0;

                if (error == 0)
                    len = len + k;

                //printf("%d %d - %d\n", len, j, i);

                if (len > max_len)
                    max_len = len;

                break;
            }
        }
    }

    printf("%d\n", max_len);
}

int main()
{
    int i, j;
    int n, k;
    char s[100];

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        scanf(" %s %d", s, &k);

        calculate(s, k);
    }

    return 0;
}
