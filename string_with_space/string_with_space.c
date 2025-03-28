#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];  //字元陣列當字串

    //fgets(字串, 字串大小, 輸入)
    fgets(str, 100, stdin);  //輸入可包含空格的字串

    //strcspn(字串, "要找的字串")  找到引號 "" 中的字串第一個字所在的索引
    str[strcspn(str, "\n")] = '\0';  //將換行符號改為字串結束符號

    printf("%s", str);

    return 0;
}
