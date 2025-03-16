#include<stdio.h>

void swap(int *x, int *y)
{
    int t;

    t = *x;
    *x = *y;
    *y = t;
}

int triangle(int a, int b, int c)
{
    if (a > b + c || a == 0 || b == 0 || c == 0) {
        printf("Not Triangle\n");
        return 0;
    }
    if (a == b && a == c)
        printf("Equilateral Triangle\n");
    if (a == b || a == c || b == c)
        printf("Isosceles Triangle\n");
    if (a * a > b * b + c * c)
        printf("Obtuse Triangle\n");
    if (a * a < b * b + c * c)
        printf("Acute Triangle\n");
    if (a * a == b * b + c * c)
        printf("Right Triangle\n");

    return 0;
}

int main()
{
    int i, j;
    int n, a, b, c;

    scanf("%d ", &n);

    for (i=0;i<n;i++) {
        scanf("%d %d %d", &a, &b, &c);

        if (b > a && b >= c)
            swap(&a, &b);
        else if (c > a && c >= b)
            swap(&a, &c);

        if (i == n - 1)
            triangle(a, b, c);
        else {
            triangle(a, b, c);

            for (j=0;j<n;j++)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}
