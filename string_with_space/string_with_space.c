#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];  //�r���}�C��r��

    //fgets(�r��, �r��j�p, ��J)
    fgets(str, 100, stdin);  //��J�i�]�t�Ů檺�r��

    //strcspn(�r��, "�n�䪺�r��")  ���޸� "" �����r��Ĥ@�Ӧr�Ҧb������
    str[strcspn(str, "\n")] = '\0';  //�N����Ÿ��אּ�r�굲���Ÿ�

    printf("%s", str);
}
