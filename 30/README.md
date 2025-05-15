030 棒球遊戲  
  
請使用以下提供的Union以及Struct進行實作  
  
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
  
  
球場上有四個壘包，稱為本壘、一、二和三壘。在本壘握球棒打的稱「擊球員」，站在另外三個壘包稱「跑員」。擊球員打擊結果為「安打」時，場上擊球員與跑壘員可移動。「出局」時,跑壘員不動，擊球員離場換下一位。球隊共九位球員，依序排列。比賽開始由第一位打擊，當第i位球員打擊完，由第(i+1)位球員打擊。當第九位球員完後,輪回第一位球員。當打出 K 壘打時，場上球員（擊球員和跑壘員）會前進 K 個壘包。從本壘前進 一個壘包會移動到一壘，接著是二壘、三壘，最後回到本壘。每位球員回到本壘時可得 1 分。每達到三個出局數時，一、二和三壘就會清空（跑壘員都得離開）。  
  
假設擊球員的打擊結果只有以下情況：  
(1) 安打：以 1B，2B，3B 和 HR 分別代表一壘、二壘、三壘和全(四)壘打。  
(2) 出局：以 FO，GO，和 SO 表示。  
簡化版模擬讀入棒球隊每位球員打擊結果，計算得分  
  
【輸入說明】  
每組測試資料固定有十行  
第一到九行，依照球員順序，每一行代表一位球員的打擊資訊。每一行開始有一個  
正整數 a (1 ≤ a ≤ 5)，代表球員總共打了 a 次。接下來有 a 個字串（均為兩個字元），依序代表每次打擊的結果。  
第十行有一個正整數 b (1 ≤ b ≤ 27)，表示我們想要計算當總出局數累計到 b 時，該球隊的得分。輸入的打擊資訊中至少包含 b 個出局。  
  
範例輸入說明:  
5 1B 1B FO GO 1B (打擊次數為5, 打擊結果分別為1B 1B FO GO 1B)  
5 1B 2B FO FO SO (打擊次數為5, 打擊結果分別為1B 2B FO FO SO)  
4 SO HR SO 1B (打擊次數為4, 打擊結果分別為SO HR SO 1B)  
4 FO FO FO HR (打擊次數為4, 打擊結果分別為FO FO FO HR)  
4 1B 1B 1B 1B (打擊次數為4, 打擊結果分別為1B 1B 1B 1B)  
4 GO GO 3B GO (打擊次數為4, 打擊結果分別為GO GO 3B GO)  
4 1B GO GO SO (打擊次數為4, 打擊結果分別為1B GO GO SO)  
4 SO GO 2B 2B (打擊次數為4, 打擊結果分別為SO GO 2B 2B)  
4 3B GO FO FO (打擊次數為4, 打擊結果分別為3B GO FO FO)  
6 (比賽在累積 6 次出局時停止計算得分)  
  
【輸出說明】  
計算在總計第 b 個出局數發生時的總得分，並將此得分輸出於一行。  
  
範例輸出說明:  
5  
  
【測試資料一】  
輸入：  
3 FO GO SO  
3 FO GO SO  
3 FO GO SO  
3 FO GO SO  
3 FO GO SO  
3 FO GO SO  
3 FO GO SO  
3 FO GO SO  
3 FO GO SO  
12  
  
輸出：  
0  
  
【測試資料二】  
輸入：  
4 HR HR HR HR  
4 HR HR HR HR  
4 HR HR HR HR  
4 HR HR HR HR  
4 HR HR HR HR  
4 HR HR HR HR  
4 HR HR HR HR  
4 HR HR HR HR  
4 HR HR HR FO  
1  
  
輸出：  
35  
  
【測試資料三】  
輸入：  
3 1B 1B 1B  
3 1B 1B 1B  
3 FO FO FO  
3 2B 2B 2B  
3 2B 2B 2B  
3 SO SO SO  
3 3B 3B 3B  
3 3B 3B 3B  
3 GO GO GO  
9  
  
輸出：  
15  
  
【測試資料四】  
輸入：  
3 1B 3B 1B  
3 1B HR 1B  
3 1B SO FO  
3 FO 1B 1B  
3 2B 1B 1B  
3 2B FO FO  
3 GO 1B 1B  
3 3B 1B 1B  
3 3B FO FO  
3  
  
輸出：  
9  
  
【測試資料五】  
輸入：  
3 FO 3B 2B  
3 FO HR 2B  
3 FO FO HR  
3 FO 1B FO  
3 SO 1B FO  
3 GO 1B FO  
3 FO FO FO  
3 FO 1B 1B  
3 FO FO FO  
15  
  
輸出：  
6  
