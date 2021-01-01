#include <stdio.h>

#include <stdlib.h>

 

#define MAX 200
typedef  char Elemtype;    //定义宏类型 char
typedef int ElemType;        //定义宏类型int 
typedef struct stack {     //定义结构体：符号栈的实现 
    ElemType top;
    Elemtype array[200];
} *STACK, stack;

ElemType IsKuohao(char elem)  //判断输入是否为括号 
{
	if(elem !='('&&elem!=')')   //是（）则返回0，不是则返回1 
		return 0;
	else return 1;
}

ElemType IsNum(char elem)              //判断输入是否为数字 
{
	if(elem=='+'||elem=='-'||elem=='*'||elem=='/')          //易知只要字符不是运算符和括号，即为数字 
		return  0;
	if (IsKuohao(elem))                                  //不是数字返回0，是数字返回1 
		return 0;
	return 1;
} 

ElemType CharRank(char elem)                            //运算符优先级赋值函数 
{
	if(elem=='+'||elem=='-')                            //+-赋值1 
		return 1;
	if(elem=='*'||elem=='/')                           //*/赋值2 
		return 2;
	if(elem=='^')                                        //^赋值3 
		return 3;
} 

ElemType CharJudge(char elem1,char elem2)              //运算符优先级比较算法
{
	if(CharRank(elem1)>CharRank(elem2))                //1>2返回1 
		return 1;
	if(CharRank(elem1)==CharRank(elem2))               //相等进行判断，如果是^就前比后大，否则优先级相等 
	{
	
		if(CharRank(elem1)==3)
			return 1;
		else return 0;
	}
	return 0;
} 






