038 Double Link List  
  
請使用以下結構，實作Double Link List，並模擬以下操作。  
  
Double Link List結構:  
typedef struct dnode_s {  
int data;  
struct dnode_s * front;  
struct dnode_s * back;  
} node_t;  
typedef node_t * nodep_t;  
  
8種Double Link List操作：  
addFront：將資料放入串列前端，不進行輸出。  
addBack：將資料放入串列尾端，不進行輸出。  
removeFront：將最前端的節點刪除，假如串列是空的則輸出"Double link list is empty"，非空則不進行輸出。  
removeBack : 將最尾端端的節點刪除，假如串列是空的則輸出"Double link list is empty"，非空則不進行輸出。  
empty：將串列中所有節點刪除，假如串列是空的則輸出"Double link list is empty"，非空則不進行輸出。  
insert n : 在第n個節點後插入新的資料，最前端節點為1。假如串列長度小於n則輸出"Invalid command"，其餘情況不進行輸出。  
remove n : 刪除第n個節點，最前端節點為1。假如串列長度小於n則輸出"Invalid command"，其餘情況不進行輸出。  
print：將串列中所有節點資料從前端到尾端依序每行輸出data，假如串列是空的則輸出"Double ink list is empty"  
  
【輸入說明】  
第一行，輸入一整數 N ( 1 <= N <= 20 )，代表有N個操作。  
第二行~第2+N行，輸入操作的種類  
addFront：將資料放入串列前端（最前面），不進行輸出。格式為 addFront data，其中 data 為整數，範圍為 0~100。  
addBack：將資料放入串列尾端（最後面），不進行輸出。格式為 addBack data，其中 data 為整數，範圍為 0~100。  
removeFront：將最前端節點刪除，假如串列為空則輸出 "Double link list is empty"，非空則不進行輸出。  
removeBack：將最後端節點刪除，假如串列為空則輸出 "Double link list is empty"，非空則不進行輸出。  
empty：刪除串列中所有節點，假如串列為空則輸出 "Double link list is empty"，非空則不進行輸出。  
insert：在第 n 個節點後插入新的節點資料，最前端節點為第1個節點。格式為 insert n data，其中 n 為整數 (120)，data 為整數 (0100)。若串列長度小於 n 則輸出 "Invalid command"，其餘情況不進行輸出。  
remove：刪除第 n 個節點，最前端節點為第1個節點。格式為 remove n，其中 n 為整數 (1~20)。若串列長度小於 n 則輸出 "Invalid command"，其餘情況不進行輸出。  
print：將串列中所有節點資料從前端到尾端依序輸出，每個資料各占一行。若串列為空，則輸出 "Double link list is empty"。  
  
範例說明:  
Sample Input:  
13 (N為13，代表有13個操作)  
addFront 13(在串列前端加入13)  
addBack 12(在串列尾端加入12)  
addFront 10(在串列前端加入10)  
insert 2 20(在第2個節點後加入20)  
insert 5 100(在第5個節點後加入100)  
remove 2(移除第2個節點)  
print(由前端到尾端輸出所有節點)  
remove 5(移除第5個節點)  
removeBack(刪除最尾端的節點)  
removeFront(刪除最前端的節點)  
print(由前端到尾端輸出所有節點)  
empty(刪除串列所有節點)  
empty(刪除串列所有節點)  
  
【輸出說明】  
按照操作說明輸出，一個操作一行輸出  
  
Sample Output:  
Invalid command(根據輸入的操作1、2、3、4，串列長度為4，由於5超過串列長度，故指令失效)  
10(根據輸入的操作6，串列長度為3，第一個節點的data為10)  
20(根據輸入的操作6，串列長度為3，第二個節點的data為20)  
12(根據輸入的操作6，串列長度為3，第三個節點的data為12)  
Invalid command(目前串列長度為3，由於5超過串列長度，故指令失效)  
20(根據輸入操作9、10，串列長度為1，第一個節點的data為20)  
Double link list is empty (在操作12時，已將Stack中所有節點刪除，故為空)  
  
【測試資料一】  
輸入：  
13  
addFront 13  
addBack 12  
addFront 10  
insert 2 20  
insert 5 100  
remove 2  
print  
remove 5  
removeBack  
removeFront  
print  
empty  
empty  
  
輸出：  
Invalid command  
10  
20  
12  
Invalid command  
20  
Double link list is empty  
  
【測試資料二】  
輸入：  
15  
addFront 12  
addFront 13  
addBack 15  
addBack 16  
addFront 17  
addFront 16  
removeFront  
removeFront  
removeBack  
removeBack  
print  
addBack 15  
addFront 14  
removeFront  
print  
  
輸出：  
13  
12  
13  
12  
15  
  
【測試資料三】  
輸入：  
11  
addFront 12  
addFront 13  
addFront 14  
insert 1 20  
print  
insert 5 17  
insert 2 19  
print  
remove 2  
remove 5  
print  
  
輸出：  
14  
20  
13  
12  
Invalid command  
14  
20  
19  
13  
12  
Invalid command  
14  
19  
13  
12  
  
【測試資料四】  
輸入：  
20  
addFront 3  
addFront 29  
addBack 58  
addBack 63  
remove 2  
insert 2 13  
print  
removeBack  
removeFront  
addBack 25  
removeFront  
insert 4 36  
insert 2 7  
remove 9  
empty  
removeFront  
addFront 1  
addBack 71  
addBack 84  
print  
  
輸出：  
29  
58  
13  
63  
Invalid command  
Invalid command  
Double link list is empty  
1  
71  
84  
