008 判斷何種三角形  
  
輸入一個正整數n，代表n個三角形，接著有n行輸入，每一行都會有3個正整數a、b、c，以空白區隔,判斷每一個三角形為正三角、等腰、鈍角、銳角、直角或是無法構成三角形，並輸出結果(若符合多種三角形則按照輸出格式編號順序輸出)，每個三角形的結果輸出以n個*區隔。  
  
判別方法如下:  
1. 不能成為三角形：任兩邊和不大於第三邊，或任一邊長不大於0。  
2. 正三角形：三個邊相等。  
3. 等腰三角形：任兩邊相等。  
4. 鈍角三角形: 最長邊平方大於兩短邊平方和。  
5. 銳角三角形: 最長邊平方小於兩短邊平方和。  
6. 直角三角形: 最長邊平方等於兩短邊平方和。  
【輸入說明】  
第一航輸入整數(int) n  
第二行輸入三個整數(int) a b c  
  
  
範例輸入說明:  
Sample Input:  
2  
10 10 5  
2 2 2  
  
【輸出說明】  
若符合多種三角形則按照輸出格式編號順序輸出  
輸出格式如下：  
1. 不能成為三角形：輸出Not Triangle。  
2. 正三角形：輸出Equilateral Triangle。  
3. 等腰三角形：輸出Isosceles Triangle  
4. 鈍角三角形:輸出Obtuse Triangle。  
5. 銳角三角形: 輸出Acute Triangle。  
6. 直角三角形:輸出Right Triangle。  
  
範例輸出說明:  
```
Isosceles Triangle  
Obtuse Triangle  
**  
Equilateral Triangle  
Isosceles Triangle  
Acute Triangle
```
  
【測試資料一】  
輸入：  
2  
5 2 2  
2 2 5  
  
輸出：  
```
Not Triangle  
**  
Not Triangle
```
  
【測試資料二】  
輸入：  
1  
6 6 6  
  
輸出：  
```
Equilateral Triangle  
Isosceles Triangle  
Acute Triangle
```
  
【測試資料三】  
輸入：  
3  
8 11 5  
6 8 9  
3 7 12  
  
輸出：  
```
Obtuse Triangle  
***  
Acute Triangle  
***  
Not Triangle
```  
【測試資料四】  
輸入：  
4  
1 1 1  
5 12 13  
12 13 15  
3 4 5  
  
輸出：  
```
Equilateral Triangle  
Isosceles Triangle  
Acute Triangle  
****  
Right Triangle  
****  
Acute Triangle  
****  
Right Triangle  
```
