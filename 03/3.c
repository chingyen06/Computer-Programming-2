#include<stdio.h>
#include<math.h>

void decimal_to_binary(int s, int *S, int *S_2)
{
    int n = 0;

    while (s > 0) {
        S[n] = s % 2;
        S_2[n] = s % 2;
        s = s / 2;
        n++;
    }

    /*for (int i=0;i<6;i++)
        printf("%d ", S[i]);*/
}

int main()
{
    int i;
    int s0, s1;
    int S0[6]={}, S1[6]={}, S2[6]={}, S3[6]={};
    int error = 0, q1 = 0, q2 = 1, q3 = 0, q4 = 0, q5 = 0;
    char e1, e2;
    char element[6][2]={{'a', '0'}, {'b', '1'}, {'c', '2'}, {'d', '3'}, {'e', '4'}, {'f', '5'}};

    //printf("%c %d", element[1][0], element[1][1]-'0');

    scanf("%d %d %c %c", &s0, &s1, &e1, &e2);

    if (s0 < 0 || s0 > 63) {
        printf("S0 ERROR\n");
        error = 1;
    }

    if (s1 < 0 || s1 > 63) {
        printf("S1 ERROR\n");
        error = 1;
    }

    if (e1 < 'a' || e1 > 'f') {
        printf("e1 ERROR\n");
        error = 1;
    }

    if (e2 < 'a' || e2 > 'f') {
        printf("e2 ERROR\n");
        error = 1;
    }

    if (error == 1)
        return 0;

    decimal_to_binary(s0, S0, S3);  //S3 µL¥Î
    decimal_to_binary(s1, S1, S2);

    for (i=0;i<6;i++)
        if (element[i][0] == e1)
            S2[element[i][1]-'0'] = 1;

    for (i=0;i<6;i++) {
        if (element[i][0] == e2 && S2[element[i][1]-'0'] == 1) {
            q1 = 1;
            printf("Y\n");
        }
    }
    if (q1 == 0)
        printf("N\n");

    for (i=0;i<6;i++) {
        if (S2[i] == 1 && S0[i] == 0) {
            q2 = 0;
            printf("N\n");
            break;
        }
    }
    if (q2 == 1)
        printf("Y\n");

    for (i=0;i<6;i++)
        if (S2[i] == 1 && S0[i] == 1)
            q3 += pow(2, i);
    printf("%d\n", q3);

    for (i=0;i<6;i++)
        if (S2[i] == 1 || S0[i] == 1)
            q4 += pow(2, i);
    printf("%d\n", q4);

    for (i=0;i<6;i++)
        if (S2[i] == 0 && S0[i] == 1)
            q5 += pow(2, i);
    printf("%d", q5);

    return 0;
}
