#include <stdio.h>
#include<malloc.h>
#include<string.h>

//定义栈 
typedef  char Elemtype;    //定义宏类型 Elemtype
typedef int ElemType;        //定义宏类型int 
typedef struct{
	Elemtype array[100];
	int top;                                    //顶指针
	int bottom;                                 //底指针
}stack; 

//创建栈
stack *Init(){
	stack *p=(stack*)malloc(sizeof(stack));//分配新空间 
	if(p==NULL)//分配失败 
	return 0;
	p->bottom=p->top=0;//分配成功 
	return p;
}

//入栈
void StackScanf(stack *p,Elemtype str){
	p->array[p->top]=str;//存入栈中 
	p->top++;//栈顶指针加1 
} 

//出栈 
Elemtype StackPrint(stack *p){
	if(p->top!=p->bottom){//栈非空 
		Elemtype str=p->array[p->top-1];//栈顶内容输出 
		p->top--;//栈顶减1 
		return str;
	}
} 


