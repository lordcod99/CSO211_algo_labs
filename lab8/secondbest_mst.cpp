#include <bits/stdc++.h>

using namespace std;
#define ll long long
class dsu{
   int* parent;
   int* rank;
public:
   dsu(int v){
      parent = new int[v];
      rank = new int[v];
      

   }
   void intialise(int v){
   	 for(int i=0;i<v;++i)
      {
         parent[i]=-1;
         rank[i]=1;
      }
   }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }

     void update_set(int s1, int s2)
    {
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }




   
};
class graph{
   vector<vector<int>> e;
   vector<int> mste;
   int v;
public:
   graph(int v) {this->v=v;}

   void addedge(int p,int c,int w)
   {
      e.push_back({ w, p, c });
   }

   void mst(){
      int weight =0;
      int n=e.size();
      sort(e.begin(), e.end());
      dsu s(v);
      s.intialise(v);
     int s1,s2;
     for(int i=0;i<n && mste.size()<v-1;++i)
     {
         s1=s.find(e[i][1]);
         s2=s.find(e[i][2]);
         if(s1!=s2)
         {  
            cout<<e[i][1]<<" === "<<e[i][2]<<" with weight "<<e[i][0]<<"\n";
            s.update_set(s1,s2);
            weight+=e[i][0];
            mste.push_back(i);
         }
     }
   cout<<"\nobtained mst with weight: "<<weight<<"\n\n";

   }

   void second_mst()
   {
   	  int weight=0,smtw=INT_MAX;

   	  int n = e.size();
   	  // int newedge[3],oldedge[3];
   	  dsu s(v);
   	  int s1,s2,edges=0;
   	  for(int i=0;i<mste.size();++i)
   	  { s.intialise(v);
   	  	edges=0;
   	  	for(int j=0;j<n;++j)
   	  	{
   	  		if(j!=mste[i])
   	  		{
               s1=s.find(e[j][1]);
               s2=s.find(e[j][2]);
               if(s1!=s2)
               {
               	  s.update_set(s1,s2);
               	  weight+=e[j][0];
               	  ++edges;
               }
   	  		}
   	  	}

   	  	if(edges!=v-1)
   	  		 weight=0;
   	  	else if(edges == v-1 && smtw>weight)
   	  		smtw=weight;

   	  	weight=0;
   	  }

      cout<<"second best mst with weight: "<<smtw;
     return;
   }
   

};
int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    graph g(n);
    int p,c,w;
    while(cin>>p && cin>>c && cin>>w)
    {
      
      g.addedge(p,c,w);
    }
    g.mst();
    g.second_mst();


    
    return 0;
 } 


// we have to find minimum spannimg tree form given connected graph 
// v=nof nodes E=V(v-1)~v^2 no of edges 
//sorting takes O(Elogv)
//dsu takes at most O(logv)
//and for second best from mst we will exclude each edge in 
//mst and find next best fit by searching through all edges (E)
//it takes = O(EV) 
// tiem complexit = O(EV)
// space complexity = O(|E| + |v|) 
// O(|v|) form dsu and E form all edges 
// 
// 
// 
// 
// 
