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

    newNode = (nodep_t)malloc(sizeof(node_t));  //�t�m�O���� (�ܭ��n!)

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
        newNode->back = *head;  //(newNode ���U�Ӧ�m)�]��(�̶}�l����m)
        newNode->front = *tail;  //(newNode ���W�Ӧ�m)�]��(�̫᪺��m)
        (*head)->front = newNode;  //(�̶}�l����m���V���W�Ӧ�m)�]��(newNode)
        (*tail)->back = newNode;  //��(�̫᪺��m���U�Ӧ�m)�]��(newNode)

        if (strcmp(s, "addFront") == 0)  //��Ʃ�J��C�e��
            *head = newNode;  //head ���V�s���`�I
        else  //��Ʃ�J��C����
            *tail = newNode;  //tail ���V�s���`�I
    }
}

void removeFront(nodep_t *head, nodep_t *tail)
{
    nodep_t next;

    if (*head == NULL)
        printf("Double link list is empty\n");
    else if ((*head)->front == *head && (*head)->back == *head) {  //�u���ۤv
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else {
        next = (*head)->back;  //(next)�]��(�ĤG�Ӧ�m)
        (*tail)->back = next;  //(�̫᪺��m���U�Ӧ�m)�]��(�ĤG�Ӧ�m)
        next->front = *tail;  //(�ĤG�Ӧ�m���W�Ӧ�m)�]��(�̫᪺��m)

        free(*head);  //�M���̶}�l����m
        *head = next;  //head ���V�ĤG�Ӧ�m
    }
}

void removeBack(nodep_t *head, nodep_t *tail)
{
    nodep_t previous;

    if (*head == NULL)
        printf("Double link list is empty\n");
    else if ((*tail)->front == *tail && (*tail)->back == *tail) {  //�u���ۤv
        free(*tail);
        *head = NULL;
        *tail = NULL;
    }
    else {
        previous = (*tail)->front;  //(previous)�]��(�˼ƲĤG�Ӧ�m)
        previous->back = *head;  //(�ĤG�Ӧ�m���W�Ӧ�m)�]��(�̶}�l����m)
        (*head)->front = previous;  //(�̶}�l����m���W�Ӧ�m)�]��(�˼ƲĤG�Ӧ�m)

        free(*tail);  //�M���̫᪺��m
        *tail = previous;  //tail ���V�˼ƲĤG�Ӧ�m
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
            found = 1;  //���

            if (p == *tail)  //n �O�̫᪺��m
                addFrontAndBack(head, tail, data, "addBack");
            else {
                next = p->back;  //(next)�]��(�� n+1 �Ӧ�m)
                newNode->front = p;  //(newNode ���W�Ӧ�m)�]��(�� n �Ӧ�m)
                newNode->back = next;  //(newNode ���U�Ӧ�m)�]��(�� n+1 �Ӧ�m)
                p->back = newNode;  //(�� n �Ӧ�m���U�Ӧ�m)�]��(newNode ����m)
                next->front = newNode;  //(�� n+1 �Ӧ�m���W�Ӧ�m)�]��(newNode ����m)
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
            found = 1;  //���

            if (current == *head)  //n �O�̶}�l����m
                removeFront(head, tail);
            else if (current == *tail)  //n �O�̫᪺��m
                removeBack(head, tail);
            else {
                next = current->back;  //(next)�]��(�� n+1 �Ӧ�m)
                next->front = previous;  //(�� n+1 �Ӧ�m���W�Ӧ�m)�]��(�� n-1 �Ӧ�m)
                previous->back = next;  //(�� n-1 �Ӧ�m���U�Ӧ�m)�]��(�� n+1 �Ӧ�m)
                free(current);  //�R���� n �Ӧ�m
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
