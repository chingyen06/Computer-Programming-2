#include <stdio.h>
#include <string.h>
#define GATEVALUE(Gate) int(*GateValue)(struct _Gate*)

typedef struct _Gate {
    int input1;
    int input2;
    GATEVALUE(Gate);
} Gate;

int three_bits(int num) {
    int com = 7;  //二進位 111

    return num & com;  //與 7(111) 做 AND，除了後三位不變以外其他都變0
}

int GateORValue(Gate *gate) {
    return three_bits(gate->input1 | gate->input2);
}

int GateANDValue(Gate *gate) {
    return three_bits(gate->input1 & gate->input2);
}

int GateNOTValue(Gate *gate) {
    return three_bits(~gate->input1);
}

int GateBUFFERValue(Gate *gate) {
    return three_bits(gate->input1);
}

int GateNANDRValue(Gate *gate) {
    return three_bits(~(gate->input1 & gate->input2));
}

int GateNORValue(Gate *gate) {
    return three_bits(~(gate->input1 | gate->input2));
}

void CreateGate(Gate *obj, char type[], int input1, int input2) {
    obj->input1 = input1;
    obj->input2 = input2;

    if (strcmp(type, "N") == 0)
        obj->GateValue = GateNOTValue;
    else if (strcmp(type, "B") == 0)
        obj->GateValue = GateBUFFERValue;
    else if (strcmp(type, "A") == 0)
        obj->GateValue = GateANDValue;
    else if (strcmp(type, "O") == 0)
        obj->GateValue = GateORValue;
    else if (strcmp(type, "NA") == 0)
        obj->GateValue = GateNANDRValue;
    else
        obj->GateValue = GateNORValue;
}

int main()
{
    int i, x1, x2, x3;
    int value1, value2, value3, y, o, ans[3]={};
    char c1[5], c2[5], c3[5], c4[5], c5[5];
    Gate g1, g2, g3, g4, g5;

    scanf("%d %d %d", &x1, &x2, &x3);

    scanf("%s %s %s %s %s", c1, c2, c3, c4, c5);

    CreateGate(&g1, c1, x1, ~x1);  //建立 g1
    CreateGate(&g2, c2, x2, ~x2);  //建立 g2
    CreateGate(&g3, c3, x3, ~x3);  //建立 g3

    value1 = g1.GateValue(&g1);  //得到 x1 經過 c1 後的值 value1
    value2 = g2.GateValue(&g2);  //得到 x2 經過 c2 後的值 value2
    value3 = g3.GateValue(&g3);  //得到 x3 經過 c3 後的值 value3

    CreateGate(&g4, c4, value1, value2);  //建立 g4

    y = g4.GateValue(&g4);  //得到 value1, value2 經過 c4 後的值 y

    CreateGate(&g5, c5, y, value3);  //建立 g5

    o = g5.GateValue(&g5);  //得到 y, value3 經過 c5 後的值 o

    i = 0;
    while (o > 0) {
        ans[i] = o % 2;
        o = o / 2;

        i++;
    }

    for (i=2;i>=0;i--)
        printf("%d", ans[i]);

    return 0;
}
