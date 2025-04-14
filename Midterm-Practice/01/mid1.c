#include <stdio.h>

void pic1(int n)
{
    int i, j;

    for (i=1;i<=n;i++) {
        for (j=1;j<=i;j++)
            printf("%d", j);
        printf("\n");
    }

    for (i=1;i<=n;i++) {
        for (j=n-i+1;j>=1;j--)
            printf("%d", j);
        printf("\n");
    }
}

void pic2(int n)
{
    int i, j;

    for (i=1;i<=n;i++) {
        for (j=1;j<=n-i;j++)
            printf("_");
        for (j=i;j>=1;j--)
            printf("%d", j);
        for (j=2;j<=i;j++)
            printf("%d", j);
        for (j=1;j<=n-i;j++)
            printf("_");

        printf("\n");
    }

    for (i=n-1;i>=1;i--) {
        for (j=1;j<=n-i;j++)
            printf("_");
        for (j=i;j>=1;j--)
            printf("%d", j);
        for (j=2;j<=i;j++)
            printf("%d", j);
        for (j=1;j<=n-i;j++)
            printf("_");

        printf("\n");
    }
}

void pic3(int n)
{
    int i, j;

    for (i=1;i<=n;i++) {
        for (j=1;j<=i;j++)
            printf("%d", j);
        for (j=i-1;j>=1;j--)
            printf("%d", j);
        for (j=1;j<=n*2-i*2;j++)
            printf("_");

        printf("\n");
    }
}

void pic4(int n)
{
    int i, j;

    for (i=1;i<=n;i++) {
        for (j=1;j<i;j++)
            printf("_");

        if (i % 2 == 0) {  //°¸¼Æ
            for (j=n;j>=1;j--)
                printf("%d", j);
        }
        else {  //©_¼Æ
            for (j=1;j<=n;j++)
                printf("%d", j);
        }

        for (j=1;j<=n-i;j++)
            printf("_");

        printf("\n");
    }
}

int main()
{
    int pic, n;

    scanf("%d %d", &pic, &n);

    if (pic == 1)
        pic1(n);
    else if (pic == 2)
        pic2(n);
    else if (pic == 3)
        pic3(n);
    else
        pic4(n);
}
