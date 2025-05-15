#include <stdio.h>
#include <math.h>

double f1(int a, double x)
{
    double ans;

    ans = (double) sqrt(a - x * x);

    return ans;
}

double f2(int a, double x)
{
    double ans;

    ans = (double) (a * pow(x, 3) + 7 * x) / sqrt(a + x);

    return ans;
}

double get_integral(double (*f)(int, double), int a, int p, int q, int err)
{
    int i, n = 1;
    double h, t, before_t = 0, xi;

    while (1) {
        t = 0.0;
        h = (double) (q - p) / n;

        t += f(a, p);  //f(p)
        t += f(a, q);  //f(q)

        for (i=1;i<=n-1;i++) {
            xi = (double) p + i * h;

            t += 2 * f(a, xi);  //2 * f(xi)
        }

        t = t * (h / 2);

        if (before_t == 0 || fabs(t - before_t) > pow(10.0, err * (-1))) {
            before_t = t;
            n = n * 2;
        }
        else
            break;
    }

    return t;
}

int main()
{
    int f, a, p, q, err;
    double out;
    double (*ans)(double (*)(int, double), int, int, int, int);

    ans = get_integral;

    while (1) {
        scanf(" %d", &f);

        if (f == 0)
            break;

        if (f != 1 && f != 2) {
            printf("Invalid\n");
            continue;
        }

        scanf(" %d %d %d %d", &a, &p, &q, &err);

        if (f == 1)
            out = ans(f1, a, p, q, err);
        else
            out = ans(f2, a, p, q, err);

        printf("%.12lf\n", out);
    }

    return 0;
}
