#include <stdio.h>
#include <string.h>

typedef enum scoreType_s{G,GPA,S}scoreType_t;

typedef enum G_s{Aplus,A,Aduce,Bplus,B,Bduce,Cplus,C,Cduce,F,X}G_t;

typedef enum GPA_s{b4dot3,b4dot0,b3dot7,b3dot3,b3dot0,b2dot7,b2dot3,b2dot0,b1dot7,b1,b0}GPA_t;

typedef enum S_s{b90to100,b85to89,b80to84, b77to79,b73to76,b70to72,b67to69,b63to66,b60to62,b1to59,b0to0}S_t;

typedef union student_s {
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
} student_t;

typedef struct studentInfo_s {
    int id;
    student_t fullScore[4];
    int avg;
} studentInfo_t;

int G_type(G_t *score, char g[])
{
    if (strcmp(g, "A+") == 0)
        *score = Aplus;
    else if (strcmp(g, "A") == 0)
        *score = A;
    else if (strcmp(g, "A-") == 0)
        *score = Aduce;
    else if (strcmp(g, "B+") == 0)
        *score = Bplus;
    else if (strcmp(g, "B") == 0)
        *score = B;
    else if (strcmp(g, "B-") == 0)
        *score = Bduce;
    else if (strcmp(g, "C+") == 0)
        *score = Cplus;
    else if (strcmp(g, "C") == 0)
        *score = C;
    else if (strcmp(g, "C-") == 0)
        *score = Cduce;
    else if (strcmp(g, "F") == 0)
        *score = F;
    else
        *score = X;
}

int GPA_type(GPA_t *score, double gpa)
{
    if (gpa == 4.3)
        *score = b4dot3;
    else if (gpa == 4.0)
        *score = b4dot0;
    else if (gpa == 3.7)
        *score = b3dot7;
    else if (gpa == 3.3)
        *score = b3dot3;
    else if (gpa == 3.0)
        *score = b3dot0;
    else if (gpa == 2.7)
        *score = b2dot7;
    else if (gpa == 2.3)
        *score = b2dot3;
    else if (gpa == 2.0)
        *score = b2dot0;
    else if (gpa == 1.7)
        *score = b1dot7;
    else if (gpa == 1.0)
        *score = b1;
    else
        *score = b0;
}

int S_type(S_t *score, char s[])
{
    if (strcmp(s, "90-100") == 0)
        *score = b90to100;
    else if (strcmp(s, "85-89") == 0)
        *score = b85to89;
    else if (strcmp(s, "80-84") == 0)
        *score = b80to84;
    else if (strcmp(s, "77-79") == 0)
        *score = b77to79;
    else if (strcmp(s, "73-76") == 0)
        *score = b73to76;
    else if (strcmp(s, "70-72") == 0)
        *score = b70to72;
    else if (strcmp(s, "67-69") == 0)
        *score = b67to69;
    else if (strcmp(s, "63-66") == 0)
        *score = b63to66;
    else if (strcmp(s, "60-62") == 0)
        *score = b60to62;
    else if (strcmp(s, "1-59") == 0)
        *score = b1to59;
    else
        *score = b0to0;
}

int main()
{
    int i, j;
    int m, n;
    int score[11]={95,87,82,78,75,70,68,65,60,50,0};
    double gpa;
    char type[4], g[3], s[7];
    scoreType_t scoreType[4];
    studentInfo_t student[10], temp;

    scanf("%d", &m);

    for (i=0;i<m;i++) {
        scanf("%s", type);

        if (strcmp(type, "G") == 0)
            scoreType[i] = G;
        else if (strcmp(type, "GPA") == 0)
            scoreType[i] = GPA;
        else
            scoreType[i] = S;
    }

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        scanf("%d ", &student[i].id);

        for (j=0;j<m;j++) {
            if (scoreType[j] == G) {
                scanf("%s", g);  //student[i].fullScore[j].G
                G_type(&student[i].fullScore[j].G, g);
                student[i].fullScore[j].score = score[student[i].fullScore[j].G];
            }
            else if (scoreType[j] == GPA) {
                scanf("%lf", &gpa);  //student[i].fullScore[j].GPA
                GPA_type(&student[i].fullScore[j].GPA, gpa);
                student[i].fullScore[j].score = score[student[i].fullScore[j].GPA];
            }
            else {
                scanf("%s", s);  //student[i].fullScore[j].S
                S_type(&student[i].fullScore[j].S, s);
                student[i].fullScore[j].score = score[student[i].fullScore[j].S];
            }
        }
    }

    for (i=0;i<n;i++) {
        student[i].avg = 0;  //歸零

        for (j=0;j<m;j++)
            student[i].avg += student[i].fullScore[j].score;  //取總分 (score 的用意就是為了 int)

        student[i].avg /= m;  //取平均
    }

    for (i=0;i<n;i++) {
        for (j=i+1;j<n;j++) {
            if (student[i].avg > student[j].avg) {  //交換 (從小排到大)
                temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }

    for (i=0;i<n;i++)
        printf("%d %d\n", student[i].id, student[i].avg);

    return 0;
}
