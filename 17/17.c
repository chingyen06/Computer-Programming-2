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

        team1 = ch1 - 'A';  //����1
        team2 = ch2 - 'A';  //����2

        //�����o���k�s
        point1 = 0;
        point2 = 0;

        for (j=0;j<4;j++) {
            scanf("%d %d", &p1, &p2);

            //�������ƥ[�J��������
            point1 += p1;
            point2 += p2;
        }

        //�����o���[�J�`�o��
        point[team1] += point1;
        point[team2] += point2;

        if (point1 > point2)  //����1Ĺ
            win[team1]++;
        else  //����2Ĺ
            win[team2]++;
    }

    for (i=1;i<=2;i++)
        if (win[i] > win[max])
            max = i;  //max �s�ӳ��h������

    printf("%c %d", max+'A', point[max]);

    return 0;
}
