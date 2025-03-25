#include <stdio.h>
#include <string.h>

int check_str(char *str)
{
    if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z') || *str == '_')
        return 1;

    return 0;
}

void reverse(char *str)
{
    char temp;
    char *start = str, *end = str + strlen(str) - 1;
    //start ���V str ���V���a�}, end ���V�r��̫�@�Ӧr����m

    while (start < end) {
        temp = *start;  //temp = start ���V���a�}����
        *start = *end;  //start ���V���a�}���� = end ���V���a�}����
        *end = temp;  //end ���V���a�}���� = temp

        start++;
        end--;
    }
}

int get_len(char *str)
{
    int t = 0;

    while (*str) {
        if (*str != ' ')
            t++;

        str++;
    }

    return t;
}

int main()
{
    int len1, len2;
    char str1[100], str2[100];

    //fgets(�r��, �r��j�p, ��J)
    fgets(str1, 100, stdin);  //��J�i�]�t�Ů檺�r��
    str1[strcspn(str1, "\n")] = '\0';  //�R������Ÿ�

    if (check_str(str1) == 0 || check_str(str1+strlen(str1)-1) == 0) {
        printf("Error");
        return 0;
    }

    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (check_str(str2) == 0) {
        printf("Error");
        return 0;
    }

    reverse(str1);
    reverse(str2);

    printf("%s\n%s\n", str1, str2);

    reverse(str1);
    reverse(str2);

    len1 = get_len(str1);
    len2 = get_len(str2);

    if (len2 > len1)
        printf("%s", str2);
    else
        printf("%s", str1);

    return 0;
}
