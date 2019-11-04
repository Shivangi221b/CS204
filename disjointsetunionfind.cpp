#include <bits/stdc++.h>
using namespace std;

/*PROGRAM TO FIND WHETHER A GRAPH CONTAINS A CYCLE OR NOT 
USING DISJOINT SET UNION FIND*/

struct edge{
	int v1, v2;
};

struct graph{
	int v, e;
	struct edge* edge;
};

struct subset{
	int parent, rank;
};

struct graph* createGraph(int v, int e){
	struct graph* graph= (struct graph*) malloc(sizeof(struct graph));
	graph->v= v;
	graph->e= e;
	graph->edge= (struct edge*) malloc(graph->e * sizeof(struct edge));

	return graph;
}

int find(struct subset subsets[], int n){
	if(subsets[n].parent!=n)
		subsets[n].parent= find(subsets, subsets[n].parent);

	return subsets[n].parent;
}

void unionSet(struct subset subsets[], int x, int y){
	int xrep= find(subsets, x);
	int yrep= find(subsets, y);

	if(subsets[xrep].rank>subsets[yrep].rank)
		subsets[yrep].parent=xrep;
	else if(subsets[xrep].rank<subsets[yrep].rank)
		subsets[xrep].parent=yrep;

	else{
		subsets[yrep].parent=xrep;
		subsets[xrep].rank++;
	}

}

bool checkCycle(struct graph* graph){
	struct subset* subsets= (struct subset*) malloc(graph->v * sizeof(struct subset));

	for(int v=0; v<graph->v; v++){
		subsets[v].parent=v;
		subsets[v].rank=0;
	}

	for(int e=0; e<graph->e; e++){
		int x= find(subsets, graph->edge[e].v1);
		int y= find(subsets, graph->edge[e].v2);

		if(x==y)
			return true;

		unionSet(subsets, x, y);
	}

	return 0;
}

int main(){
	int v=3, e=3;
	struct graph* graph=createGraph(v, e);
	graph->edge[0].v1 = 0;
    graph->edge[0].v2 = 1;

    graph->edge[1].v1 = 1;
    graph->edge[1].v2 = 2;

    graph->edge[2].v1 = 0;
    graph->edge[2].v2 = 2;

    checkCycle(graph)? cout<<"Contains Cycle" : cout<<"No Cycle";
    return 0;
}
