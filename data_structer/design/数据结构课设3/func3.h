#include <stdio.h>  
#include <stdlib.h>  
#define Maxpoint 20

typedef int Elemtype;

Elemtype visited[Maxpoint];  
Elemtype len = 0;
typedef char CElemType;  
typedef struct ArcNode  
{  
       Elemtype adjvex;                               //该弧指向的顶点位置  
       Elemtype information;                                      //权值信息
       struct ArcNode * nextarc;          //指向下一个表结点  
}ArcNode;                                              //边结点类型  
   
typedef struct VNode  
{  
       CElemType data;  
       Elemtype deepdegree;  
       ArcNode * firstnode;  
}VNode, Adjlist[Maxpoint];  
   
typedef struct  
{  
       Adjlist vertices;                //邻接表  
       Elemtype point, arc;             //顶点数和弧数  
}ALGraph;  
Elemtype kk = 0;
CElemType path [20][2];

//查找符合的数据在数组中的下标  
Elemtype LookBOT(ALGraph G, char u)  
{  
       Elemtype i;  
       for(i = 0; i < G.point; i++)  
       {  
              if(u == G.vertices[i].data)  
                     return i;  
       }  
       if(i == G.point)  
       {  
              printf("Error u!\n");  
              exit(1);  
       }  
       return 0;  
}  
   
 
void InitGraph(ALGraph G)  
{  
       Elemtype i, j, k, w;  
       CElemType v1, v2;  
       ArcNode * p;  
       printf("输入顶点数和弧数: ");  
       scanf("%d %d", &G.point, &G.arc);  
       printf("请输入顶点!\n");  
       for(i = 0; i < G.point; i++)  
       {  
              printf("请输入第 %d 个顶点: \n", i);  
              fflush(stdin);  
              scanf("%c", &G.vertices[i].data);  
              G.vertices[i].firstnode = NULL;  
              G.vertices[i].deepdegree = 0;  
       }  
   
       for(k = 0; k < G.arc; k++)  
       {  
              printf("请输入弧的顶点和相应权值(v1, v2, w): \n");  
              //清空输入缓冲区  
              fflush(stdin);  
              scanf("%c %c %d", &v1, &v2, &w);  
              i = LookBOT(G, v1);  
              j = LookBOT(G, v2);  
              p = (ArcNode *)malloc(sizeof(ArcNode));  
              p->adjvex = j;  
              p->information = w;  
              p->nextarc = G.vertices[i].firstnode;  
              G.vertices[i].firstnode = p;  
              G.vertices[j].deepdegree++;                   //vi->vj, vj入度加1  
       }  
       return;  
}  
   
//求图的关键路径函数  
void CtriPath(ALGraph G)  
{  
       Elemtype i, k, e, l;  
       Elemtype * Vearl, * Vlate;  
       ArcNode * p;  
   
       //求时间最早发生时间  
	   Elemtype typeA[G.point];
	   Elemtype typeB[G.point];
       Vlate = typeB;
   	   Vearl = typeA;
   	   
   	   
       for(i = 0; i < G.point; i++)              //前推  
              Vearl[i] = 0;  
   	
       for(i = 0; i < G.point; i++)  
       {  
              ArcNode * p = G.vertices[i].firstnode;  
              while(p != NULL)  
              {  
                     k = p->adjvex;  
                     if(Vearl[i] + p->information > Vearl[k])  //前节点加权值的和大于该节点
                            Vearl[k] = Vearl[i]+p->information;  
                     p = p->nextarc;  
              }  
       }  
    	for(i = 0; i < G.point; i++) {
			if(Vearl[i]>len)len = Vearl[i];
		}
       
       //求最迟发生时间  
       for(i = 0; i < G.point; i++)  
              Vlate[i] = Vearl[G.point-1];  
       for(i = G.point-2; i >= 0; i--)                 //后推  
       {  
              p = G.vertices[i].firstnode;  
              while(p != NULL)  
              {  
                     k = p->adjvex;  
                     if(Vlate[k] - p->information < Vlate[i])  
                            Vlate[i] = Vlate[k] - p->information;  
                     p = p->nextarc;  
              }  
       }  
       //******************************************  
       for(i = 0; i < G.point; i++)  
       {  
              p = G.vertices[i].firstnode;  
              while(p != NULL)  
              {  
                     k = p->adjvex;  
                     e = Vearl[i];              //最早开始时间为时间vi的最早发生时间  
                     l = Vlate[k] - p->information;             //最迟开始时间  
                     char tag = (e == l) ? '*' : ' '; //关键活动  
                     printf("(%c, %c), early = %2d, late = %2d, %c\n", G.vertices[i].data, G.vertices[k].data, e, l, tag);
					 if(e == l){
					 	 path[kk][0] = G.vertices[i].data;
						 path[kk++][1] = G.vertices[k].data;
					 }
                     p = p->nextarc;  
              }  
       }  
     
}  