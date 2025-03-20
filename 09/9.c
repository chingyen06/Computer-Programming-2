#include <stdio.h>
#define start 0  // 開始
#define minus 1  // 輸入符號 -
#define fi 2     // 第一數為 0 (+)
#define ni 3     // 第一數為 0 (-)
#define ih 4     // 第一數為 1 ~ 9
#define fp 5     // 小數點
#define ff 6     // 小數點後數
#define fd 7     // 浮點數
#define ib 8     // 第 2 ~ n 數
#define id 9     // 整數
#define vf 10     // 第一字為英文字或底線 (變數)
#define vw 11    // 確認變數後所有字
#define vd 12    // 變數
#define sd 13    // 字串

int get_state(int state, int key) {
    if (state == start && key == '-')
        return minus;  // 負數
    else if (state == start && key == '0')
        return fi;  // 第一數為 0 (+)
    else if (state == minus && key == '0')
        return ni;  // 第一數為 0 (-)
    else if ((state == fi || state == ni || state == ih || state == ib) && key == '.')
        return fp;  // 小數點
    else if ((state == fp || state == ff) && key >= '0' && key <= '9')
        return ff;  // 小數點後數
    else if (state == ff && key == '\0')
        return fd;  // 浮點數
    else if ((state == start || state == minus) && key >= '1' && key <= '9')
        return ih;  // 整數第一數為1 ~ 9
    else if ((state == ih || state == ib) && key >= '0' && key <= '9')
        return ib;  // 整數第 2 ~ n 數
    else if ((state == fi || state == ih || state == ib) && key == '\0')
        return id;  // 整數
    else if (state == start && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || key == '_'))
        return vf;  // 第一字為英文或底線
    else if ((state == vf || state == vw) && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key >= '0' && key <= '9') || key == '_'))
        return vw;  // 變數第 2 ~ n 字
    else if (state == vw && key == '\0')
        return vd;  // 變數
    else
        return sd;  // 字串
}

int main() {
    int i, j, n;
    int state, len;
    char key[100];

    scanf("%d", &n);
    getchar(); // 修改：忽略換行符

    for (i=0;i<n;i++) {
        state = start;
        len = 0;
        scanf("%s", key);

        for (j=0;j<strlen(key);j++) {
            state = get_state(state, key[j]);
            len++;
        }
        state = get_state(state, '\0');

        if (state == fd && len >= 3 && len <= 50)  // 浮點數
            printf("float\n");
        else if (state == id && len >= 1 && len <= 50)  // 整數
            printf("integer\n");
        else if (state == vd && len >= 1 && len <= 10)  // 變數
            printf("variable\n");
        else  // 字串 (除了state == sd 外，state 是其他狀態的中間值也是)
            printf("string\n");
    }

    return 0;
}
