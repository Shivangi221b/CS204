#include <bits/stdc++.h>
using namespace std;

bool isBipartiteSingle(vector<vector <int> > graph, int source, int colour[], int v)
{
	colour[source]=1;

	queue <int> q;
	q.push(source);

	while(!q.empty())
	{
		int x=q.front();
		q.pop();

		if(graph[x][x]==1)
			return false;

		for(int i=0; i<v; i++)
		{
			if (graph[x][i] && colour[i]==-1)
			{
				colour[i]=1-colour[x];
				q.push(i);
			}

			else if(graph[x][i] && colour[i]==colour[x])
				return false;
		}
	}

	return true;
}

bool isBipartite(vector<vector <int> > graph, int v)
{
	int colour[v];

	for(int i=0; i<v; i++)
		colour[i]=-1;

	for(int i=0; i<v; i++){
		if(colour[i]==-1){
			if(isBipartiteSingle(graph, i, colour, v)==false)
				return false;
		}
	}

	return true;
}

int main() 
{ 
 
    int n, m, x, y;
    cin>>n;
    cin>>m;
    vector<vector<int> > graph(n, vector<int>(n,0));
    for(int i=0; i<m; i++){
    	cin>>x;
    	cin>>y;
    	graph[x-1][y-1]=1;
    }

    isBipartite(graph, n) ? cout << "Yes" : cout << "No";
    return 0; 
} 
