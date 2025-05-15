#include <stdio.h>
#include <string.h>

int calculate(char s[], int k)
{
    int i, j, l;
    int before, big, ch, error, len, max_len;

    max_len = 0;  //最大子字串長度

    for (i=0;i<strlen(s)-k;i++) {
        before = -1;

        for (j=i;j<strlen(s);j=j+k) {
            if (s[j] <= 'Z')
                big = 1;  //大寫
            else
                big = 0;  //小寫

            error = 0;  //初始為都相同

            if (before == big)  //與前面相同
                error = 1;

            for (l=j+1;l<j+k;l++) {
                if (s[l] <= 'Z')
                    ch = 1;
                else
                    ch = 0;

                if (ch != big) {
                    error = 1;  //大小寫不同
                    break;
                }
            }

            before = big;  //更新為這一個連續為大或小寫

            if (error == 1 || (j == strlen(s) - k && error == 0)) {
                //錯誤以致結束子字串累積(需 > k，至少交替一次)或完全結束
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
