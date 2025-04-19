#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first, second;
} pair;

int rule (const void *a, const void *b)
{
    const pair *pair_a = (const pair *)a;
    const pair *pair_b = (const pair *)b;

    if (pair_a->first != pair_b->first)
        return pair_a->first - pair_b->first;

    return pair_a->second - pair_b->second;
}

int main()
{
    int i, j, n, count = 0;

    scanf("%d", &n);

    int a[n];
    pair b[10000];

    for (i=0;i<n;i++)
        scanf(" %d", &a[i]);

    for (i=0;i<n;i++) {
        for (j=i+1;j<n;j++) {
            if (a[i] > a[j]) {
                b[count].first = a[i];
                b[count].second = a[j];
                count++;
            }
        }
    }

    qsort(b, count, sizeof(pair), rule);

    for (i=0;i<count;i++) {
        if (i == 0 || b[i].first != b[i-1].first || b[i].second != b[i-1].second)  //與前面不同或 i == 0
            printf("(%d,%d)\n", b[i].first, b[i].second);
    }

    if (count == 0)
        printf("0");
}
