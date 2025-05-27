#include <stdio.h>

int wait(int a[10][10], int t[10], int machine[10], int period[10], int i)
{
    int time;

    time = machine[a[i][t[i]]];  //等待時間設為機器完成的時間

    if (machine[a[i][t[i]]] < period[i])  //若上個任務完成的時間比機器慢
        time = period[i];  //等待時間改為上個任務完成的時間

    return time;
}

int main()
{
    int i, j;
    int n, m, p, total_p = 0, min, min_t, spend, total_time = 0;
    int a[10][10]={}, t[10]={}, machine[10]={}, period[10]={};
    //a 存使用機器、花費時間, t 存第幾個任務, machine 存機器占用結束時間

    scanf("%d %d", &n, &m);

    for (i=0;i<m;i++) {
        scanf("%d", &p);

        for (j=0;j<2*p;j=j+2)
            scanf("%d %d", &a[i][j], &a[i][j+1]);  //使用機器, 花費時間

        total_p += p;
    }

    for (i=0;i<total_p;i++) {
        min = 999;
        min_t = 999;

        for (j=0;j<m;j++) {
            if (a[j][t[j]+1] == 0)  //花費時間為 0 (無任務)
                continue;

            spend = wait(a, t, machine, period, j) + a[j][t[j]+1];
            //花費時間 = (機器可以使用的時間  比較  前一個任務花費時間) + 任務花費時間 = (等待時間) + 任務花費時間

            if (spend < min) {
                min = spend;
                min_t = j;
            }
        }

        machine[a[min_t][t[min_t]]] = min;  //更新新任務機器的結束時間
        period[min_t] = min;  //存這個任務的結束時間 (下次判斷這個結束時間)
        t[min_t] += 2;  //這個工作跳到下個任務
    }

    for (i=0;i<m;i++)
        total_time += period[i];  //每個工作完成的時間

    printf("%d", total_time);

    return 0;
}
