#include <stdio.h>
#include <string.h>

typedef struct student_s {
    char name[50];
    int score;
} student_t;

void input(student_t s[], int n)
{
    int i;

    for (i=0;i<n;i++)
        scanf("%s %d", s[i].name, &s[i].score);
}

void getHigh(student_t s[], int n, char name[], int *highScore)
{
    int i, max = 0;

    for (i=0;i<n;i++) {
        if (s[i].score > max) {
            strcpy(name, s[i].name);
            max = s[i].score;
        }
    }

    *highScore = max;
}

void getLow(student_t s[], int n, char name[], int *lowScore)
{
    int i, min = 101;

    for (i=0;i<n;i++) {
        if (s[i].score < min) {
            strcpy(name, s[i].name);
            min = s[i].score;
        }
    }

    *lowScore = min;
}

int getAverage(student_t s[], int n)
{
    int i, sum = 0;

    for (i=0;i<n;i++)
        sum += s[i].score;  //羆だ

    return sum / n;
}

int getMedian(student_t s[], int n)
{
    int i, j;
    student_t temp;

    for (i=0;i<n;i++) {
        for (j=0;j<n-i-1;j++) {
            if (s[j].score > s[j+1].score) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    if (n % 2 == 0)  //案计
        return (s[n/2].score + s[n/2-1].score) / 2;
    else  //计
        return s[n/2].score;
}

int main()
{
    int n, high_score, low_score, avg, mid;
    char high_name[50], low_name[50];
    student_t student[15];

    scanf("%d", &n);

    input(student, n);

    getHigh(student, n, high_name, &high_score);
    getLow(student, n, low_name, &low_score);
    avg = getAverage(student, n);
    mid = getMedian(student, n);

    printf("%s %d\n", high_name, high_score);  //程蔼
    printf("%s %d\n", low_name, low_score);  //程
    printf("%d\n", avg);  //キА
    printf("%d", mid);  //い计

    return 0;
}
