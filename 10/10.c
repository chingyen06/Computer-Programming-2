#include<stdio.h>

int C(int m, int r)
{
    if (m == 0 || m == 1)
        return r;
    else if (m % 2 == 0)
        return C(m/2, r+1);
    else
        return C((m+1)/2, r+1);
}

int main()
{
    char M[9], R[5];
    int i, m, r;

    while (1) {
        scanf(" %s", &M);

        if (M[0] == '-' && M[1] == '1' && M[2] == '\0')
            break;

        m = 0;

        for (i=0;i<8;i++)
            m += (M[i] - '0') * pow(2, 7-i);

        r = C(m, 0);

        i = 3;

        while (i >= 0) {
            R[i] = (char) (r % 2 + '0');

            r = r / 2;
            i--;
        }
        R[4] = '\0';

        printf("%s\n", R);
    }

    return 0;
}
