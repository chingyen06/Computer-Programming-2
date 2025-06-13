#include <stdio.h>
//�ݼ��Ƨ�

typedef struct node_s {
    int days;  //�}�o�ɶ�
    int condition;  //�Ѿl���B�z�e�m����
    int nextCount;  //���ݤ������ؼ�
    int next[200];  //���ݤ�������
} node_t;

void process(node_t node[200], int m)
{
    int i, front = 0, end = 0, task, nextTask, temp, max = 0;
    int queue[200]={}, finish[200]={};

    for (i=0;i<m;i++) {
        if (node[i].condition == 0) {  //�S�����B�z���e�m����
            queue[end] = i;  //���ȦC��(��C)�ƤW i
            finish[i] = node[i].days;  //�����ɶ��Y���}�o�ɶ�
            end++;

            if (finish[i] > max)  //��X�̫�@�ӧ���������
                max = finish[i];
        }
    }

    while (front < end) {
        task = queue[front];

        for (i=0;i<node[task].nextCount;i++) {
            nextTask = node[task].next[i];  //�U�Ӷ��ت��s��
            temp = finish[task] + node[nextTask].days;  //���������� + �U�Ӷ��ت��һݮɶ�

            if (temp > finish[nextTask])  //��쥻�������ɶ��[
                finish[nextTask] = temp;  //�ɶ��令�s���һݮɶ�

            node[nextTask].condition--;  //�ӥ��Ȫ��Ѿl���B�z�e�m���� - 1

            if (node[nextTask].condition == 0) {  //�S�����B�z���e�m����
                queue[end] = nextTask;  //���ȦC��(��C)�ƤW nextTask
                end++;

                if (finish[nextTask] > max)  //��X�̫�@�ӧ���������
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
            node[i].condition = 0;  //���ݤ����e�m�����k�s

        for (i=0;i<m;i++) {
            scanf("%d %d", &time, &k);

            node[i].days = time;  //�]�w�}�o�ɶ�
            node[i].nextCount = k;  //�]�w���ݤ������ؼ�

            for (j=0;j<k;j++) {
                scanf("%d", &task);

                node[i].next[j] = task - 1;  //�]�w���ݤ�������
                node[task-1].condition++;  //�]�w���ݤ������ت��e�m���� + 1
            }
        }

        process(node, m);

        n--;
    }

    return 0;
}
