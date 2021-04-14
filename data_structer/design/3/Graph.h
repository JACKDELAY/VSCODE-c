#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 20;
typedef char datatype;
//边表结点
struct PIcNode
{
	int adjvex;//结点下标
	int weight;//权重
	PIcNode* next;//下一个表结点
};
//头结点
struct HeadNode
{
	datatype data;//头结点数据
	PIcNode* firstedge;//与该头结点相邻的第一条边
};
//邻接表图
typedef struct Graph
{
	int numVertexes;//顶点数
	int numEdges;//边数
	HeadNode* vnode;//顶点表
}*GraphAdjList;//图指针
struct Path//存储起点到所有临边的权值
{
	int start;
	int end;
	int weight;
};
Path* PathValue;//全局数组保存输入的值
//创建邻接表
void createGraph(GraphAdjList& g)
{
	g = new Graph;
	cout << "输入顶点数与边数：\n";
	cin >> g->numVertexes >> g->numEdges;
	PathValue = new Path[g->numEdges];
	g->vnode = new HeadNode[g->numVertexes];
	cout << "输入顶点数据：\n";
	for (int i = 0; i < g->numVertexes; i++)
	{
		cin >> g->vnode[i].data;
		g->vnode[i].firstedge = nullptr;
	}
	cout << "请输入每条边之间的顶点编号(顶点编号从0开始),以及该边的权重：\n";
	int start, end, weight;
	for (int i = 0; i < g->numEdges; i++)
	{
		cin >> start >> end >> weight;
		PathValue[i].start = start;
		PathValue[i].end = end;
		PathValue[i].weight = weight;
		PIcNode* p = new PIcNode;//头插法
		p->adjvex = end;
		p->next = g->vnode[start].firstedge;
		p->weight = weight;
		g->vnode[start].firstedge = p;
		//无向图对称
		PIcNode* q = new PIcNode;
		q->adjvex = start;
		q->next = g->vnode[end].firstedge;
		q->weight = weight;
		g->vnode[end].firstedge = q;
	}
}
void DFS(GraphAdjList g, int* visited, int adjvex)
{
	if (!g)
		return;
	visited[adjvex] = 1;
	cout << g->vnode[adjvex].data<<" ";
	PIcNode* p = g->vnode[adjvex].firstedge;//获取当前顶点指针
	while (p)
	{
		if (!visited[p->adjvex])//未访问则递归
			DFS(g, visited, p->adjvex);
		p = p->next;//否则到下一条相邻路径
	}
}
void DFS(GraphAdjList g)
{
	int* visited = new int[g->numVertexes];
	for (int i = 0; i < g->numVertexes; i++)//初始化
		visited[i] = 0;
	for (int i = 0; i < g->numVertexes; i++)//连通图与非连通图都能全部访问到
		if (!visited[i])
			DFS(g, visited, i);
}
void BFS(GraphAdjList g, int* visited, int adjvex)
{
	if (!g)
		return;
	int queue[MAX], front = -1, rear = -1;//构造一个循环队列
	cout << g->vnode[adjvex].data<<" ";
	visited[adjvex] = 1;
	rear = (++rear) % MAX;//出队入队都先自加1取模数组最大值，充分利用空间
	queue[rear] = adjvex;
	while (front != rear)//队列不为空
	{
		front = (++front) % MAX;//出队保存
		int temp = queue[front];
		PIcNode* q = g->vnode[temp].firstedge;//获取当前顶点指针
		while (q)//非空时循环
		{
			if (!visited[q->adjvex])//如果未访问
			{
				visited[q->adjvex] = 1;//标记输出再入队
				cout << g->vnode[q->adjvex].data<<" ";
				rear = (++rear) % MAX;
				queue[rear] = q->adjvex;
			}
			q = q->next;//否则到下一条相邻路径
		}
	}
}
void BFS(GraphAdjList g)
{
	int* visited = new int[g->numVertexes];
	for (int i = 0; i < g->numVertexes; i++)//初始化
		visited[i] = 0;
	for (int i = 0; i < g->numVertexes; i++)//连通图与非连通图都能全部访问到
		if (!visited[i])
			BFS(g, visited, i);
}
