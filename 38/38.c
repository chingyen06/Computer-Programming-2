#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dnode_s {
    int data;
    struct dnode_s *front;
    struct dnode_s *back;
} node_t;

typedef node_t * nodep_t;

nodep_t create(int data)
{
    nodep_t newNode;

    newNode = (nodep_t)malloc(sizeof(node_t));  //配置記憶體 (很重要!)

    newNode->data = data;
    newNode->front = NULL;
    newNode->back = NULL;

    return newNode;
}

void addFrontAndBack(nodep_t *head, nodep_t *tail, int data, char *s)
{
    nodep_t newNode = create(data);

    if (*head == NULL && *tail == NULL) {
        *head = newNode;
        *tail = newNode;
        newNode->front = newNode;
        newNode->back = newNode;
    }
    else {
        newNode->back = *head;  //(newNode 的下個位置)設為(最開始的位置)
        newNode->front = *tail;  //(newNode 的上個位置)設為(最後的位置)
        (*head)->front = newNode;  //(最開始的位置指向的上個位置)設為(newNode)
        (*tail)->back = newNode;  //把(最後的位置的下個位置)設為(newNode)

        if (strcmp(s, "addFront") == 0)  //資料放入串列前端
            *head = newNode;  //head 指向新的節點
        else  //資料放入串列尾端
            *tail = newNode;  //tail 指向新的節點
    }
}

void removeFront(nodep_t *head, nodep_t *tail)
{
    nodep_t next;

    if (*head == NULL)
        printf("Double link list is empty\n");
    else if ((*head)->front == *head && (*head)->back == *head) {  //只有自己
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else {
        next = (*head)->back;  //(next)設為(第二個位置)
        (*tail)->back = next;  //(最後的位置的下個位置)設為(第二個位置)
        next->front = *tail;  //(第二個位置的上個位置)設為(最後的位置)

        free(*head);  //清除最開始的位置
        *head = next;  //head 指向第二個位置
    }
}

void removeBack(nodep_t *head, nodep_t *tail)
{
    nodep_t previous;

    if (*head == NULL)
        printf("Double link list is empty\n");
    else if ((*tail)->front == *tail && (*tail)->back == *tail) {  //只有自己
        free(*tail);
        *head = NULL;
        *tail = NULL;
    }
    else {
        previous = (*tail)->front;  //(previous)設為(倒數第二個位置)
        previous->back = *head;  //(第二個位置的上個位置)設為(最開始的位置)
        (*head)->front = previous;  //(最開始的位置的上個位置)設為(倒數第二個位置)

        free(*tail);  //清除最後的位置
        *tail = previous;  //tail 指向倒數第二個位置
    }
}

void empty(nodep_t *head, nodep_t *tail)
{
    if (*head == NULL && *tail == NULL)
        printf("Double link list is empty\n");
    else {
        *head = NULL;
        *tail = NULL;
    }
}

void insert(nodep_t *head, nodep_t *tail, int pos, int data)
{
    int i = 1, found = 0;
    nodep_t newNode = create(data);
    nodep_t p = *head;
    nodep_t next;

    if (*head == NULL && *tail == NULL) {
        printf("Invalid command\n");
        return 0;
    }

    do {
        if (i == pos) {
            found = 1;  //找到

            if (p == *tail)  //n 是最後的位置
                addFrontAndBack(head, tail, data, "addBack");
            else {
                next = p->back;  //(next)設為(第 n+1 個位置)
                newNode->front = p;  //(newNode 的上個位置)設為(第 n 個位置)
                newNode->back = next;  //(newNode 的下個位置)設為(第 n+1 個位置)
                p->back = newNode;  //(第 n 個位置的下個位置)設為(newNode 的位置)
                next->front = newNode;  //(第 n+1 個位置的上個位置)設為(newNode 的位置)
            }

            break;
        }

        p = p->back;
        i++;
    } while (p != *head);

    if (found == 0)
        printf("Invalid command\n");
}

int Remove(nodep_t *head, nodep_t *tail, int pos)
{
    int i = 1, found = 0;
    nodep_t current = *head;
    nodep_t previous = NULL;
    nodep_t next;

    if (*head == NULL && *tail == NULL) {
        printf("Invalid command\n");
        return 0;
    }

    do {
        if (i == pos) {
            found = 1;  //找到

            if (current == *head)  //n 是最開始的位置
                removeFront(head, tail);
            else if (current == *tail)  //n 是最後的位置
                removeBack(head, tail);
            else {
                next = current->back;  //(next)設為(第 n+1 個位置)
                next->front = previous;  //(第 n+1 個位置的上個位置)設為(第 n-1 個位置)
                previous->back = next;  //(第 n-1 個位置的下個位置)設為(第 n+1 個位置)
                free(current);  //刪除第 n 個位置
            }

            break;
        }

        previous = current;
        current = current->back;
        i++;
    } while (current != *head);

    if (found == 0)
        printf("Invalid command\n");
}

void print(nodep_t head, nodep_t tail)
{
    nodep_t p = head;

    if (head == NULL && tail == NULL)
        printf("Double link list is empty\n");
    else {
        do {
            printf("%d\n", p->data);

            p = p->back;
        } while (p != head);
    }
}

int main()
{
    int i, n, data, pos;
    char s[50];
    nodep_t head = NULL, tail = NULL;

    scanf("%d", &n);

    for (i=0;i<n;i++) {
        scanf(" %s", s);

        if (strcmp(s, "addFront") == 0) {
            scanf("%d", &data);
            addFrontAndBack(&head, &tail, data, "addFront");
        }
        else if (strcmp(s, "addBack") == 0) {
            scanf("%d", &data);
            addFrontAndBack(&head, &tail, data, "addBack");
        }
        else if (strcmp(s, "insert") == 0) {
            scanf("%d %d", &pos, &data);
            insert(&head, &tail, pos, data);
        }
        else if (strcmp(s, "remove") == 0) {
            scanf("%d", &pos);
            Remove(&head, &tail, pos);
        }
        else if (strcmp(s, "removeFront") == 0)
            removeFront(&head, &tail);
        else if (strcmp(s, "removeBack") == 0)
            removeBack(&head, &tail);
        else if (strcmp(s, "empty") == 0)
            empty(&head, &tail);
        else
            print(head, tail);
    }

    return 0;
}
