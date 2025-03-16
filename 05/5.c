#include<stdio.h>

int calculate(int info[5], double plan[5][2], int money)
{
    int i;
    double spend = 0;

    for (i=0;i<5;i++)
        if (info[i] > plan[i][0])
            spend += (info[i] - plan[i][0]) * plan[i][1];

    if (spend < money)
        spend = money;

    return spend;
}

int main()
{
    int i, info[5];
    double plan183[5][2]={{500, 0.08}, {400, 0.1393}, {300, 0.1349}, {10, 1.1287}, {15, 1.4803}},
    plan383[5][2]={{600, 0.07}, {500, 0.1304}, {400, 0.1217}, {20, 1.1127}, {25, 1.2453}},
    plan983[5][2]={{700, 0.06}, {600, 0.1087}, {500, 0.1018}, {30, 0.9572}, {35, 1.1243}};
    double spend183, spend383, spend983;

    for (i=0;i<5;i++)
        scanf("%d", &info[i]);

    spend183 = calculate(info, plan183, 183);
    spend383 = calculate(info, plan383, 383);
    spend983 = calculate(info, plan983, 983);

    if (spend183 < spend383 && spend183 < spend983)
        printf("%.f\n%d", spend183, 183);
    else if (spend383 < spend183 && spend383 < spend983)
        printf("%.f\n%d", spend383, 383);
    else
        printf("%.f\n%d", spend983, 983);

    return 0;
}
