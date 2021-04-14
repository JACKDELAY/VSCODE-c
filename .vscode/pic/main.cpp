#include"func.h"
Elemtype Prim(Elemtype graph[][MAX],Elemtype n)
{
    Elemtype lowprice[MAX]; //lowprice[i]记录以i为终点的边的权值,lowprice[i]=0时表示重点i加入图
    Elemtype lst[MAX];  //记录对应的lowprice的起点，lst[i]=0时表示起点i进入图
    Elemtype i, j;
    Elemtype min,minpoElemtype,sum=0;                 //权值最小值
    for (i = 2; i <= n ;i++)                                //默认起点从1开始
        {
            lowprice[i] = graph[1][i];                      //最短距离初始化为其他节点到1节点的距离
            lst[i] = 1;                                     //起点为1
        }
        lst[1] = 0;
    for (i = 2; i <= n;i++)
        {
            min = UTB;
            minpoElemtype = 0;                                  //最小权值点序号
        for (j = 2; j <= n;j++)                            //找符合要求的最小权值节点minpoElemtype
            {
                if(min>lowprice[j]&&lowprice[j]!=0)        //找到最小值且不在集合中
                    {
                        min = lowprice[j];
                        minpoElemtype = j;
                    }
            }
            printf("%c - %c: %d\n", lst[minpoElemtype] + 'A' - 1, minpoElemtype + 'A' - 1, min);
            sum += min;
            lowprice[minpoElemtype] = 0;
        
        for (j = 2; j <= n;j++)
            {
                if(graph[minpoElemtype][j]<lowprice[j])           //发现更小权值
                {
                    lowprice[j] = graph[minpoElemtype][j];        //更新权值信息
                    lst[j] = minpoElemtype;                       //更新最小权值点信息
                }

            }
        }
    return sum;
}

void Init(Elemtype graph[MAX][MAX], Elemtype vertex, Elemtype edge)        //输入和初始化算法
{
    char cinx, ciny;
    Elemtype weight;
    getchar();                                              //读取上一行回车
    for (Elemtype i = 1; i <= vertex;i++)
        for (Elemtype j = 1; j <= vertex;j++)
             graph[i][j] = UTB;                      //将所有权值赋值为无穷大
    for (Elemtype k = 0; k < edge;k++)
        {
            printf("请输入顶点，终点和权值:(起点和重点要求都是大写字母)");
            scanf("%c %c %d",&cinx,&ciny,&weight); 
            //prElemtypef("%c %c %d", &cinx, &ciny, &weight);
            getchar();        //读入顶点，终点和权值
                  //每次输入完后用于读入回车
            Elemtype chi = cinx - 'A' + 1, chj = ciny - 'A' + 1; //将输入字母转化为数组中的顺序
            graph[chi][chj] = weight;                       //赋值
            graph[chj][chi] = weight; 
        }
} 

Elemtype main()
{
    Elemtype core, edge;                                        //节点数和边数
    Elemtype graph[MAX][MAX];
    printf("请输入节点数和边数\n");
    scanf("%d %d", &core, &edge);
    //prElemtypef("%d %d", core, edge);
    Init(graph,core, edge);
    printf("最短路径为：\n");
    printf("Total:%d\n",Prim(graph, core));
    return 0;
}