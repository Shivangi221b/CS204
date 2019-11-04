#include <bits/stdc++.h> 
using namespace std; 

struct edge{
	long long int v1, v2;
	long long int weight;
};

struct graph{
	long long int v, e;
	struct edge* edge;
};

struct subset{
	int parent, rank;
};

struct graph* createGraph(long long int v, long long int e){
	struct graph* graph= (struct graph*) malloc(sizeof(struct graph));
	graph->v= v;
	graph->e= e;
	graph->edge= (struct edge*) malloc(graph->e * sizeof(struct edge));

	return graph;
}

long long int find(struct subset subsets[], long long int n){
	if(subsets[n].parent!=n)
		subsets[n].parent= find(subsets, subsets[n].parent);

	return subsets[n].parent;
}

void unionSet(struct subset subsets[], int x, int y){
	long long int xrep= find(subsets, x);
	long long int yrep= find(subsets, y);

	if(subsets[xrep].rank>subsets[yrep].rank)
		subsets[yrep].parent=xrep;
	else if(subsets[xrep].rank<subsets[yrep].rank)
		subsets[xrep].parent=yrep;

	else{
		subsets[yrep].parent=xrep;
		subsets[xrep].rank++;
	}

}

int myComp(const void* a, const void* b) 
{ 
	struct edge* a1 = (struct edge*)a; 
	struct edge* b1 = (struct edge*)b; 
	return a1->weight < b1->weight; 
} 

void KruskalMST(struct graph* graph) 
{ 
	long long int w=1;
	long long int V=graph->v; 
	long long int i = 0; 

	qsort(graph->edge, graph->e, sizeof(graph->edge[0]), myComp); 

	subset *subsets = new subset[( V * sizeof(subset) )]; 

	for (long long int v = 0; v < V; ++v) 
	{ 
		subsets[v].parent = v; 
		subsets[v].rank = 0; 
	} 

	while (i<graph->e) 
	{ 
		struct edge next_edge = graph->edge[i++]; 

		long long int x = find(subsets, next_edge.v1); 
		long long int y = find(subsets, next_edge.v2); 
 
		if (x != y) 
		{  
			unionSet(subsets, x, y); 
			w = w * (next_edge.weight);
		} 
	} 

	double res=w%(7+1000000000);
	cout<<"Maximum cost: "<< res <<endl; 
} 

int main() 
{ 
	
	long long int V, E;
	cin>>V>>E;
	struct graph* graph = createGraph(V, E); 

	for(long long int i=0; i<E; i++){
		long long int x, y;
		double k;
		cin>>x;
		cin>>y;
		cin>>k;
		graph->edge[i].v1 = x; 
		graph->edge[i].v2 = y; 
		graph->edge[i].weight = k;
	}

	KruskalMST(graph); 

	return 0; 
} 
