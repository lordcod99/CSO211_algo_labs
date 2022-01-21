#include <bits/stdc++.h>

using namespace std;
#define ll long long

void merge(int a[],int s,int m,int e)
{
    int l=m-s+1,//size of left subarray
    r=e-m;//size of right subarray
    int left[l],right[r];
    for(int i=0;i<l;++i)
    	left[i]=a[s+i];
    for(int i=0;i<r;++i)
    	right[i]=a[m+1+i];
    int pos=s,//for indexing sorted array
    li=0,ri=0;// for indexing of left and right array
    while(li<l && ri<r)
    {
    	if(left[li]<=right[ri])
    		{a[pos]=left[li];++li;}   //merging left and right 
    	else 
    		{a[pos]=right[ri];++ri;}
    	++pos;
    }
    //if any left array is remained 
    while(li<l)
    {
    	a[pos]=left[li];
    	++li;++pos;
    }

    //if any light array is remained 
    while(ri<r)
    {
    	a[pos]=right[ri];
    	++ri;++pos;
    }

}

void itr_msort(int a[],int e)
{
   int size=1, //to monitor the size of the sorted arrary
   start=0;  // for left index of sub array to  be merged 
   int mid, //for middle element or right end of left subarray
   end;     // rigth end of right sub array
   for(size=1;size<e;size*=2)
   {
   	  for(start=0;start<e-1;start+=2*size)
   	  {
          // mid=((start+size -1)<e-1?(start+size -1):e-1); 
          mid=min((start+size -1),e-1); //middle element or right end of left subarray
          // end = ((start+2*size -1)<e-1?(start+size -1):e-1);  //rigth end of right sub array
          end=min((start+2*size -1),e-1);
          merge(a,start,mid,end);
   	  }
   	 
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
   itr_msort(a,n);

   for(int i=0;i<n;++i)
      cout<<a[i]<<" ";

   cout<<"\n";
    
    return 0;
 } 
 /*
 time complexity:
 average = best = worst = O(n log(n))

 space complexty :  0(n)

 */