#include <bits/stdc++.h>

using namespace std;

bool isTwoColSingle(vector<int> ge[], int n, int source, int colour[]){
	colour[source]=1;
	queue<int> q;
	q.push(source);

	while(!q.empty()){
		int x=q.front();
		q.pop();

		for(int v=0; v<ge[x].size(); v++){
			if(colour[ge[x][v]] == -1){
				colour[ge[x][v]] = 1 - colour[x]; 
                q.push(ge[x][v]);
			}

			else if (colour[ge[x][v]] == colour[x])
				return false;
		}
	}

	return true;
}

bool isTwoCol(vector<int> ge[], int n){
	int colour[n];
	for(int i=0; i<n; i++)
		colour[i]=-1;

	for(int i=0; i<n; i++)
		if(colour[i]==-1)
			if(isTwoColSingle(ge, n, i, colour)==false)
				return false;

	return true;
}

int main(){
	int n, m, x, y, w;
    cin>>n;
    cin>>m;

    vector<int> ge[2*n];

	int pn=n+1;
	int pnc=0;

	for(int i=0; i<m; i++){

		cin>>x>>y>>w;
		if((w%2)==1){
			ge[y-1].push_back(x-1);
			ge[x-1].push_back(y-1);
		}

		else{
			ge[x-1].push_back(pn);
			ge[pn].push_back(x-1);
			ge[y-1].push_back(pn);
			ge[pn].push_back(y-1);

			pnc++;
			pn++;
		}
	}

    isTwoCol(ge, n+pnc) ? cout << "No" : cout << "Yes";
    return 0;
}
