#include <stdio.h>

int main()
{
    int i, j, n, max = 0;
    int point[3]={}, win[3]={};
    int team1, team2, point1, point2, p1, p2;
    char ch1, ch2;

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        scanf(" %c %c", &ch1, &ch2);

        team1 = ch1 - 'A';  //隊伍1
        team2 = ch2 - 'A';  //隊伍2

        //本局得分歸零
        point1 = 0;
        point2 = 0;

        for (j=0;j<4;j++) {
            scanf("%d %d", &p1, &p2);

            //本場分數加入本局分數
            point1 += p1;
            point2 += p2;
        }

        //本局得分加入總得分
        point[team1] += point1;
        point[team2] += point2;

        if (point1 > point2)  //隊伍1贏
            win[team1]++;
        else  //隊伍2贏
            win[team2]++;
    }

    for (i=1;i<=2;i++)
        if (win[i] > win[max])
            max = i;  //max 存勝場多的隊伍

    printf("%c %d", max+'A', point[max]);

    return 0;
}
