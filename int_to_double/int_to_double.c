#include<stdio.h>

int main()
{
    int a, b;
    double c;

    scanf("%d %d", &a, &b);  //範例 a = 3, b = 2

    //c = a / b;  //答案會是1，拋棄小數點後的數字(0.5)
    c = (float) a / b;  //答案會是1.5 (正確)

    printf("%.1f", c);

    return 0;
}
