027 多重單詞操作  
給定一篇英文文章，針對文章中的英文單詞進行不同的操作。  
1. 單詞取代：將英文文章中所有的單詞P以單詞Q取代。  
2. 單詞前插入：在英文文章中每個單詞P前插入單詞Q。  
3. 單詞後插入：在英文文章中每個單詞P後插入單詞Q。  
4. 單詞刪除：將英文文章中所有的單詞P刪除。  
5. 單詞順序反轉：反轉文章中的單詞順序，但保持每個單詞的字母順序不變。  
單詞相符的定義  
如果某個單詞與指定單詞完全相同，或單詞結尾僅附上一個英文標點符號（. , ! ? ; :）時，也視為相符，需要進行上述操作。  
例如：若指定單詞為 sun，則 sun、sun!、sun,、sun.、sun? 都會被視為與 sun 相符。  
但像 can't、I'm 等含有縮寫符號（' 或 `）的單詞，則不視為與任何其它單詞相符（即：不能將 can't 視為 can 或 cant）。  
多個結尾標點或非英文標點號，則不列為相符範圍，例如 sun... 不視為相符。  
單詞主體須完全相符，字母大小寫須一致  
替換及插入時，若原單詞末有標點，操作後須保留並附於新單詞末尾。  
  
【輸入說明】  
第一行為輸入一篇英文文章，文章中的英文單詞間以空白分隔。  
第二行為輸入一個英單詞P。  
第三行為輸入一個英單詞Q。  
  
範例輸入：  
Bright sun! shines, Sun. and sun  
sun  
star  
【輸出說明】  
第一行輸出單詞取代後的結果。  
第二行輸出單詞前插入後的結果。  
第三行輸出單詞後插入後的結果。  
第四行輸出單詞刪除後的結果。  
第五行輸出單詞順序反轉後的結果。  
  
範例輸出：  
Bright star! shines, Sun. and star  
Bright star sun! shines, Sun. and star sun  
Bright sun! star shines, Sun. and sun star  
Bright shines, Sun. and  
sun and Sun. shines, sun! Bright  
  
【測試資料一】  
輸入：  
Whether the weather be cold or whether the weather be hot  
the  
a  
輸出：  
Whether a weather be cold or whether a weather be hot  
Whether a the weather be cold or whether a the weather be hot  
Whether the a weather be cold or whether the a weather be hot  
Whether weather be cold or whether weather be hot  
hot be weather the whether or cold be weather the Whether  
  
【測試資料二】  
輸入：  
The bmi doctors want to develop a bmi calculator to help people calculate bmi  
bmi  
BMI  
輸出：  
The BMI doctors want to develop a BMI calculator to help people calculate BMI  
The BMI bmi doctors want to develop a BMI bmi calculator to help people calculate BMI bmi  
The bmi BMI doctors want to develop a bmi BMI calculator to help people calculate bmi BMI  
The doctors want to develop a calculator to help people calculate  
bmi calculate people help to calculator bmi a develop to want doctors bmi The  
  
【測試資料三】  
輸入：  
Sun sun! sunny, sun. not sun's sun?  
sun  
moon  
輸出：  
Sun moon! sunny, moon. not sun's moon?  
Sun moon sun! sunny, moon sun. not sun's moon sun?  
Sun sun! moon sunny, sun. moon not sun's sun? moon  
Sun sunny, not sun's  
sun? sun's not sun. sunny, sun! Sun  
  
【測試資料四】  
輸入：  
Let's go, go! going. they can't go? gone gone.  
go  
move  
輸出：  
Let's move, move! going. they can't move? gone gone.  
Let's move go, move go! going. they can't move go? gone gone.  
Let's go, move go! move going. they can't go? move gone gone.  
Let's going. they can't gone gone.  
gone. gone go? can't they going. go! go, Let's  
