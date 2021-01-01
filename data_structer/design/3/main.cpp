#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include"func.h"
using namespace std;

void main(){
	Graph G;
	CreateGraph(G);
	cout<<"从顶点"<<G.vertices[0].data<<"开始的深度优先搜索遍历为："<<endl; 
	DFSTraverse(G,visit);
	cout<<endl;
	cout<<"从顶点"<<G.vertices[0].data<<"开始的广度优先搜索遍历为："<<endl; 
	BFSTraverse(G,visit);
	cout<<endl;
}