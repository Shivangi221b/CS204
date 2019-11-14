#include<bits/stdc++.h>
using namespace std;
/*BFS IMPLEMENTATION
you have been given a tree consisting of N nodes. A tree is a fully connected graph consisting of n nodes ans n-1 edges.
The nodes in this tree a indexed from 1 to n. Consider node indexed 1 to be the root node of this tree. The root node lies in 
level one of the tree. you shall be given the tree and a single integer x.you need to find no of nodes lying on level x.
input
no of vetices
n-1 lines containing index of nodes
last line level on which no of nnodes is to be found out.
output 
single integer denoting no of nodes on that level
*/
/*sample input
20
11 1
1 2
13 3
15 4
17 5
11 6
2 7
1 8
15 9
4 10
15 12
5 13
2 14
17 15
15 16
11 17
15 18
9 19
16 20
2
output 3
*/
int BFS(vector<int> v[],int level1, int start,int n)
{
  bool visited[n];
  int level [n];
  queue<int> q;
  q.push(start);
  visited[start]=true;
  level[start]=1;
  int h=0;
  int k;
    
  while(!q.empty())
  {
    k=q.front();
    q.pop();
    for(int i=0;i<v[k].size();i++)
    {
      if(visited[v[k][i]]==false)
      {
        level[v[k][i]]=level[k]+1;
        q.push(v[k][i]);
        visited[v[k][i]]=true;
               
        if(level[v[k][i]]==level1)
          h++;
               
      }
    }
       
  }
    
  return h;
}


int main()
{
    int n;
    cin>>n;
    vector<int> v[n];
    
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
        
    }
    int level;
    cin>>level;
    cout<<BFS(v,level,0,n);
    return 0;
    
}

