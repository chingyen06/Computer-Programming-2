#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

typedef node_t * nodep_t;

nodep_t create(int data)
{
    nodep_t newNode;
    newNode = (nodep_t)malloc(sizeof(node_t));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insert_end(nodep_t *p, int data)  //queue
{
    nodep_t current;
    nodep_t newNode = create(data);

    if (*p == NULL)
        *p = newNode;
    else {
        current = *p;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insert_begin(nodep_t *p, int data)  //stack
{
    nodep_t newNode = create(data);

    if (*p == NULL)
        *p = newNode;
    else {
        newNode->next = *p;

        *p = newNode;
    }
}

void popAndTopFront(nodep_t *p, char *s, char *name)
{
    nodep_t current;

    if (*p == NULL)
        printf("%s is empty\n", name);
    else {
        current = *p;

        printf("%d\n", current->data);

        if (strcmp(s, "pop") == 0) {  //是 pop
            *p = current->next;  //指向下一個
            free(current);  //清除第一個
        }
    }
}

void empty(nodep_t *p, char *name)
{
    if (*p == NULL)
        printf("%s is empty\n", name);
    else
        *p = NULL;
}

void print(nodep_t *p, char *name)
{
    nodep_t current;

    if (*p == NULL)
        printf("%s is empty\n", name);
    else {
        current = *p;

        while (current != NULL) {
            printf("%d\n", current->data);

            current = current->next;
        }
    }
}

void operateQueue(nodep_t *queue, char *s, int data)
{
    if (strcmp(s, "push") == 0)  //push
        insert_end(queue, data);
    else if (strcmp(s, "pop") == 0 || strcmp(s, "front") == 0)  //pop, front
        popAndTopFront(queue, s, "Queue");
    else if (strcmp(s, "empty") == 0)  //empty
        empty(queue, "Queue");
    else  //print
        print(queue, "Queue");
}

void operateStack(nodep_t *stack, char *s, int data)
{
    if (strcmp(s, "push") == 0)  //push
        insert_begin(stack, data);
    else if (strcmp(s, "pop") == 0 || strcmp(s, "top") == 0)  //pop, top
        popAndTopFront(stack, s, "Stack");
    else if (strcmp(s, "empty") == 0)
        empty(stack, "Stack");
    else  //print
        print(stack, "Stack");
}

int main()
{
    int i, j, n, data;
    char s[50], *s1, *s2, *s3, *delim = " ";
    nodep_t stack = NULL, queue = NULL;

    scanf("%d", &n);
    getchar();

    for (i=0;i<n;i++) {
        fgets(s, 50, stdin);
        s[strcspn(s, "\n")] = '\0';

        s1 = strtok(s, delim);  //stack, queue
        s2 = strtok(NULL, delim);  //操作

        if (strcmp(s2, "push") == 0) {
            s3 = strtok(NULL, delim);
            data = atoi(s3);  //字串轉整數
        }

        if (strcmp(s1, "stack") == 0)
            operateStack(&stack, s2, data);
        else
            operateQueue(&queue, s2, data);
    }

    return 0;
}
