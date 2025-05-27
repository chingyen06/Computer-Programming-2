#include <stdio.h>
#include <string.h>
#define GATEVALUE(Gate) int(*GateValue)(struct _Gate*)

typedef struct _Gate {
    int input1;
    int input2;
    GATEVALUE(Gate);
} Gate;

int three_bits(int num) {
    int com = 7;  //�G�i�� 111

    return num & com;  //�P 7(111) �� AND�A���F��T�줣�ܥH�~��L����0
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

    CreateGate(&g1, c1, x1, ~x1);  //�إ� g1
    CreateGate(&g2, c2, x2, ~x2);  //�إ� g2
    CreateGate(&g3, c3, x3, ~x3);  //�إ� g3

    value1 = g1.GateValue(&g1);  //�o�� x1 �g�L c1 �᪺�� value1
    value2 = g2.GateValue(&g2);  //�o�� x2 �g�L c2 �᪺�� value2
    value3 = g3.GateValue(&g3);  //�o�� x3 �g�L c3 �᪺�� value3

    CreateGate(&g4, c4, value1, value2);  //�إ� g4

    y = g4.GateValue(&g4);  //�o�� value1, value2 �g�L c4 �᪺�� y

    CreateGate(&g5, c5, y, value3);  //�إ� g5

    o = g5.GateValue(&g5);  //�o�� y, value3 �g�L c5 �᪺�� o

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
