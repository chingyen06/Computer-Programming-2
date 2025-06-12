040 唯一二元樹  
請使用以下結構實作。  
  
Link List 架構:  
typedef struct node_s {  
char data;  
struct node_s * right, * left;  
} tree_t;  
typedef tree_t * btree;  
  
給定前序或後序以及中序，請建構唯一的Binary Tree(非二元搜尋樹)。  
輸出該Tree的內容，輸出順序為由上而下，由左而右印出。  
  
前序或後序以及中序代號分別為:  
前序代號：P  
中序代號：I  
後序代號：O  
  
【輸入說明】  
第一行輸入前序、中序或後序的代號。  
第二行輸入上一行輸入尋訪的字串結果A(1<=A的字串長度<=20)，結果皆為大寫英文字母。  
第三行輸入前序、中序或後序的代號。  
第四行輸入上一行輸入尋訪的字串結果B(1<=B的字串長度<=20)。  
  
範例輸入說明:  
Sample Input:  
P (下一行輸入前序結果)  
ABDHIEJKCFLMGNO (前序尋訪Tree的結果)  
I (下一行輸入中序結果)  
HDIBJEKALFMCNGO(中序尋訪Tree的結果)  
  
【輸出說明】  
輸出唯一二元樹的內容，輸出順序為由上而下，由左而右。  
  
Sample Output:  
ABCDEFGHIJKLMNO(唯一二元樹由上而下，由左而右的輸出結果)。  
【測試資料一】  
輸入：  
P  
ABDHIEJKCFLMGNO  
I  
HDIBJEKALFMCNGO  
  
輸出：  
ABCDEFGHIJKLMNO  
  
【測試資料二】  
輸入：  
I  
CHRONEMIA  
O  
AIMENORHC  
  
輸出：  
CHRONEMIA  
  
【測試資料三】  
輸入：  
P  
MQVYBJAWZCDKXHT  
I  
YBVJQWAMCZKDHXT  
  
輸出：  
MQZVACDYJWKXBHT  
  
【測試資料四】  
輸入：  
I  
MXFIPNOEAGDRL  
O  
MFIONPXDRGLAE  
  
輸出：  
EXAMPLINGFORD  
  
【測試資料五】  
輸入：  
O  
EGATNIV  
I  
ITGEANV  
  
輸出：  
VINTAGE  
