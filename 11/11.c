#include<stdio.h>

void gray_code(int n, int k, char *code)
{
    if (n == 1) {
        code[0] = (char) (k + '0');
        code[1] = '\0';  //�r�굲��
    }
    else if (k < pow(2, (n-1))) {
        code[0] = '0';
        gray_code(n-1, k, code+1);  //code + 1 => ����Щ��k����U�@�Ӧ�m
    }
    else {
        code[0] = '1';
        gray_code(n-1, pow(2, n)-1-k, code+1);  //code + 1 => ����Щ��k����U�@�Ӧ�m
    }
}

int main()
{
    char code[32];  //�]���ŧi�bmain�A�ҥH�C���iwhile�j�鳣�|�O�@�}�l���ˤl
    int n, k;

    while (1) {
        scanf("%d", &n);

        if (n == -1)
            break;

        scanf(" %d", &k);

        gray_code(n, k, code);

        printf("%s\n", code);
    }

    return 0;
}
