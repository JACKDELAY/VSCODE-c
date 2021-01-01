#include<stdio.h>
#define MAX 100
#define UTB 0x3f3f3f3f        //理论上的无穷大ultimately big
typedef int Elemtype;
Elemtype Prim(Elemtype graph[][MAX], Elemtype n);    //Prim算法
void Init(Elemtype grapg[MAX][MAX], Elemtype vertex, Elemtype edge);    
//输入和初始化函数，此处定义了图结构，顶点和边