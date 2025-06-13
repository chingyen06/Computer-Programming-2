#include <stdio.h>
//拓撲排序

typedef struct node_s {
    int days;  //開發時間
    int condition;  //剩餘未處理前置項目
    int nextCount;  //等待中的項目數
    int next[200];  //等待中的項目
} node_t;

void process(node_t node[200], int m)
{
    int i, front = 0, end = 0, task, nextTask, temp, max = 0;
    int queue[200]={}, finish[200]={};

    for (i=0;i<m;i++) {
        if (node[i].condition == 0) {  //沒有未處理的前置項目
            queue[end] = i;  //任務列表(佇列)排上 i
            finish[i] = node[i].days;  //完成時間即為開發時間
            end++;

            if (finish[i] > max)  //找出最後一個完成的任務
                max = finish[i];
        }
    }

    while (front < end) {
        task = queue[front];

        for (i=0;i<node[task].nextCount;i++) {
            nextTask = node[task].next[i];  //下個項目的編號
            temp = finish[task] + node[nextTask].days;  //完成此項目 + 下個項目的所需時間

            if (temp > finish[nextTask])  //比原本的完成時間久
                finish[nextTask] = temp;  //時間改成新的所需時間

            node[nextTask].condition--;  //該任務的剩餘未處理前置項目 - 1

            if (node[nextTask].condition == 0) {  //沒有未處理的前置項目
                queue[end] = nextTask;  //任務列表(佇列)排上 nextTask
                end++;

                if (finish[nextTask] > max)  //找出最後一個完成的任務
                    max = finish[nextTask];
            }
        }

        front++;
    }

    printf("%d\n", max);
}

int main()
{
    int i, j;
    int n, m, time, k, task;
    node_t node[200];

    scanf("%d", &n);

    while (n > 0) {
        scanf("%d", &m);

        for (i=0;i<m;i++)
            node[i].condition = 0;  //等待中的前置項目歸零

        for (i=0;i<m;i++) {
            scanf("%d %d", &time, &k);

            node[i].days = time;  //設定開發時間
            node[i].nextCount = k;  //設定等待中的項目數

            for (j=0;j<k;j++) {
                scanf("%d", &task);

                node[i].next[j] = task - 1;  //設定等待中的項目
                node[task-1].condition++;  //設定等待中的項目的前置項目 + 1
            }
        }

        process(node, m);

        n--;
    }

    return 0;
}
