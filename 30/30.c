#include <stdio.h>
#include <string.h>

typedef enum { OUT, BASE_HIT } play_type_t;

typedef union {
    int base_hit; // 1~4: number of bases
    char out_kind; // 'F', 'S', 'G'
} play_result_t;

typedef struct {
    play_type_t type;
    play_result_t result;
} play_t;

typedef struct {
    int no; // ���y������������
    play_t data[5]; // ���y�����������G
} basePlayer_t;

int main()
{
    basePlayer_t play[9];
    int i, j, times = 0, player = 0;
    int b, point = 0, out_count = 0, three_out = 0, new_pos, mov;
    int base[3]={};
    char input[5];

    for (i=0;i<9;i++) {
        scanf("%d", &play[i].no);  //��������

        for (j=0;j<play[i].no;j++) {
            scanf("%s", input);  //�������G

            if (input[1] != 'O') {  //�w��
                play[i].data[j].type = BASE_HIT;

                if (input[0] == 'H')  //���S��
                    play[i].data[j].result.base_hit = 4;
                else
                    play[i].data[j].result.base_hit = input[0] - '0';
            }
            else {  //�X��
                play[i].data[j].type = OUT;
                play[i].data[j].result.out_kind = input[0];
            }
        }
    }

    scanf("%d", &b);

    while (out_count < b) {
        if (player == 9) {
            player = 0;  //�ĴX�Ӳy������
            times++;  //�ĴX������
        }

        if (three_out == 3) {  //�T�X���A�M���S�]
            for (i=0;i<=2;i++)
                base[i] = 0;

            three_out = 0;  //�M�ŤT������
        }

        if (play[player].data[times].type == OUT) {  //�X��
            out_count++;
            three_out++;
        }
        else {  //�w��
            mov = play[player].data[times].result.base_hit;  //�����X�S�w��

            for (i=2;i>=0;i--) {
                if (base[i] == 0)  //���S�]�L�H
                    continue;

                base[i] = 0;  //�M�ųo�@�S
                new_pos = i + mov;  //���i�X�S

                if (new_pos > 2)  //�]�^���S
                    point++;
                else  //�]��Y�@�S
                    base[new_pos] = 1;
            }

            if (mov == 4)  //���S��
                point++;
            else
                base[mov-1] = 1;  //���̤W�S
        }

        player++;
    }

    printf("%d", point);

    return 0;
}
