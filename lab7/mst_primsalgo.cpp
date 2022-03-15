#include <bits/stdc++.h>

using namespace std;
#define ll long long
int findminkey(bool set[],int key[],int v)
{
   int m=INT_MAX,mi=-1;
   for(int i=0;i<v;++i)
   {
      if(set[i]==false && key[i]<m)
        { m=key[i];
          mi=i;
        }
   }
   return mi;
}
void prmst(vector<vector<int>> graph,int v)
{

  int parent[v],key[v];
  bool set[v];
  // memset(key,INT_MAX,sizeof(key));
  // memset(set,false,sizeof(set));
  for (int i = 0; i < v; i++)
        key[i] = INT_MAX, set[i] = false;
  key[0]=0;
  parent[0]=-1;
  int mstv =v-1;
  while(mstv--)
  {
    int minnode=findminkey(set,key,v);
    set[minnode]=true;
    for(int i=0;i<v;++i)
    {
       if(graph[minnode][i] && set[i]==false && graph[minnode][i]<key[i])
       {
         key[i]=graph[minnode][i];
         parent[i]=minnode;
       }
    }
  }
 int weight=0;
  for(int i=1;i<v;++i)
  { cout<<parent[i]<<" === "<<i<<" with weight "<<key[i]<<"\n"; weight+=key[i];}
 cout<<"\nobtained mst with weight: "<<weight<<"\n";


   return ;
}

int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v;
    cin>>v;
    vector<vector<int>> graph(v,vector<int> (v,0));

    int p,c,w;
    for(int i=0;i<v;++i)
      for(int j=0;j<v;++j)
         graph[i][j]=0;
    while(cin>>p && cin>>c && cin>>w)
     { graph[p][c]=w;graph[c][p]=w;}
   

   prmst(graph,v);


    
    return 0;
 } 

// we have to find minimum spannimg tree form given connected graph 
// v=nof nodes E=V(v-1)~v^2 no of edges 
// we iterate to obtain v-1 nodes so v-1 times 
// as we used adjacency matrix for graph we have iterate through v for 
// getting adjacent vertices
// our time complexity = O(v^2)
// sapce complexity = O(v^2)
// 
// 
// 






































// we can use adjacency list for matrix so our space complexity 
// so our space complexity = O(v+E) v=nof vertices E=nof edges(undirected so *2)
// we will use min heap to buid priority queueu so every operation  O(logn)
// our time complexity = O(Elogv)
// 
// 
// 
// 
// 

