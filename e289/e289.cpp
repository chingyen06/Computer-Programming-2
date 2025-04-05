#include <bits/stdc++.h>
using namespace std;

int i;
int m, n, a = 0;
string s[200001];  //數字介於 0 ~ 10^150
unordered_map<string,int>M;  //紀錄每個數字出現幾次

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> m >> n;
    
    for (i=0;i<n;i++)
    	cin >> s[i];
    	
    int t = 0;
    
    for (i=0;i<m;i++) {  //0 ~ m
    	if (M[s[i]] == 0)  //沒用過
			t++;
			
    	M[s[i]]++;
	}
	
	if (t == m)
		a++;
		
	for (i=m;i<n;i++) {
		M[s[i-m]]--;
		
		if (M[s[i-m]] == 0)
			t--;
		
    	if (M[s[i]] == 0)
			t++;
			
    	M[s[i]]++;
    	
    	if (t == m)
    		a++;
	}
    
    cout << a;
}
