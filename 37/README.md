037 Stack & Queue  
本題必須使用Link List實作，否則不予計分。  
請使用 Linked List 分別實作 Stack（堆疊）與 Queue（佇列），並模擬以下操作。  
Stack 為後進先出（LIFO, Last In First Out）  
Queue 為先進先出（FIFO, First In First Out）  
結構定義:  
typedef struct node_s {  
int data;  
struct node_s * next;  
}node_t;  
typedef node_t * nodep_t;  
5種Stack操作：  
push：將資料放入堆疊的頂點（串列形式），不進行輸出。  
pop：將堆疊頂端資料輸出，並刪除頂點節點，假如堆疊是空的則輸出"Stack is empty"。  
top：將堆疊頂端資料輸出，假如堆疊是空的則輸出"Stack is empty"。  
empty：將堆疊中所有節點刪除，假如堆疊是空的則輸出"Stack is empty"，非空則不進行輸出。  
print：將堆疊中所有節點資料從頂點到底部依序輸出data(逐個輸出每輸出一個節點後換行)，假如堆疊是空的則輸出"Stack is empty"。  
  
5種Queue操作：  
push：將資料放入佇列的尾端（串列形式），不進行輸出。  
pop：將佇列前端資料輸出，並刪除前端節點，假如佇列是空的則輸出"Queue is empty"。  
front：將佇列前端資料輸出，假如佇列是空的則輸出"Queue is empty"。  
empty：將佇列中所有節點刪除，假如佇列是空的則輸出"Queue is empty"，非空則不進行輸出。  
print：將佇列中所有節點資料從前端到尾端依序每行輸出data(逐個輸出每輸出一個節點後換行)，假如佇列是空的則輸出"Queue is empty"。  
  
【輸入說明】  
第1行：一個整數N(1<=N<=20)，代表有N個操作  
第2~N+1行：輸入字串，中間以空白隔開，說明如下：  
1.stack/queue ：代表對stack 或是queue 做操作  
2.對指定stack 或 queue的操作  
  
範例說明:  
Sample Input:  
10 (N為10，代表有10個操作)  
stack push 10(將data 10 push 進stack)  
stack push 31(將data 31push 進stack)  
queue push 15(將data 15 push 進queue)  
queue push 23(將data 23 push 進queue)  
queue pop(將queue 前端data輸出，並刪除前端節點)  
stack pop(將stack 頂端data輸出，並刪除頂端節點)  
queue front(將queue 前端data輸出)  
stack empty(將stack 所有節點刪除)  
stack print(將所有stack 的節點輸出，每輸出一個節點後換行)  
queue print(將所有queue 的節點輸出，每輸出一個節點後換行)  
  
【輸出說明】  
按照操作說明輸出，一個操作一行輸出  
  
Sample Output:  
15(按照操作3、4，目前queue的前端data為15)  
31(按照操作1、2，目前stack的前端data為31)  
23(按照操作3、4、5，目前queue的前端data為23)  
Stack is empty(按照操作8，目前stack為空)  
23(按照操作3、4、5、7，目前queue的前端data為23)  
  
【測試資料一】  
輸入：  
stack pop  
stack push 68  
stack push 4  
stack print  
stack empty  
stack push 99  
stack top  
stack print  
  
輸出：  
Stack is empty  
4  
68  
99  
99  
  
【測試資料二】  
輸入：  
16  
queue push 58  
queue push 81  
queue front  
queue push 49  
queue pop  
queue push 5  
queue empty  
queue push 20  
queue pop  
queue empty  
queue push 77  
queue push 99  
queue print  
queue push 13  
queue push 14  
queue print  
  
輸出：  
58  
58  
20  
Queue is empty  
77  
99  
77  
99  
13  
14  
  
【測試資料三】  
輸入：  
10  
stack push 10  
stack push 31  
queue push 15  
queue push 23  
queue pop  
stack pop  
queue front  
stack empty  
stack print  
queue print  
  
輸出：  
15  
31  
23  
Stack is empty  
23  
  
【測試資料四】  
輸入：  
17  
queue push 71  
queue push 89  
queue pop  
stack push 33  
stack pop  
stack push 24  
stack push 16  
stack print  
queue push 41  
queue push 23  
queue print  
queue empty  
stack pop  
queue print  
stack push 60  
stack push 68  
stack print  
  
輸出：  
71  
33  
16  
24  
89  
41  
23  
16  
Queue is empty  
68  
60  
24  
