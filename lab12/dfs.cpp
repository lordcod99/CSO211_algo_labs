#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,p,c;
    cin>>v;
    vector<vector<int>> adjlist(v);
    vector<int> visited(v,false);

    while(cin>>p && cin>>c)
      adjlist[p].push_back(c);
  stack<int> crnt;
  crnt.push(0);
  while(!crnt.empty())
  {
  	int node = crnt.top();
  	crnt.pop();

  	if(visited[node] == false)
  	{
  		cout<<node<<" ";
  		visited[node]= true;
  	}

  	int l=adjlist[node].size();
  	for(int i=0;i<l;++i)
  	{
  		if(visited[adjlist[node][i]] == false)
  			crnt.push(adjlist[node][i]);
  	}

  }



   
    
    return 0;
 } 


 // take a random node as a root in graph maintain a stack 
 // and arrary to know if each node is visited or not to avoid cycles in graph
 // if not visted print and make it visted 
 //and push all non visited childs of curent node and continue till the stack is empty 
 // time complexity = O(V+E)
// auxilary space = O(V)

