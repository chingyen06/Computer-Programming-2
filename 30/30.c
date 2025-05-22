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
    int no; // 擊球員的打擊次數
    play_t data[5]; // 擊球員的打擊結果
} basePlayer_t;

int main()
{
    basePlayer_t play[9];
    int i, j, times = 0, player = 0;
    int b, point = 0, out_count = 0, three_out = 0, new_pos, mov;
    int base[3]={};
    char input[5];

    for (i=0;i<9;i++) {
        scanf("%d", &play[i].no);  //打擊次數

        for (j=0;j<play[i].no;j++) {
            scanf("%s", input);  //打擊結果

            if (input[1] != 'O') {  //安打
                play[i].data[j].type = BASE_HIT;

                if (input[0] == 'H')  //全壘打
                    play[i].data[j].result.base_hit = 4;
                else
                    play[i].data[j].result.base_hit = input[0] - '0';
            }
            else {  //出局
                play[i].data[j].type = OUT;
                play[i].data[j].result.out_kind = input[0];
            }
        }
    }

    scanf("%d", &b);

    while (out_count < b) {
        if (player == 9) {
            player = 0;  //第幾個球員擊打
            times++;  //第幾次擊打
        }

        if (three_out == 3) {  //三出局，清空壘包
            for (i=0;i<=2;i++)
                base[i] = 0;

            three_out = 0;  //清空三振紀錄
        }

        if (play[player].data[times].type == OUT) {  //出局
            out_count++;
            three_out++;
        }
        else {  //安打
            mov = play[player].data[times].result.base_hit;  //打擊幾壘安打

            for (i=2;i>=0;i--) {
                if (base[i] == 0)  //此壘包無人
                    continue;

                base[i] = 0;  //清空這一壘
                new_pos = i + mov;  //推進幾壘

                if (new_pos > 2)  //跑回本壘
                    point++;
                else  //跑到某一壘
                    base[new_pos] = 1;
            }

            if (mov == 4)  //全壘打
                point++;
            else
                base[mov-1] = 1;  //打者上壘
        }

        player++;
    }

    printf("%d", point);

    return 0;
}
