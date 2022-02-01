#include <bits/stdc++.h>

using namespace std;
void add(vector<vector<int>>& a, vector<vector<int>>& b,vector<vector<int>>& c, int n)
{
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			c[i][j]=a[i][j]+b[i][j];
}
void subtract(vector<vector<int>>& a, vector<vector<int>>& b,vector<vector<int>>& c, int n)
{
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			c[i][j]=a[i][j]-b[i][j];
}
void multiply_vs(vector<vector<int>>& a, vector<vector<int>>& b,vector<vector<int>>& c, int n)
{
   if(n==1)
	 {c[0][0]=a[0][0] * b[0][0]; return;}

	// cout<<n<<"\n";
   int new_n=n/2;
   vector<vector<int>> a11(new_n,vector<int> (new_n,0)),a12(new_n,vector<int> (new_n,0)),
                       a21(new_n,vector<int> (new_n,0)),a22(new_n,vector<int> (new_n,0)),
                       b11(new_n,vector<int> (new_n,0)),b12(new_n,vector<int> (new_n,0)),
                       b21(new_n,vector<int> (new_n,0)),b22(new_n,vector<int> (new_n,0)),
                       c11(new_n,vector<int> (new_n,0)),c12(new_n,vector<int> (new_n,0)),
                       c21(new_n,vector<int> (new_n,0)),c22(new_n,vector<int> (new_n,0)); 

  for(int i=0;i<new_n;++i)
  	{
  		for(int j=0;j<new_n;++j)
  		{
  			a11[i][j]=a[i][j];
  			a12[i][j]=a[i][j+new_n];
  			a21[i][j]=a[i+new_n][j];
  			a22[i][j]=a[i+new_n][j+new_n];

  			b11[i][j]=b[i][j];
  			b12[i][j]=b[i][j+new_n];
  			b21[i][j]=b[i+new_n][j];
  			b22[i][j]=b[i+new_n][j+new_n];

  		}
  	}

  vector<vector<int>> p(new_n,vector<int> (new_n,0)),q(new_n,vector<int> (new_n,0)),
                      r(new_n,vector<int> (new_n,0)),s(new_n,vector<int> (new_n,0)),
                      t(new_n,vector<int> (new_n,0)),u(new_n,vector<int> (new_n,0)),
                      v(new_n,vector<int> (new_n,0));

  vector<vector<int>> auxilaryA(new_n,vector<int> (new_n,0)),auxilaryB(new_n,vector<int> (new_n,0));
  add(a11,a22,auxilaryA,new_n); //a11+a22
  add(b11,b22,auxilaryB,new_n); //b11+b22
  multiply_vs(auxilaryA,auxilaryB,p,new_n);//p=(a11+a22)(b11+b22)

  add(a21,a22,auxilaryA,new_n); //a21+a22
  multiply_vs(auxilaryA,b11,q,new_n);//q=(a21+a22)b11

  subtract(b12,b22,auxilaryA,new_n); //b12-b22
  multiply_vs(a11,auxilaryA,r,new_n);//r=a11(b12-b22)

  subtract(b21,b11,auxilaryA,new_n); //b21-b11
  multiply_vs(a22,auxilaryA,s,new_n);//s=a22(b21-b11)

  add(a11,a12,auxilaryA,new_n);//a11+a12
  multiply_vs(auxilaryA,b22,t,new_n);//t=(a11+a12)b22

  subtract(a21,a11,auxilaryA,new_n); //a21-a11
  add(b11,b12,auxilaryB,new_n); //b11+b12
  multiply_vs(auxilaryA,auxilaryB,u,new_n);//u=(a21-a11)(b11+b12)

  subtract(a12,a22,auxilaryA,new_n); //a12-a22
  add(b21,b22,auxilaryB,new_n); //b21+b22
  multiply_vs(auxilaryA,auxilaryB,v,new_n);//v=(a12-a22)(b21+b22)


  //coumputig c11,c12,c21,c22
  add(p,s,auxilaryA,new_n);//P+s
  subtract(auxilaryA,t,auxilaryB,new_n);//p+s-t
  add(auxilaryB,v,c11,new_n);//c11=p+s-t+v

  add(r,t,c12,new_n);//c12=r+t

  add(q,s,c21,new_n);//c21=q+s

  add(p,r,auxilaryA,new_n);//p+r
  subtract(auxilaryA,q,auxilaryB,new_n);//p+r-q
  add(auxilaryB,u,c22,new_n);//c22=p+r-q+u

  for(int i=0;i<new_n;++i)
  {
  	for(int j=0;j<new_n;++j)
  	{
  		c[i][j]=c11[i][j];
  		c[i][j+new_n]=c12[i][j];
  		c[i+new_n][j]=c21[i][j];
  		c[i+new_n][j+new_n]=c22[i][j];
  	}
  }


}
int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n;
   cin>>n;
   vector<vector<int>> a(n,vector<int> (n,0)),
                       b(n,vector<int> (n,0)),
                       c(n,vector<int> (n,0)); 
   for(int i=0;i<n;++i)
   	for(int j=0;j<n;++j)
   		cin>>a[i][j];

   for(int i=0;i<n;++i)
   	for(int j=0;j<n;++j)
   		cin>>b[i][j];

   for(int i=0;i<n;++i)
   	for(int j=0;j<n;++j)
   		c[i][j]=0;

   	multiply_vs(a,b,c,n);
   	// subtract(a,b,c,n);

   	for(int i=0;i<n;++i)
   	{
   		for(int j=0;j<n;++j)
   			cout<<c[i][j]<<" ";

   		cout<<"\n";
   	}


    return 0;
 } 

 //time complexity = O(n^log7) ==> O(n^2.807)
 // space complexity = O(N) N=number of elements =n^2 (n=size of nxn matrix)
 // auxilary space complexity = O(N) or O(n^2) N=number of elements =n^2 (n=size of nxn matrix)
 //
