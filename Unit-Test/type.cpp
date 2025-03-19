#include <string.h>
#define start 0  // �}�l
#define minus 1  // ��J�Ÿ� -
#define fi 2     // �Ĥ@�Ƭ� 0 (+)
#define ih 3     // �Ĥ@�Ƭ� 1 ~ 9
#define fp 4     // �p���I��� 1 ��
#define ff 5     // �p���I��� 2 ~ n ��
#define fd 6     // �B�I��
#define ib 7     // �� 2 ~ n ��
#define id 8     // ���
#define vf 9     // �Ĥ@�r���^��r�Ω��u (�ܼ�)
#define vw 10    // �T�{�ܼƫ�Ҧ��r
#define vd 11    // �ܼ�
#define sd 12    // ERROR

int get_state(int state, int key) {
    if (state == start && key == '-')
        return minus;  // �t��
    else if (state == start && key == '0')
        return fi;  // �Ĥ@�Ƭ� 0
    else if ((state == fi || state == ih || state == ib) && key == '.')
        return fp;  // �p���I
    else if ((state == fp || state == ff) && key >= '0' && key <= '9')
        return ff;  // �p���I���
    else if (state == ff && key == ' ')
        return fd;  // �B�I��
    else if ((state == start || state == minus) && key >= '1' && key <= '9')
        return ih;  // ��ƲĤ@�Ƭ�1 ~ 9
    else if ((state == ih || state == ib) && key >= '0' && key <= '9')
        return ib;  // ��Ʋ� 2 ~ n ��
    else if ((state == fi || state == ih || state == ib) && key == ' ')
        return id;  // ���
    else if (state == start && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || key == '_'))
        return vf;  // �Ĥ@�r���^��Ω��u
    else if ((state == vf || state == vw) && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key >= '0' && key <= '9') || key == '_'))
        return vw;  // �ܼƲ� 2 ~ n �r
    else if ((state == vf || state == vw) && key == ' ')
        return vd;  // �ܼ�
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

		if (state == fd) {  //�B�I��
		    if (neg == 1) {
                strcat(ans, str);
                strcat(ans, " - Positive Floating\n");
	    	}
	    	else {
                strcat(ans, str);
                strcat(ans, " - Negative Floating\n");
	    	}
	    }
	    else if (state == id) {  //���
	    	if (neg == 1) {
                strcat(ans, str);
                strcat(ans, " - Positive Integer\n");
	    	}
	    	else {
                strcat(ans, str);
                strcat(ans, " - Negative Integer\n");
	    	}
		}
	    else if (state == vd) {  //�ܼ�
            strcat(ans, str);
            strcat(ans, " - Identifier\n");
        }
	    else {  //���~
            strcat(ans, str);
            strcat(ans, " - Error\n");
        }

		i = j + 1;
    }

    return ans;
}
