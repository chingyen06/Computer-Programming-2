#include <stdio.h>

int wait(int a[10][10], int t[10], int machine[10], int period[10], int i)
{
    int time;

    time = machine[a[i][t[i]]];  //���ݮɶ��]�������������ɶ�

    if (machine[a[i][t[i]]] < period[i])  //�Y�W�ӥ��ȧ������ɶ�������C
        time = period[i];  //���ݮɶ��אּ�W�ӥ��ȧ������ɶ�

    return time;
}

int main()
{
    int i, j;
    int n, m, p, total_p = 0, min, min_t, spend, total_time = 0;
    int a[10][10]={}, t[10]={}, machine[10]={}, period[10]={};
    //a �s�ϥξ����B��O�ɶ�, t �s�ĴX�ӥ���, machine �s�����e�ε����ɶ�

    scanf("%d %d", &n, &m);

    for (i=0;i<m;i++) {
        scanf("%d", &p);

        for (j=0;j<2*p;j=j+2)
            scanf("%d %d", &a[i][j], &a[i][j+1]);  //�ϥξ���, ��O�ɶ�

        total_p += p;
    }

    for (i=0;i<total_p;i++) {
        min = 999;
        min_t = 999;

        for (j=0;j<m;j++) {
            if (a[j][t[j]+1] == 0)  //��O�ɶ��� 0 (�L����)
                continue;

            spend = wait(a, t, machine, period, j) + a[j][t[j]+1];
            //��O�ɶ� = (�����i�H�ϥΪ��ɶ�  ���  �e�@�ӥ��Ȫ�O�ɶ�) + ���Ȫ�O�ɶ� = (���ݮɶ�) + ���Ȫ�O�ɶ�

            if (spend < min) {
                min = spend;
                min_t = j;
            }
        }

        machine[a[min_t][t[min_t]]] = min;  //��s�s���Ⱦ����������ɶ�
        period[min_t] = min;  //�s�o�ӥ��Ȫ������ɶ� (�U���P�_�o�ӵ����ɶ�)
        t[min_t] += 2;  //�o�Ӥu�@����U�ӥ���
    }

    for (i=0;i<m;i++)
        total_time += period[i];  //�C�Ӥu�@�������ɶ�

    printf("%d", total_time);

    return 0;
}
