#include <string.h>
#define start 0  // 秨﹍
#define minus 1  // 块才腹 -
#define fi 2     // 材计 0 (+)
#define ih 3     // 材计 1 ~ 9
#define fp 4     // 计翴材 1 计
#define ff 5     // 计翴材 2 ~ n 计
#define fd 6     // 疊翴计
#define ib 7     // 材 2 ~ n 计
#define id 8     // 俱计
#define vf 9     // 材璣ゅ┪┏絬 (跑计)
#define vw 10    // 絋粄跑计┮Τ
#define vd 11    // 跑计
#define sd 12    // ERROR

int get_state(int state, int key) {
    if (state == start && key == '-')
        return minus;  // 璽计
    else if (state == start && key == '0')
        return fi;  // 材计 0
    else if ((state == fi || state == ih || state == ib) && key == '.')
        return fp;  // 计翴
    else if ((state == fp || state == ff) && key >= '0' && key <= '9')
        return ff;  // 计翴计
    else if (state == ff && key == ' ')
        return fd;  // 疊翴计
    else if ((state == start || state == minus) && key >= '1' && key <= '9')
        return ih;  // 俱计材计1 ~ 9
    else if ((state == ih || state == ib) && key >= '0' && key <= '9')
        return ib;  // 俱计材 2 ~ n 计
    else if ((state == fi || state == ih || state == ib) && key == ' ')
        return id;  // 俱计
    else if (state == start && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || key == '_'))
        return vf;  // 材璣ゅ┪┏絬
    else if ((state == vf || state == vw) && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key >= '0' && key <= '9') || key == '_'))
        return vw;  // 跑计材 2 ~ n 
    else if ((state == vf || state == vw) && key == ' ')
        return vd;  // 跑计
    else
        return sd;  // ERROR
}

const char* mul(const char *key) {
    int i = 0, j, k;
    int state, neg;
    static char ans[1000]="";
    
    memset(ans, '\0', sizeof(ans));

    while (key[i] != '#') {
        char str[100]="";
    	state = start;
    	neg = 1;
    	j = i - 1;

    	while (1) {
    		j++;
    		state = get_state(state, key[j]);
    		str[j-i] = key[j];

    		if (key[j] == ' ')
    			break;

    		if (state == minus)
            	neg = -1;
		}
		str[j-i] = '\0';

		if (state == fd) {  //疊翴计
		    if (neg == 1) {
                strcat(ans, str);
                strcat(ans, " - Positive Floating\n");
	    	}
	    	else {
                strcat(ans, str);
                strcat(ans, " - Negative Floating\n");
	    	}
	    }
	    else if (state == id) {  //俱计
	    	if (neg == 1) {
                strcat(ans, str);
                strcat(ans, " - Positive Integer\n");
	    	}
	    	else {
                strcat(ans, str);
                strcat(ans, " - Negative Integer\n");
	    	}
		}
	    else if (state == vd) {  //跑计
            strcat(ans, str);
            strcat(ans, " - Identifier\n");
        }
	    else {  //岿粇
            strcat(ans, str);
            strcat(ans, " - Error\n");
        }

		i = j + 1;
    }

    return ans;
}
