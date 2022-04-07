#include <bits/stdc++.h>

using namespace std;
#define ll long long

class lcs{
	vector<vector<int>> dp;
public:
	lcs(int m,int n){
		dp.assign(m+1,vector<int>(n+1,-1));

	}

	int find(string s1,string s2,int m, int n){

	if (m == 0 || n == 0)
        return 0;
    if (s1[m - 1] == s2[n - 1])
        return dp[m][n] = 1 + find(s1, s2, m - 1, n - 1);
 
    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(find(s1, s2, m, n - 1),
                          find(s1, s2, m - 1, n));
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
   cout<<s.find(s1,s2,m,n);



    
    return 0;
 } 