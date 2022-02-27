#include <bits/stdc++.h>

using namespace std;
set<pair<int,int>> ans;
int pos(pair<int,int> p1,pair<int,int> p2,pair<int,int> p)
{
  int fxy=(p.second-p1.second)*(p2.first-p1.first)
              - (p2.second-p1.second)*(p.first-p1.first);
  if(fxy>0)
    return 1;
  if(fxy<0)
    return -1;
  return 0;
                                              
}
int distance(pair<int,int> p1,pair<int,int> p2,pair<int,int> p)
{
  return abs((p.second-p1.second)*(p2.first-p1.first)
              - (p2.second-p1.second)*(p.first-p1.first));
}

void convexhull(vector<pair<int,int>> p,pair<int,int> p1,pair<int,int> p2,int n,int outside)
{
   int max_dis=0,point=-1,cd=0;
   for(int i=0;i<n;++i)
   {
      cd=distance(p1,p2,p[i]);
      if(pos(p1,p2,p[i]) == outside && cd>max_dis)
        {point = i;max_dis=cd;}
   }

   if(point==-1)
   {
     ans.insert(p1);
     ans.insert(p2);
     for(int i=0;i<n;++i)
     {
       if(pos(p1,p2,p[i])==0)
        ans.insert(p[i]);

     }

     return;
   }
   

   convexhull(p,p[point],p1,n,-pos(p[point],p1,p2));
   convexhull(p,p[point],p2,n,-pos(p[point],p2,p1));

}
int main()
 { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,int>> p;
    int x,y,n=0;
    int x_max=0,x_min=0;
    while((cin>>x && cin>>y))
    {
      p.push_back(make_pair(x,y));
      
      if(p[n].first > p[x_max].first)
        x_max=n;
      if(p[n].first < p[x_min].first)
        x_min=n;
      ++n;
    }
  
    if(n<3)
      cout<<"no of points must be greater than or equal to 3\n";
    else 
    {
      convexhull(p,p[x_min],p[x_max],n,1);
      convexhull(p,p[x_min],p[x_max],n,-1);


      for (auto itr : ans) 
        cout<<itr.first<<" "<<itr.second<<"\n";


    }


    return 0;
 } 

// space complexity : average case => tn=2t(n/2)+O(n)
// T(n) = O(nlog n)
// worst case : T(n)=T(n-1)+O(n) 
// T(n)=O(n^2) occurs when all points are on convex hull
// space complexity = o(n) n = number of points



























































// C++ program to implement Quick Hull algorithm
// to find convex hull.
// #include<bits/stdc++.h>
// using namespace std;

// // iPair is integer pairs
// #define iPair pair<int, int>

// // Stores the result (points of convex hull)
// set<iPair> hull;

// // Returns the side of point p with respect to line
// // joining points p1 and p2.
// int findSide(iPair p1, iPair p2, iPair p)
// {
//   int val = (p.second - p1.second) * (p2.first - p1.first) -
//       (p2.second - p1.second) * (p.first - p1.first);

//   // if (val >= 0)
//   //   return 1;
//   if (val < 0)
//     return -1;
//   return 1;
// }

// // returns a value proportional to the distance
// // between the point p and the line joining the
// // points p1 and p2
// int lineDist(iPair p1, iPair p2, iPair p)
// {
//   return abs ((p.second - p1.second) * (p2.first - p1.first) -
//       (p2.second - p1.second) * (p.first - p1.first));
// }

// // End points of line L are p1 and p2. side can have value
// // 1 or -1 specifying each of the parts made by the line L
// void quickHull(iPair a[], int n, iPair p1, iPair p2, int side)
// {
//   int ind = -1;
//   int max_dist = 0;

//   // finding the point with maximum distance
//   // from L and also on the specified side of L.
//   for (int i=0; i<n; i++)
//   {
//     int temp = lineDist(p1, p2, a[i]);
//     if (findSide(p1, p2, a[i]) == side && temp > max_dist)
//     {
//       ind = i;
//       max_dist = temp;
//     }
//   }

//   cout<<"sai\n";

//   // If no point is found, add the end points
//   // of L to the convex hull.
//   if (ind == -1)
//   {
//     hull.insert(p1);
//     hull.insert(p2);
//     return;
//   }

//   // Recur for the two parts divided by a[ind]
//   quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
//   quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
// }

// void printHull(iPair a[], int n)
// {
//   // a[i].second -> y-coordinate of the ith point
//   if (n < 3)
//   {
//     cout << "Convex hull not possible\n";
//     return;
//   }

//   // Finding the point with minimum and
//   // maximum x-coordinate
//   int min_x = 0, max_x = 0;
//   for (int i=1; i<n; i++)
//   {
//     if (a[i].first < a[min_x].first)
//       min_x = i;
//     if (a[i].first > a[max_x].first)
//       max_x = i;
//   }

//   // Recursively find convex hull points on
//   // one side of line joining a[min_x] and
//   // a[max_x]
//   quickHull(a, n, a[min_x], a[max_x], 1);

//   // Recursively find convex hull points on
//   // other side of line joining a[min_x] and
//   // a[max_x]
//   quickHull(a, n, a[min_x], a[max_x], -1);

//   cout << "The points in Convex Hull are:\n";
//   for (auto itr : hull) 
//         cout<<itr.first<<" "<<itr.second<<"\n";
// }

// // Driver code
// int main()
// {
//   iPair a[] = {{7, 2}, {3, 4}, {5, 6}, {7, 8}};
//   int n = sizeof(a)/sizeof(a[0]);
//   printHull(a, n);
//   return 0;
// }
