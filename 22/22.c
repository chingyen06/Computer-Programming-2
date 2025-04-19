#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int y, x;
} coord;

coord coords[100];
int n, coords_count = 0, index = 0;
//�`�ؤo, ��ĴX��coords, ��ĴX�� DF-expression �ǦC

int rule(const void *a, const void *b)
{
    const coord *coords_a = (const coord *)a;
    const coord *coords_b = (const coord *)b;

    if (coords_a->y != coords_b->y)
        return coords_a->y - coords_b->y;

    return coords_a->x - coords_b->x;
}

void DF(const char s[], int y, int x, int size)
{
    int i, n, half = size / 2;

    if (s[index] == '1') {
        for (i=0;i<size*size;i++) {
            coords[coords_count].y = y + (i / size);
            coords[coords_count].x = x + (i % size);

            coords_count++;
        }

        index++;
    }
    else if (s[index] == '2') {
        index++;

        DF(s, y, x, half);
        DF(s, y, x + half, half);
        DF(s, y + half, x, half);
        DF(s, y + half, x + half, half);
    }
    else
        index++;
}

int main()
{
    int i;
    char s[101];

    scanf("%s %d", s, &n);

    DF(s, 0, 0, n);
    //��F��, �ثe�����W�� y, �ثe���k�W�� x, �ثe���쪺�ؤo

    qsort(coords, coords_count, sizeof(coord), rule);

    for (i=0;i<coords_count;i++)
        printf("%d,%d\n", coords[i].y, coords[i].x);

    if (coords_count == 0)
        printf("all white");
}
