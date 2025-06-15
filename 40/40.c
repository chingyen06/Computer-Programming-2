#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char data;
    struct node_s * right, * left;
} tree_t;

typedef tree_t *btree;

btree create(char data)
{
    btree newNode;
    newNode = (btree)malloc(sizeof(tree_t));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int preorder(btree *tree, char str[50], char inorder[50], int dir)
{
    int i;
    char data = str[0];
    char left[50], right[50], inleft[50], inright[50];
    btree newNode = create(data);

    if (strlen(inorder) == 0)  //無子節點
        return 0;

    *tree = newNode;  //新增節點

    for (i=0;i<strlen(inorder);i++)  //中序找到父節點
        if (inorder[i] == data)
            break;

    //左子樹 - 前序
    memmove(left, str + 1, i);
    left[i] = '\0';
    //左子樹 - 中序
    memmove(inleft, inorder, i);
    inleft[i] = '\0';

    //右子樹 - 前序
    strcpy(right, str + i + 1);
    //右子樹 - 中序
    strcpy(inright, inorder + i + 1);

    preorder(&((*tree)->left), left, inleft, 1);
    preorder(&((*tree)->right), right, inright, 2);
}

int postorder(btree *tree, char str[50], char inorder[50], int dir)
{
    int i, len = strlen(str) - 1;
    char data = str[len];
    char left[50], right[50], inleft[50], inright[50];
    btree newNode = create(data);

    if (strlen(inorder) == 0)  //無子節點
        return 0;

    *tree = newNode;  //新增節點

    for (i=0;i<strlen(inorder);i++)  //中序找到父節點
        if (inorder[i] == data)
            break;

    //左子樹 - 後序
    memmove(left, str, i);
    left[i] = '\0';
    //左子樹 - 中序
    memmove(inleft, inorder, i);
    inleft[i] = '\0';

    //右子樹 - 後序
    memmove(right, str + i, 50);
    right[len-i] = '\0';
    //右子樹 - 中序
    memmove(inright, inorder + i + 1, 50);

    //printf("%s\n%s\n", left, right);
    postorder(&((*tree)->left), left, inleft, 1);
    postorder(&((*tree)->right), right, inright, 2);
}

int print(btree tree) {
    int front = 0, rear = 0;
    btree queue[1000];

    if (tree == NULL)
        return 0;

    queue[rear] = tree;
    rear++;

    while (front < rear) {
        btree current = queue[front];
        printf("%c", current->data);

        if (current->left != NULL) {  //新增左子節點值
            queue[rear] = current->left;
            rear++;
        }
        if (current->right != NULL) {  //新增右子節點值
            queue[rear] = current->right;
            rear++;
        }

        front++;
    }
}

int main()
{
    char code1, code2, temp_code;
    char str1[50], str2[50], temp_str[50];
    btree tree = NULL;

    scanf(" %c %s", &code1, str1);
    scanf(" %c %s", &code2, str2);

    if (code1 == 'I') {  //中序在第一個
        //換到第二個
        temp_code = code2;
        code2 = code1;
        code1 = temp_code;
        strcpy(temp_str, str2);
        strcpy(str2, str1);
        strcpy(str1, temp_str);
    }

    if (code1 == 'P') {  //前序
        preorder(&tree, str1, str2, 0);
    }
    else {  //後序
        postorder(&tree, str1, str2, 0);
    }

    print(tree);

    return 0;
}
