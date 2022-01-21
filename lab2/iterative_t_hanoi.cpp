#include <bits/stdc++.h>

using namespace std;
#define ll long long

void re_arrange(stack<int> &s, stack<int> &d, char A, char C)
{ 
  int disk;
  if(s.empty())
  { 
    disk=d.top();
    s.push(disk);
    d.pop();
    cout<<"disk "<<disk<<" moved from "<<C<<" to "<<A<<"\n";
  }
  else if(d.empty())
  {
    disk=s.top();
    d.push(disk);
    s.pop();
    cout<<"disk "<<disk<<" moved from "<<A<<" to "<<C<<"\n";
  } 
  else if(s.top()<d.top())
  {
    disk=s.top();
    s.pop();d.push(disk);
    cout<<"disk "<<disk<<" moved from "<<A<<" to "<<C<<"\n";
  }
  else 
  {
    disk=d.top();
    d.pop();s.push(disk);
    cout<<"disk "<<disk<<" moved from "<<C<<" to "<<A<<"\n";
  }

  return;
}
int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,steps; 
    cin>>n;
    steps = pow(2,n)-1;
    stack<int> source,auxilary,destin;

    for(int i=n;i>0;--i)
      source.push(i);

    char A='A',B='B',C='C'; //A is source pole;
    if(n%2==0)
      swap(B,C);
   for(int i=1;i<=steps;++i)
   {
     if(i%3==1)
        re_arrange(source,destin,A,C);
      else if(i%3==2)
        re_arrange(source,auxilary,A,B);
      else 
        re_arrange(auxilary,destin,B,C);

   }


    
    return 0;
 } 
 // number of steps = 2^n -1 
//time complexity = O(2^n)  exponential order 
//space complexity = O(n) as only 3 stacks of each of fixed size n is maintained 
// tower hanoi can be expanded to 3 parts or movements 1st= movement from/between source and dest
// 2nd movement between source and auxilary 
//3rd is between auxilary and destination