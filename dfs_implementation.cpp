#include<bits/stdc++.h>
using namespace std;

/* DFS IMPLEMENTATION
You have been given a graph consisting of N nodes and M edges. The nodes in this graph are enumerated from 1 to N . 
The graph can consist of self-loops as well as multiple edges. This graph consists of a special node called the head node. 
You need to consider this and the entry point of this graph. You need to find and print the number of nodes that are 
unreachable from this head node.
Input Format
The first line consists of a 2 integers N and M denoting the number of nodes and edges in this graph. 
The next M lines consist of 2 integers a and b denoting an undirected edge between node a and b. 
The next line consists of a single integer x denoting the index of the head node.
*Output Format *:
You need to print a single integer denoting the number of nodes that are unreachable from the given head node.
*/
/*sample input output
50 23
7 9
9 45
16 37
15 41
26 47
15 34
32 22
32 17
13 39
6 43
35 21
29 36
34 14
49 31
22 1
49 26
32 28
41 33
31 25
29 38
37 12
13 2
32 18
7
output 47
*/

void DFS(vector<int> v[], int n, bool visited[], int s)
{
    visited[s]=true;
    for(int i=0;i<v[s].size();i++)
    {
        if(visited[v[s][i]]==false)
        {
            DFS(v,n,visited,v[s][i]);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v[n];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    bool visited[n];

    for(int i=0;i<n;i++)
        visited[i]=false;

    int x;
    cin>>x;
    int count;

    DFS(v,n,visited,x-1);

    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        count++;
    }
    
    cout<<count;
    return 0;

}
