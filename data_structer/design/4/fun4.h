
#include <stdio.h>
typedef int Elemtype;
typedef struct  edge{  
    Elemtype first;     //起点
	Elemtype end;        //终点
	int weight;  //权重
}edge;

//交换两个结构体内容
int swap(edge arr[], Elemtype i, Elemtype j) 
{
	Elemtype t1 = arr[i].first;
	Elemtype t2 = arr[i].end;
	Elemtype t3 = arr[i].weight; 
	arr[i].first = arr[j].first;
	arr[i].end = arr[j].end;
	arr[i].weight = arr[j].weight;
	arr[j].first = t1;
	arr[j].end = t2;
	arr[j].weight = t3;
	return 0;
}
//调整堆
void Changedown(edge tree[], Elemtype lenght, Elemtype i)
{
	if (i >= lenght) { return; }
	Elemtype c1 = 2 * i + 1;
	Elemtype c2 = 2 * i + 2;
	Elemtype max = i;
	if (c1<lenght&&tree[c1].weight>tree[max].weight) {
		max = c1;
	}
	if (c2<lenght&&tree[c2].weight>tree[max].weight) {
		max = c2;
	}
	if (max != i) {
		swap(tree, max, i);
		Changedown(tree, lenght, max);
	}
}

void Changeup(edge tree[], Elemtype lenght, Elemtype i)
{
	//如果到最后结束
	if (i >= lenght) { return; }
	Elemtype c1 = 2 * i + 1;
	Elemtype c2 = 2 * i + 2;
	Elemtype min = i;
	//找三个点中最小的放到顶点
	if (c1<lenght&&tree[c1].weight<tree[min].weight) {
		min = c1;
	}
	if (c2<lenght&&tree[c2].weight<tree[min].weight) {
		min = c2;
	}
	if (min != i) {
		swap(tree, min, i);
		Changeup(tree, lenght, min);
	}
}

 //构建堆
void HeapInit(edge tree[], Elemtype lenght,Elemtype ch){
	Elemtype last_node = lenght-1;
	Elemtype father = (last_node-1)/2;
	Elemtype i;
	//只需要遍历有孩子的节点
	for(i = father;i>=0;i--){
		if(ch ==1){
			Changedown(tree,lenght,i);
		}else{
			Changeup(tree,lenght,i);
		}	
	}
}
//堆排序根据排序方式和k
void HeapSort(edge tree[], Elemtype lenght,Elemtype ch,Elemtype sh){
	HeapInit(tree,lenght,ch);
	Elemtype i;
	for(i = lenght-1;i>=0;i--){
		swap(tree,i,0);
		if(ch ==1){
			Changedown(tree,i,0);
		}else{
			Changeup(tree,i,0);
		}
	}
}

