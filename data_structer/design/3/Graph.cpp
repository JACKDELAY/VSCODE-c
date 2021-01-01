#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"func.h"
using namespace std;

Boolen visited[MAX_VERTEX_NUM];//访问标志数组
Status (* VisitFunc)(Graph G, int v);//函数变量

Status visit(Graph G,int v){
	cout<<G.vertices[v].data<<' ';
	return 0;
}

Status FirstAdjVex(Graph G, int v){
	//提取v的第一个邻接顶点
	if(v>=0&&v<G.vexnum)
		if(G.vertices[v].firstarc)
			return (G.vertices[v].firstarc)->adjvex;
	return -1;
}

Status NextAdjVex(Graph G, int v, int w){
	//提取下一邻接顶点,若w是v的最后一个邻接顶点，则返回-1
	ArcNode *p;
	if(v>=0&&v<G.vexnum&&w>=0&&w<G.vexnum){
		p=G.vertices[v].firstarc;
		while(p->nextarc)
			if(p->adjvex==w) return p->nextarc->adjvex;
			else
				p=p->nextarc;
	}
	return -1;
}

void InitQueue(Queue &Q){
	//队列初始化
	Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base) exit(OVERFLOW);//存储分配失败
	Q.front=Q.rear=0;
}

Status EnQueue(Queue &Q,QElemType e){
	//插入元素e为Q的新队尾元素
	if((Q.rear+1)%MAXQSIZE==Q.front)
		return ERROR;//队列元素已满
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return OK;
}

Status DeQueue(Queue &Q,QElemType &e){
	if(Q.front==Q.rear) return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return OK;
}

Status QueueEmpty(Queue Q){
	return Q.front==Q.rear;
}

void DestroyQueue(Queue &Q){
	//销毁队列
	free(Q.base);
	Q.front=0;
	Q.rear=0;
}

Status CreateGraph(Graph &G){ 
	int i,j,k,w;
	ArcNode *p;
	cout<<"请输入图的顶点数及弧数:"<<endl;
	cin>>G.vexnum>>G.arcnum;
	cout<<"请输入这些顶点的值:"<<endl;
	for(i=0; i<G.vexnum; i++)
	{
		cin>>G.vertices[i].data;	
		G.vertices[i].firstarc=NULL;
	}
	for(k=0;k<G.arcnum;k++)
    {
        cout<<"请输入第"<<k+1<<"条边的两个顶点及其权值:"<<endl;
		cin>>i>>j>>w;
        p=(ArcNode *)malloc(sizeof(ArcNode));//生成j的弧结点
        p->adjvex=j;
		p->weight=w;
		p->nextarc=G.vertices[i].firstarc;//将结点j链接到i的单链表中
        G.vertices[i].firstarc=p;
        p=(ArcNode *)malloc(sizeof(ArcNode));//生成i的弧结点
        p->adjvex=i;
		p->weight=w;
        p->nextarc=G.vertices[j].firstarc;//将结点i链接到j的单链表中
        G.vertices[j].firstarc=p;
    }
	return OK;
}

void DFS(Graph G, int v){
	//从第v个顶点出发递归地对图G进行深度优先搜索
	visited[v] = TRUE;  VisitFunc(G,v);//访问第 v 个顶点
    for(int w=FirstAdjVex(G,v); w>=0;w=NextAdjVex(G,v,w))
		if (!visited[w]) DFS(G, w);//对v的尚未访问过的邻接顶点w递归调用DFS
}

void DFSTraverse(Graph G, Status( * visit)(Graph G, int v)){
	// 对图G作深度优先遍历
       VisitFunc=visit;//使用全局变量VisitFunc，使DFS不必设函数指针参数
       for (int v=0; v<G.vexnum; ++v)  visited[v]=FALSE; // 访问标识数组初始化
       for (int v=0; v<G.vexnum; ++v)
       if (!visited[v]) DFS(G, v);        // 对尚未访问的顶点调用DFS
}


void BFSTraverse(Graph G, Status(* visit)(Graph G, int v)){
	//按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited。
	Queue Q;
	int u,v,w;
	for (v=0; v<G.vexnum; ++v) visited[v]=FALSE;
	InitQueue(Q);                         //置空的辅助队列Q
	for (v=0; v<G.vexnum; ++v)
		if(!visited[v]){                  //尚未访问
			visited[v]=TRUE; visit(G,v);
			EnQueue(Q,v);                 //入队列
			while(!QueueEmpty(Q)){
				DeQueue(Q,u);             //队头元素出队并置为u
				for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
					if(!visited[w]){       //w为u的尚未访问的邻接顶点
						visited[w]=TRUE; 
						visit(G,w);
						EnQueue(Q,w);
					}
			}
		}
		DestroyQueue(Q);
}

void DestroyGraph(Graph G){ 
	int i;
	ArcNode *p,*q;	
	for (i=0; i<G.vexnum; ++i){
		p=G.vertices[i].firstarc;
		while(p){
			q=p->nextarc;
			free(p);
			p=q;
		}
		G.vertices[i].data=0;
		G.vertices[i].firstarc=NULL;
	}
	G.vexnum = 0;
	G.arcnum = 0;
}
