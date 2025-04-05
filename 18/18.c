#include <stdio.h>
#include <string.h>

int repeat(char *sub_string, int len)
{
    int i, j;
    char used[10]={};

    for (i=0;i<len;i++) {
        if (used[sub_string[i]-'0'] > 0)
            return 1;

        used[sub_string[i]-'0']++;
    }
    return 0;  //無重複
}

int main()
{
    int i, j;
    int m, len, n = 0;
    char big_list[100];

    scanf("%d ", &m);

    char sub_string[100][11];
    char temp[11];

    fgets(big_list, sizeof(big_list), stdin);  //輸入可包含空格的字串
    big_list[strcspn(big_list, "\n")] = '\0';  //刪除換行符號

    len = strlen(big_list) - (m - 1) * 2;  //計算最後一個子字串的開頭

    for (i=0;i<len;i=i+2) {
        for (j=0;j<m;j++)
            sub_string[n][j] = big_list[i+2*j];

        sub_string[n][m] = '\0';

        if (repeat(sub_string[n], m) == 0)
            n++;
    }

    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (strcmp(sub_string[j], sub_string[i]) > 0) {
                strcpy(temp, sub_string[i]);
                strcpy(sub_string[i], sub_string[j]);
                strcpy(sub_string[j], temp);
            }
        }
    }

    printf("%d\n", n);

    for (i=0;i<m;i++)
        printf("%c ", sub_string[0][i]);

    printf("\n");

    for (i=1;i<n;i++) {
        if (strcmp(sub_string[i], sub_string[i-1]) != 0) {
            for (j=0;j<m;j++)
                printf("%c ", sub_string[i][j]);

            printf("\n");
        }
    }

    return 0;
}
