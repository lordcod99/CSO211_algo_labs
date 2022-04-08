#include <bits/stdc++.h>

using namespace std;
#define ll long long

class lcs{
	vector<vector<int>> dp;
public:
	lcs(int m,int n){
		dp.assign(m+1,vector<int>(n+1,-1));

	}

	void find(string s1,string s2,int m, int n){

	for (int i=0; i<=m; ++i)
 	 {
    	for (int j=0; j<=n;++j)
   	 	{
      		if (i == 0 || j == 0)
        	dp[i][j] = 0;
      		else if (s1[i-1] == s2[j-1])
        	dp[i][j] = dp[i-1][j-1] + 1;
     		else
        	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    	}
 	 }

     
 	 int p=dp[m][n];
     vector<char> s(p+1);
     s[p]='\0';
     int i=m,j=n;
     while(j>0 && i>0)
     {
     	if(s1[i-1]==s2[j-1])
     	{
     		s[p-1]=s1[i-1];
     		--i;--j;
     		--p;
     	}
     	else if(dp[i-1][j] > dp[i][j-1])
     		--i;
     	else 
     		--j;
     }
    int size=s.size()-1;
    for(int k=0;k<size;++k)
    	cout<<s[k];
    cout<<"\nis the longest sub string of lenght :"<<size;

	}

};
int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   string s1,s2;
   cin>>s1>>s2;
   int m=s1.size(),n=s2.size();
   lcs s(m,n);
   s.find(s1,s2,m,n);



    
    return 0;
 } 

// first we will check last characters are same or not 
// if so add one to ans and repeat same foe l1- 1 and l2-1
// if last characters are not same then we find ans max of (l1-1, l2) and (l1,l2-1)
//we will be going recursively untill we reach base case that either of string leghts 
// becomes 0
// time complexity = O(mn)
// auxilary space = O(mn)
// 
