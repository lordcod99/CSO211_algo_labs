#include <bits/stdc++.h>

using namespace std;
#define ll long long
void recur_thanoi(int n, char a,char b,char c)
{
   if(n==0)
    return;               //we will move n-1 rods to auxilary rod
                         // so nth rod will be moved to destination
    recur_thanoi(n-1,a,c,b); 
    cout<<"disk "<<n<<" moved from "<<a<<" to "<<c<<"\n"; 
    recur_thanoi(n-1,b,a,c); // now we move n-1 rods from auxilary to destination
   // these will be happening recursively movement starts with 1st rod 
    //to A to B if n is even else A to C

}
int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    recur_thanoi(n,'A','B','C');//A is sourse rod and c is destination rod
                               //B is auxilary rod 
    
    return 0;
 } 
 // number of steps = 2^n -1 
//time complexity = O(2^n)  exponential order 
//space complexity = O(n) as each call maintained in stack (max_depth of stack tree=n)