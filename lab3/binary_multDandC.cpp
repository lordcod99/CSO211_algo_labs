#include <bits/stdc++.h>

using namespace std;
#define ll long long

int equal(string &x, string &y)
{
	int n1=x.size(),n2=y.size();
    if(n1>n2)
    {
       for(int i=0;i<n1-n2;++i)
  	      y='0'+y;
      return n1;
    }
    else if(n1<n2)
        for(int i=0;i<n2-n1;++i)
          	     x='0'+x;
    return n2;
}
int multiply(string x,string y)
{
	int n=equal(x,y);
	if(n==0)
		return 0;
	if(n==1)
	     return ((x[0]-'0')*(y[0]-'0'));
	 int l=n/2,r=n-l;
	 string a=x.substr(0,l),b=x.substr(l,r);
	 string c=y.substr(0,l),d=y.substr(l,r);

	 int ac=multiply(a,c),ad=multiply(a,d),
	       bc=multiply(b,c),bd=multiply(b,d);
	     

	 return (ac*(1<<2*r)+(bc+ad)*(1<<r)+bd);

}

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x,y;
    cin>>x>>y;
   cout<<multiply(x,y);

    return 0;
} 
// time complexity = O(n^2)
// space complexity = O(n) n= larger string length
// we recursively divide x = A*2^n/2 + b (half size if even or two parts)
// y= c*2^n/2 + d  so 4 substrings would be X ==> (A,b) Y ==> (C,D) 
// x*y=AC*2^n+(BC+AD)*2^n/2+BD
// when length of sub string = 1 we return multiplication two single bits reculsivly 
// finally we get ac,bc,ad,bd then return AC*2^n+(BC+AD)*2^n/2+BD
















//karatsuba algo

// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long

// int equal(string &x, string &y)
// {
// 	int n1=x.size(),n2=y.size();
//     if(n1>n2)
//     {
//        for(int i=0;i<n1-n2;++i)
//   	      y='0'+y;
//       return n1;
//     }
//     else if(n1<n2)
//         for(int i=0;i<n2-n1;++i)
//           	     x='0'+x;
//     return n2;
// }
// string addBitStrings( string first, string second )
// {
//     string result;  // To store the sum bits
 
//     // make the lengths same before adding
//     int length = equal(first, second);
//     int carry = 0;  // Initialize carry
 
//     // Add all bits one by one
//     for (int i = length-1 ; i >= 0 ; i--)
//     {
//         int firstBit = first.at(i) - '0';
//         int secondBit = second.at(i) - '0';
 
//         // boolean expression for sum of 3 bits
//         int sum = (firstBit ^ secondBit ^ carry)+'0';
 
//         result = (char)sum + result;
 
//         // boolean expression for 3-bit addition
//         carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
//     }
 
//     // if overflow, then add a leading 1
//     if (carry)  result = '1' + result;
 
//     return result;
// }

// int multiply(string x,string y)
// {
// 	int n=equal(x,y);
// 	if(n==0)
// 		return 0;
// 	if(n==1)
// 	     return ((x[0]-'0')*(y[0]-'0'));
// 	 int l=n/2,r=n-l;
// 	 string a=x.substr(0,l),b=x.substr(l,r);
// 	 string c=y.substr(0,l),d=y.substr(l,r);

// 	 int ac=multiply(a,c),bd=multiply(b,d),
// 	       m=multiply(addBitStrings(a,b),addBitStrings(c,d));
	     

// 	 return (ac*(1<<2*r)+(m-ac-bd)*(1<<r)+bd);

// }

// int main()
// { 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     string x,y;
//     cin>>x>>y;
//    cout<<multiply(x,y);

//     return 0;
// } 
// // time complexity = O(n^1.59)
// // space complexity = O(n) n= larger string length
// // we recursively divide x = A*2^n/2 + b (half size if even or two parts)
// // y= c*2^n/2 + d  so 4 substrings would be X ==> (A,b) Y ==> (C,D) 
// // x*y=AC*2^n+((A+B)(C+D)-AC-BD)*2^n/2+BD  here take m=(A+B)(C+D)-AC-BD
// // when length of sub string = 1 we return multiplication two single bits reculsivly 
// // finally we get ac,m,bd 
// // then return  x*y=AC*2^n+((A+B)(C+D)-AC-BD)*2^n/2+BD  here take m=(A+B)(C+D)-AC-BD