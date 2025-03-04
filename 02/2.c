#include<stdio.h>

int main()
{
    int i, j;
    int player, point = 0, out = 0;
    int base[4]={1, 0, 0, 0};  //打者, 一壘, 二壘, 三壘, 得分(本壘)

    for (i=0;i<5;i++) {
        scanf(" %d", &player);

        if (out == 3) {
            for (j=1;j<=3;j++)
                base[j] = 0;
            out = 0;
        }

        if (player == 0)
            out++;

        for (j=3;j>=4-player;j--)
            point += base[j];

        for (j=3;j>=1;j--) {
            if (j - player < 0)
                base[j] = 0;
            else
                base[j] = base[j-player];
        }

        //printf("%d %d %d %d\n", base[1], base[2], base[3], point);
    }

    printf("%d\n", point);
    if (out == 3)
        printf("0 0 0");
    else
        printf("%d %d %d", base[1], base[2], base[3]);

    return 0;
}
