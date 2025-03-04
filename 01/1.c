#include<stdio.h>
#include<math.h>

int main()
{
    int a, b, c;
    double x1, x2;
    double delta;

    scanf("%d %d %d", &a, &b, &c);  //ax^2+bx+c=0

    delta = b * b - 4 * a * c;

    if (delta >= 0) { //實根
        delta = sqrt(delta);
        x1 = (-b + delta) / (2 * a);
        x2 = (-b - delta) / (2 * a);

        if (x1 == x2)
            printf("%.1f", x1);
        else
            printf("%.1f\n%.1f", x1, x2);
    }
    else {  //虛根
        delta = sqrt(-delta) / (2 * abs(a));
        x1 = (float)(-b) / (float)(2 * a);

        printf("%.1f+%.1fi\n", x1, delta);
        printf("%.1f-%.1fi", x1, delta);
    }

    return 0;
}
