#include"func3.h"
int main()  
{  
       ALGraph G;  
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
              printf("请输入弧的顶点和相应权值(起点,终点, 权值): \n");  
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
       CtriPath(G); 
	   printf("最短开发周期为：%d\n",len);
	   printf("一旦延期影响到的路径有：\n");
	   for(i = 0; i<kk;i++){
	   		printf("(%c, %c)\n",path[i][0],path[i][1]);
	   }
       return 0;
}