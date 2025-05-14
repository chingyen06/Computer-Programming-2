#include <stdio.h>

int collapse, collapse_a, collapse_b, Min = 9999;
int min_mov[10], min_far, min_visited[10];

int dfs(int road[100][100], int position, int n, int visited[], int n_visited, int mov[], int how_far, int far[])
{
    int i, j, a, b, min, min_index, temp[100];

    mov[n_visited] = position;  //紀錄新到的位置
    visited[position] = n_visited;  //將新到的位置設為已造訪
    n_visited++;  //已抵達過的城市數量

    if (n_visited == n) {  //全部抵達
        if (how_far < Min) {
            min_far = 0;  //初始化路徑長
            for (i=0;i<n;i++) {
                min_mov[i] = mov[i] + 1;
                min_visited[i] = visited[i];
                //printf("%d ", mov[i]);

                if (i < collapse)  //封路前走過的路徑長
                    min_far += far[i];
            }

            //printf("\n");

            Min = how_far;
        }

        //恢復狀態
        visited[position] = -1;
        n_visited--;
        mov[n_visited] = 0;

        return 1;
    }

    for (i=0;i<n;i++)  //紀錄road權重
        temp[i] = road[position][i];

    for (i=0;i<n;i++) {
        min_index = -1;
        min = 1e9;

        for (j=0;j<n;j++) {
            if ((min_index == -1 || road[position][j] < road[position][min_index]) && visited[j] == -1 && road[position][j] >= 0) {  //尚未抵達過裡最小的
                min_index = j;
                min = road[position][min_index];
            }
        }

        //printf("%d %d %d\n", position, min_index, road[position][min_index]);

        if (min_index != -1 && min != 1e9) {
            how_far += min;
            far[n_visited] = min;

            road[position][min_index] = 1e9;  //走過了

            dfs(road, min_index, n, visited, n_visited, mov, how_far, far);  //繼續走

            how_far -= min;
            far[n_visited] -= min;
        }
    }

    //恢復狀態
    visited[position] = -1;
    n_visited--;
    mov[n_visited] = 0;

    for (i=0;i<n;i++)  //恢復road權重
        road[position][i] = temp[i];
}

int main()
{
    int i, j, n, position, far2;
    int road[100][100], road2[100][100], visited[100], visited2[100], mov[100], mov2[100], far[100]={}, ans[100];

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            scanf("%d", &road[i][j]);

            road2[i][j] = road[i][j];
        }
    }

    for (i=0;i<n;i++)  //初始化
        visited[i] = -1;

    scanf("%d %d %d", &collapse, &collapse_a, &collapse_b);

    dfs(road, 0, n, visited, 0, mov, 0, far);

    /*for (i=0;i<n;i++)
        printf("%d ", min_mov[i]);
    printf("\n");*/

    for (i=0;i<n;i++)  //將封路後走過的地方移除
        if (min_visited[i] >= collapse)
            min_visited[i] = -1;

    //封路
    road[collapse_a-1][collapse_b-1] = -1;
    road[collapse_b-1][collapse_a-1] = -1;

    for (i=0;i<n;i++)
        if (min_visited[i] == collapse - 1)
            position = i;

    /*for (i=0;i<n;i++)
        printf("%d ", min_visited[i]);
    printf("\n");*/

    for (i=0;i<n;i++) {
        visited2[i] = min_visited[i];
        mov2[i] = min_mov[i];
        //printf("%d ", mov2[i]);
    }

    far2 = min_far;
    Min = 9999;

    /*printf("\n===========\n");

    printf("%d\n", far2);*/

    dfs(road, position, n, visited2, collapse-1, mov2, far2, far);

    for (i=0;i<n;i++)
        ans[min_visited[i]] = i + 1;

    for (i=0;i<n;i++)
        printf("%d ", ans[i]);
    printf("\n%d", Min);

    return 0;
}
/*
【測試資料二】
輸入:
6
0 1 5 1 9 -1
1 0 4 7 -1 3
5 4 0 9 4 8
1 7 9 0 -1 9
9 -1 4 -1 0 10
-1 3 8 9 10 0
3
6 2

輸出:
1 4 6 5 3 2
28
*/
