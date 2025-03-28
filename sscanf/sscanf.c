#include <stdio.h>

int main()
{
    char str[]={'-', '3', '(', '4', '/', '7', ')', '\0'};  //-3(4/7)
    int bring, numerator, denominator;

    //sscanf(字串, "格式", 變數 ...)
    sscanf(str, "%d(%d/%d)", &bring, &numerator, &denominator);

    printf("original: %s\nbring: %d\nnumerator: %d\ndenominator: %d\n", str, bring, numerator, denominator);

    return 0;
}
