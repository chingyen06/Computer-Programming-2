#include <stdio.h>
#define start 0  // �_ʼ
#define minus 1  // ݔ���̖ -
#define fi 2     // ��һ���� 0 (+)
#define ni 3     // ��һ���� 0 (-)
#define ih 4     // ��һ���� 1 ~ 9
#define fp 5     // С���c
#define ff 6     // С���c�ᔵ
#define fd 7     // ���c��
#define ib 8     // �� 2 ~ n ��
#define id 9     // ����
#define vf 10     // ��һ�֞�Ӣ���ֻ�׾� (׃��)
#define vw 11    // �_�J׃����������
#define vd 12    // ׃��
#define sd 13    // �ִ�

int get_state(int state, int key) {
    if (state == start && key == '-')
        return minus;  // ؓ��
    else if (state == start && key == '0')
        return fi;  // ��һ���� 0 (+)
    else if (state == minus && key == '0')
        return ni;  // ��һ���� 0 (-)
    else if ((state == fi || state == ni || state == ih || state == ib) && key == '.')
        return fp;  // С���c
    else if ((state == fp || state == ff) && key >= '0' && key <= '9')
        return ff;  // С���c�ᔵ
    else if (state == ff && key == '\0')
        return fd;  // ���c��
    else if ((state == start || state == minus) && key >= '1' && key <= '9')
        return ih;  // ������һ����1 ~ 9
    else if ((state == ih || state == ib) && key >= '0' && key <= '9')
        return ib;  // ������ 2 ~ n ��
    else if ((state == fi || state == ih || state == ib) && key == '\0')
        return id;  // ����
    else if (state == start && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || key == '_'))
        return vf;  // ��һ�֞�Ӣ�Ļ�׾�
    else if ((state == vf || state == vw) && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key >= '0' && key <= '9') || key == '_'))
        return vw;  // ׃���� 2 ~ n ��
    else if (state == vw && key == '\0')
        return vd;  // ׃��
    else
        return sd;  // �ִ�
}

int main() {
    int i, j, n;
    int state, len;
    char key[100];

    scanf("%d", &n);
    getchar(); // �޸ģ����ԓQ�з�

    for (i=0;i<n;i++) {
        state = start;
        len = 0;
        scanf("%s", key);

        for (j=0;j<strlen(key);j++) {
            state = get_state(state, key[j]);
            len++;
        }
        state = get_state(state, '\0');

        if (state == fd && len >= 3 && len <= 50)  // ���c��
            printf("float\n");
        else if (state == id && len >= 1 && len <= 50)  // ����
            printf("integer\n");
        else if (state == vd && len >= 1 && len <= 10)  // ׃��
            printf("variable\n");
        else  // �ִ� (����state == sd �⣬state ��������B�����gֵҲ��)
            printf("string\n");
    }

    return 0;
}
