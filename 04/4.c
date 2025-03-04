#include<stdio.h>

int main()
{
    int H, w, bmi_i;
    double h, bmi;

    scanf("%d %d", &w, &H);

    if (w < 20 || w > 100 || H < 100 || H > 200) {
        printf("ERROR");
        return 0;
    }

    h = (float) H / 100;

    bmi = (float) w / (h * h);

    bmi_i = bmi * 10;

    //printf("%d", bmi_i);

    if (bmi_i % 10 == 5) {
        if (bmi_i / 10 % 10 % 2 == 1)
            bmi = bmi - 0.1;
        else
            bmi = bmi + 0.1;
    }

    printf("%.f\n", bmi);

    if (bmi < 18)
        printf("too low");
    else if (bmi > 24)
        printf("too high");

    return 0;
}
