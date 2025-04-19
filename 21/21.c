#include <stdio.h>

void selection_sort(int d[], int n)
{
    int i, j, min, temp;
    int compare = 0, mov = 0;

    for (i=0;i<n;i++) {
        min = i;

        for (j=i+1;j<n;j++) {
            if (d[j] < d[min])
                min = j;

            compare++;
        }

        if (min != i) {
            temp = d[i];
            d[i] = d[min];
            d[min] = temp;

            mov = mov + 3;
        }
    }

    printf("%d %d\n", compare, mov);
}

void insertion_sort(int d[], int n)
{
    int i, j, target;
    int compare = 0, mov = 0;

    for (i=1;i<n;i++) {
        target = d[i];

        for (j=i;j>=0;j--) {
            compare = compare + 2;  //§PÂ_ j > 0 ¸ò d[j-1] > target

            if (j == 0)
                compare--;  //j == 0 ¤£·|§PÂ_ d[j-1] > target

            if (j > 0 && d[j-1] > target) {
                d[j] = d[j-1];
                mov++;  //a[j] = a[j-1]·h²¾
            }
            else
                break;
        }
        d[j] = target;
        mov = mov + 2;  //a[j] = target ¸ò a[i] ·h²¾ => ¦@ 2 ¦¸
    }

    printf("%d %d", compare, mov);
}

int main()
{
    int i, n;

    scanf("%d", &n);

    int d1[n], d2[n];

    for (i=0;i<n;i++) {
        scanf(" %d", &d1[i]);
        d2[i] = d1[i];
    }

    selection_sort(d1, n);
    insertion_sort(d2, n);

    return 0;
}
