#include <bits/stdc++.h>

using namespace std;
#define ll long long
class pqueue{
	vector<pair<char,int>> q;
public:
	void insert(char,int);
	void delt();
	void peek();
    
};

void pqueue::insert(char e,int p)
{
    q.push_back(make_pair(e,p));
    int child=q.size()-1;
    int parent=(child-1)/2;
    while(child>0 && (q[child].second>q[parent].second))
    {
    	swap(q[child],q[parent]);
    	child=parent;
    	parent=(child-1)/2;
    	
    }
    
}

void pqueue::delt(){
	pair<char,int> max=q[0];
	int n=q.size();
	swap(q[0],q[n-1]);
	q.pop_back();
	--n;
	int p=0,childl=2*p+1,childr=2*p+2;
	while(n>childl)
	{
		childl=2*p+1;
		childr=2*p+2;
		int i;
		if(childr>=n)
           i=childl;
       else
       {
       	 if(q[childl].second>q[childr].second)
       	 	i=childl;
       	 else 
       	 	i=childr;
       }
       if(q[p].second<q[i].second)
       	swap(q[p],q[i]);
       else 
       	break;

       p=i;

	}
	cout<<max.first<<" with priority : "<<max.second<<"\n\n";

}

void pqueue::peek(){
	cout<<"root element : "<<q[0].first<<" with priority: "<<q[0].second<<"\n\n";
}


int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pqueue priority_queue;
    char input;
    cout<<"to insert : i \nto delete(remove max element) : d \nto peek :p\nto exit: e\n\n";
    cin>>input;
    while(input!= 'e')
    {
       if(input == 'i')
       {
       	   char e;int p;
       	   cin>>e;cin>>p;
           priority_queue.insert(e,p);
       }
       else if(input == 'd')
       {
       	   
       	priority_queue.delt();

       }
       else if(input=='p')
       {
       	   priority_queue.peek();
       }
       else 
       {
       	 cout<<"give right input: ";
       }

       cin>>input;
      
    }

    
    return 0;
 } 



 // time complexity of insert: O(logn)
 // delet : O(logn)
 // peek : O(1) constant time