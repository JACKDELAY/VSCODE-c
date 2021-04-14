#include"fun4.h"
int main()
{
	edge tree[100] ;
	int i,num;
	printf("请输入边数：");
	scanf("%d",&num);
	for(i=0;i<num;i++){
		printf("请分别输入：起点 终点 权重：");
		scanf("%d",&tree[i].first);
		scanf("%d",&tree[i].end);
		scanf("%d",&tree[i].weight);	
	}
	printf("请选择排序方式(1：大根堆(小到大)   2：小根堆(大到小)：");
	int ch,sh;
	scanf("%d",&ch);
	printf("请选择前 k位：");
	scanf("%d",&sh);
	HeapSort(tree,num,ch,sh);

	for (i = 0;i < sh;i++)
	{
		printf("起点%d 到 终点%d (%d)\n", tree[i].first, tree[i].end, tree[i].weight);
	}
	return 0;
}

/*
每一次调整的时间复杂度为logn，一共要调整n次，则总时间复杂度为O（nlogn）。
使用情况分析：当n和k的差距比较大的时候最适合用堆排序，大大节省时间，如果用快速排序或者
归并时间复杂度都高于堆排序，所以堆排序最适合与从很多数中找最大或小的几个值。
*/