#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;//函数返回状态类型
typedef bool Boolen;//标志数组元素类型
typedef int QElemType;//队列元素类型

#define MAX_VERTEX_NUM 20
#define MAXQSIZE 21

typedef struct{
	QElemType *base;
	int front;
	int rear;
}Queue;

typedef struct ArcNode{
	int adjvex;                    //该弧所指向的顶点的位置
    int weight;
    struct ArcNode *nextarc;       //指向下一条弧的指针
}ArcNode;

typedef struct VNode{
	char data;                          //顶点信息
	ArcNode *firstarc;                 //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;                //图的当前顶点数和弧数
}Graph;

Status visit(Graph G,int v);
Status FirstAdjVex(Graph G, int v);//提取v的第一个邻接顶点
Status NextAdjVex(Graph G, int v, int w);//提取下一邻接顶点,若w是v的最后一个邻接顶点，则返回-1
void InitQueue(Queue &Q);//队列初始化
Status EnQueue(Queue &Q,QElemType e);//插入元素e为Q的新队尾元素
Status DeQueue(Queue &Q,QElemType &e);//弹出元素e
Status QueueEmpty(Queue Q);//检查队空
void DestroyQueue(Queue &Q);//销毁队列
Status CreateGraph(Graph &G);//创建图G
void DFS(Graph G, int v);//从第v个顶点出发递归地对图G进行深度优先搜索
void DFSTraverse(Graph G, Status( * visit)(Graph G, int v));//对图G作深度优先遍历
void BFSTraverse(Graph G, Status(* visit)(Graph G ,int v));//按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited。
void DestroyGraph(Graph G);//销毁图G