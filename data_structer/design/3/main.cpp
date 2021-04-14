#include"Graph.h"
int main()
{
	GraphAdjList g;
	createGraph(g);//无向图
	//print(g);
	cout << "\n\nDFS:";
	DFS(g);
	cout << "\n\nBFS:";
	BFS(g);


	return 0;
}