#include <stdio.h>
#include <string.h>

void reverse(char *s, int s_size)
{
    char *start = s, *end = s + s_size - 1;
    char temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int check_size(char a[], char b[], int size)  //char a[] = char *a
{
    int i;

    for (i=size-1;i>=0;i--) {
        if (a[i] == b[i])
            continue;

        if (a[i] > b[i])
            return 1;  //a > b
        else
            return 2;  //b > a
    }

    return 3;  //一樣大
}

int delete_zero(char ans[], int size)
{
    int i;

    for (i=size-1;i>=0;i--)
        if (ans[i] != '0' || i == 0)
            break;

    ans[i+1] = '\0';

    return i + 1;
}

int add(char a[], char b[], char ans[], int size)
{
    int i, carry = 0;

    for (i=0;i<size;i++) {
        int num_a = a[i] - '0', num_b = b[i] - '0';
        ans[i] = (num_a + num_b + carry) % 10 + '0';
        carry = (num_a + num_b + carry) / 10;
    }

    if (carry > 0) {  //還有進位
        ans[size] = carry + '0';
        ans[size+1] = '\0';
        return size + 1;
    }
    else {
        ans[size] = '\0';
        return size;
    }
}

int minus(char a[], char b[], char ans[], int size)
{
    int i, borrow = 0;

    for (i=0;i<size;i++) {
        int num_a = a[i] - '0', num_b = b[i] - '0';

        if (num_a - num_b - borrow < 0) {  //需要借位
            ans[i] = (num_a - num_b - borrow + 10) % 10 + '0';
            borrow = 1;
        }
        else {  //不需借位
            ans[i] = (num_a - num_b - borrow) % 10 + '0';
            borrow = 0;
        }
    }
    ans[size] = '\0';
    return size;
}

void mult(char a[], char b[], char ans[], int size)
{
    int i, j, carry;
    char temp[201];
    memset(ans, '0', 200);
    ans[200] = '\0';

    for (i=0;i<size;i++) {
        int num_a, num_b = b[i] - '0';
        carry = 0;
        memset(temp, '0', 200);
        temp[200] = '\0';

        for (j=0;j<size;j++) {
            num_a = a[j] - '0';
            temp[j+i] = (num_a * num_b + carry) % 10 + '0';
            carry = (num_a * num_b + carry) / 10;
        }

        if (carry > 0)  //還有進位
            temp[size+i] = carry + '0';

        add(ans, temp, ans, 200);
    }
}

int main()
{
    int i;
    int a_size, b_size, size, a_neg = 1, b_neg = 1;
    int big, add_size, minus_size, mult_size;
    char a[101], b[101];
    char ans_add[102], ans_minus[102], ans_mult[201];

    scanf("%s %s", a, b);

    //確認字串長度
    a_size = strlen(a);
    b_size = strlen(b);

    //確認正負
    if (a[0] == '-') {
        a_neg = -1;
        memmove(a, a + 1, a_size);  //右移
        a_size--;
    }
    if (b[0] == '-') {
        b_neg = -1;
        memmove(b, b + 1, b_size);  //右移
        b_size--;
    }

    //首尾翻轉
    reverse(a, a_size);
    reverse(b, b_size);

    //將兩個位數同步
    if (a_size > b_size) {
        size = a_size;

        for (i=b_size;i<a_size;i++)
            b[i] = '0';
        b[a_size] = '\0';
    }
    else {
        size = b_size;

        for (i=a_size;i<b_size;i++)
            a[i] = '0';
        a[b_size] = '\0';
    }

    //確認大小
    big = check_size(a, b, size);

    //加法
    if (a_neg * b_neg == 1) {  //(+) + (+) or (-) + (-)
        if (a_neg == -1)
            printf("-");
        add_size = add(a, b, ans_add, size);
    }
    else if (a_neg * b_neg == -1) {  //(+) + (-) or (-) + (+)
        if (a_neg == -1) {  //a 是負的
            if (big == 1) {  //a 大
                printf("-");
                add_size = minus(a, b, ans_add, size);
            }
            else
                add_size = minus(b, a, ans_add, size);
        }
        else {  //b 是負的
            if (big == 2) {  //b 大
                printf("-");
                add_size = minus(b, a, ans_add, size);
            }
            else
                add_size = minus(a, b, ans_add, size);
        }
    }
    add_size = delete_zero(ans_add, add_size);  //刪除多餘的 0 並獲取大小
    reverse(ans_add, add_size);  //反轉字串
    printf("%s\n", ans_add);

    //減法
    if (a_neg == 1 && b_neg == 1) {  //(+) - (+)
        if (big == 2) {  //b 大
            printf("-");
            minus_size = minus(b, a, ans_minus, size);
        }
        else
            minus_size = minus(a, b, ans_minus, size);
    }
    else if (a_neg * b_neg == -1) {  //(-) - (+)
        if (a_neg == -1)  //a 是負的
            printf("-");

        minus_size = add(a, b, ans_minus, size);
    }
    else {  //(-) - (-) = (-) + (+)
        if (big == 1) {  //a 大
            printf("-");
            minus_size = minus(a, b, ans_minus, size);
        }
        else
            minus_size = minus(b, a, ans_minus, size);
    }
    minus_size = delete_zero(ans_minus, minus_size);  //刪除多餘的 0 並獲取大小
    reverse(ans_minus, minus_size);  //反轉字串
    printf("%s\n", ans_minus);

    //乘法
    for (i=0;i<200;i++)
        ans_mult[i] = '0';
    ans_mult[200] = '\0';

    if (a_neg * b_neg == -1)
        printf("-");
    mult(a, b, ans_mult, size);
    mult_size = delete_zero(ans_mult, 200);  //刪除多餘的 0 並獲取大小
    reverse(ans_mult, mult_size);  //反轉字串
    printf("%s\n", ans_mult);

    //printf("%s %s", a, b);

    return 0;
}
