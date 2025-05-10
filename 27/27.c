#include <stdio.h>
#include <ctype.h>
#include <string.h>

void copy_word(char dest[], char source[], char end)
{
    if (!isalpha(end)) {
        strcpy(dest, source);
        dest[strlen(dest)] = end;
        dest[strlen(dest)+1] = '\0';
    }
    else {
        strcpy(dest, source);
    }
}

void print(char ans[1000][100], int n)
{
    int i;

    for (i=0;i<n;i++)
        printf("%s ", ans[i]);

    printf("\n");
}

int main()
{
    char str[1000], p[10], q[10];
    char ans_1[1000][100]={""}, ans_2[1000][100]={""}, ans_3[1000][100]={""}, ans_4[1000][100]={""}, ans_5[1000][100]={""};
    char *delim = " ", *ch, sign;
    int i, n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;

    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0';

    scanf(" %s %s", p, q);

    ch = strtok(str, delim);

    while (ch != NULL) {
        sign = ch[strlen(ch)-1];
        if (!isalpha(sign))  //刪除結尾多餘符號
            ch[strlen(ch)-1] = '\0';

        //倒轉
        copy_word(ans_5[n5], ch, sign);
        n5++;
        if (strcmp(ch, p) == 0) {  //與單詞P相同
            //替代
            copy_word(ans_1[n1], q, sign);
            n1++;
            //前插入
            copy_word(ans_2[n2], q, 'A');  //不必加結尾符號
            copy_word(ans_2[n2+1], ch, sign);
            n2 = n2 + 2;
            //後插入
            copy_word(ans_3[n3], ch, sign);
            copy_word(ans_3[n3+1], q, 'A');  //不必加結尾符號
            n3 = n3 + 2;
        }
        else {  //這裡都是沒變的，註解只代表是哪個的答案
            //替代
            copy_word(ans_1[n1], ch, sign);
            n1++;
            //前插入
            copy_word(ans_2[n2], ch, sign);
            n2++;
            //後插入
            copy_word(ans_3[n3], ch, sign);
            n3++;
            //單字刪除
            copy_word(ans_4[n4], ch, sign);
            n4++;
        }

        ch = strtok(NULL, delim);
    }

    print(ans_1, n1);
    print(ans_2, n2);
    print(ans_3, n3);
    print(ans_4, n4);

    for (i=n5-1;i>=0;i--)
        printf("%s ", ans_5[i]);

    return 0;
}
