#include <bits/stdc++.h>

using namespace std;
#define ll long long
class chain_matrix_mul{
	vector<vector<int>> dp;
public:
	chain_matrix_mul(int n){
		dp.assign(n,vector<int>(n,-1));
	}

	int matrix_mul(vector<int> m, int i, int j) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; k++) {
            dp[i][j] = min(dp[i][j], matrix_mul(m, i, k) + matrix_mul(m, k + 1, j) + 
            	m[i - 1] * m[k] * m[j]);
        }
        return dp[i][j];
    } 

};
int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> m;
    int a;
    while(cin>>a)
    	m.push_back(a);
    int n=m.size();

    chain_matrix_mul s(n);
    int ans = s.matrix_mul(m,1,n-1);
    cout<<ans;   

    
    return 0;
 } 

// we first create 2d matrix for Memorization top down  
// and we devide the problem and find them respectively and 
// repeated states can  be found form memorization matrix 
// cause we store each state value 
// time complexity = O(n^3)
// auxilary space = O(n^2) which is also space complexity 
// 
// 
// 
// 
// 
