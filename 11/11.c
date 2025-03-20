#include<stdio.h>

void gray_code(int n, int k, char *code)
{
    if (n == 1) {
        code[0] = (char) (k + '0');
        code[1] = '\0';  //字串結尾
    }
    else if (k < pow(2, (n-1))) {
        code[0] = '0';
        gray_code(n-1, k, code+1);  //code + 1 => 把指標往右移到下一個位置
    }
    else {
        code[0] = '1';
        gray_code(n-1, pow(2, n)-1-k, code+1);  //code + 1 => 把指標往右移到下一個位置
    }
}

int main()
{
    char code[32];  //因為宣告在main，所以每次進while迴圈都會是一開始的樣子
    int n, k;

    while (1) {
        scanf("%d", &n);

        if (n == -1)
            break;

        scanf(" %d", &k);

        gray_code(n, k, code);

        printf("%s\n", code);
    }

    return 0;
}
