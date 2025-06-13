#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

typedef node_t *nodep_t;

nodep_t create(int data)
{
    nodep_t newNode;

    newNode = (nodep_t)malloc(sizeof(node_t));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insert(nodep_t *p, int data)
{
    nodep_t current;
    nodep_t newNode = create(data);

    if ((*p) == NULL)
        *p = newNode;
    else {
        current = *p;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void input(int *n, nodep_t *p)
{
    int i, a, del;
    char s[50], *str, *delim = " ";

    fgets(s, 50, stdin);

    str = strtok(s, delim);
    while (str != NULL) {
        a = atoi(str);

        insert(p, a);

        str = strtok(NULL, delim);
        (*n)++;
    }
}

int main()
{
    int n1 = 0, n2 = 0, data, max, first = 1, abs_ans;
    nodep_t p1 = NULL, p2 = NULL, ans = NULL;

    //��J
    input(&n1, &p1);
    input(&n2, &p2);

    //�D�̤j�����
    if (n1 >= n2)
        max = n1 - 1;
    else
        max = n2 - 1;

    while (p1 != NULL || p2 != NULL) {
        if (n1 == n2) {
            data = p1->data + p2->data;  //�o���
            p1 = p1->next;  //���ʨ�U�Ӹ`�I
            p2 = p2->next;  //���ʨ�U�Ӹ`�I
            n1--;
            n2--;
        }
        else if (n1 > n2) {
            data = p1->data;  //�o���
            p1 = p1->next;  //���ʨ�U�Ӹ`�I
            n1--;
        }
        else {  //n2 > n1
            data = p2->data;  //�o���
            p2 = p2->next;  //���ʨ�U�Ӹ`�I
            n2--;
        }

        insert(&ans, data);  //�s�W��X���
    }

    while (ans != NULL) {
        if (ans->data != 0) {  //�Y�Ƥ��O0
            if (first) {  //�̰���
                if (ans->data < 0)
                    printf("-");

                first = 0;
            }
            else {
                if (ans->data > 0)
                    printf("+");
                else
                    printf("-");
            }

            abs_ans = abs(ans->data);

            if (max > 1) {
                if (abs_ans != 1)
                    printf("%d", abs_ans);
                printf("x^%d", max);
            }
            else if (max == 1) {  //�@���趵
                if (abs_ans != 1)
                    printf("%d", abs_ans);
                printf("x");
            }
            else  //�`��
                printf("%d", abs_ans);
        }

        ans = ans->next;
        max--;
    }

    if (first == 1)  //����0
        printf("0");

    return 0;
}
