#include <bits/stdc++.h>

using namespace std;
#define ll long long

 int partition(int a[],int s,int e)
{
   int pivot = a[e]; //pivot 
   int pi=s-1;//index of left most small element 
   for(int i=s;i<e;++i)
   {
      if(a[i]<=pivot)
        {++pi; swap(a[i],a[pi]);}
   }
   ++pi;
   swap(a[pi],a[e]);
   return pi;
} 

void itr_qsort(int a[],int s,int e)
{
   int pos=-1;//monitoring stack index
   int r[e-s+1];//used as a stack to store start and end of sub arrays 
   ++pos;r[pos]=s;
   ++pos;r[pos]=e; 
   // int n=e+1;
   while(pos>=0)
   {
      e=r[pos];--pos;
      s=r[pos];--pos;
      int p=partition(a,s,e);//partition the array and storing pivot final position 
      
      if(p-1>s)  // if pivote is not start of array store left sub array range after partitioned array
      {
         ++pos;r[pos]=s;  
         ++pos;r[pos]=p-1;
      }
     
     if(p+1<e) // if rigth subarray exists after partition  
     {
       ++pos;r[pos]=p+1;
       ++pos;r[pos]=e;
     }
   //   for(int i=0;i<n;++i)
   //    cout<<a[i]<<" ";

   // cout<<"\n";

   }

  
}


int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
      cin>>a[i];
   itr_qsort(a,0,n-1);
   for(int i=0;i<n;++i)
      cout<<a[i]<<" ";

   cout<<"\n";

    return 0;
 } 

 /*
 time complexity:
 average = best =  O(n log(n))
 worst = O(n^2)

 space complexty :  0(n)

 */