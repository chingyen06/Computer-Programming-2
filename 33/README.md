033 邏輯電路圖  
請設計一個邏輯電路模擬器，模擬由各種邏輯閘（AND、OR、NOT 等）所構成的電路，根據輸入值與邏輯閘的種類計算最終的輸出值。  
  
本題需依照下列程式架構撰寫，否則不予計分。  
  
輸入的邏輯閘種類代號如下：  
N：NOT Gate  
B：BUFFER Gate  
A：AND Gate  
O：OR Gate  
NA：NAND Gate  
NO：NOR Gate  
  
所有輸入與中間運算皆以「3 位元」為單位進行處理，任何 NOT 或邏輯運算後的結果，僅保留其最低 3 位元（0~7）。  
例如：  
  
NOT(0) = ~000 = 111 = 7  
  
NOT(5) = ~101 = 010 = 2  
  
程式設計規範：  
解題時可針對範例的架構程式碼做修改，但需符合以下三點：  
1. #define中必須定義函數指標，函數的參數可自行決定  
2. 有定義struct，且當中有使用到第一點的define  
3. 使用struct的函數指標進行本題的實作  
  
#define GATEVALUE(Gate) int(*GateValue)()  
typedef struct _Gate {  
int input1;  
int input2;  
GATEVALUE(Gate);  
}Gate;  
int GateORValue(Gate *gate) {  
...  
}  
int GateANDValue(Gate *gate) {  
...  
}  
int GateNOTValue(Gate *gate) {  
...  
}  
int GateBUFFERValue(Gate *gate) {  
...  
}  
void CreateGate(Gate *obj, char type, int input1, int input2) {  
...  
}  
  
  
  
【輸入說明】  
第一行：輸入三個整數，代表X1, X2, X3的數值，中間以空白隔開(範圍:0~7)  
第二行：輸入字串，中間以空白隔開，說明如下：  
1. X1 的處理方式：N 表示 NOT，B 表示 BUFFER（直接輸出）  
  
2. X2 的處理方式：同上  
  
3. X3 的處理方式：同上  
  
4. 第一組邏輯閘（對處理後的 X1 與 X2 做運算，產生中間變數 Y）  
  
5. 第二組邏輯閘（對 Y 與處理後的 X3 做運算，產生最終輸出）  
  
範例說明:  
Sample Input:  
0 1 2 (X1, X2, X3)  
N B B O A (X1 invert, X2, X3, X1 invert 與X2做OR運算得出Y, Y與X3做AND運算)  
  
X1 = 0 → NOT → 7  
  
X2 = 1 → BUFFER → 1  
  
Y = 7 OR 1 = 7  
  
X3 = 2 → BUFFER → 2  
  
Output = 7 AND 2 = 10 (十進位 2)  
  
【輸出說明】  
輸出計算的Output binary值  
  
Sample Output:  
010  
  
【測試資料一】  
輸入：  
0 1 2  
N B B O A  
  
輸出：  
010  
  
【測試資料二】  
輸入：  
7 4 1  
B N B NO NA  
輸出：  
111  
  
【測試資料三】  
輸入：  
4 3 1  
N N N A NO  
  
輸出：  
001  
  
【測試資料四】  
輸入：  
2 7 1  
B N N NO A  
  
輸出：  
100  
