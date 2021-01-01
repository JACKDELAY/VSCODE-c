
//
// Created by LittleCat on 2019/11/11.
//
#include"func.h"
#include<string>
ElemType IsKuohao(Elemtype elem);
ElemType IsNum(Elemtype elem);
ElemType CharRank(Elemtype elem) ;
ElemType CharJudge(Elemtype elem1,Elemtype elem2) ;
int main() {
    int T;
    printf("请输入需要转化的字符串数量\n");
    scanf("%d\n", &T);                           //需要进行转化的字符串个数
    while (T--) {
        //创建初始符号栈
        STACK cake = (STACK) malloc(sizeof(stack));
        cake->top = 0;
        while(1) {
            char elem = getchar();
            //判断输入是否结束
            if (elem == '#') {               //从栈底逐个输出 
                while(cake->top) {
                    putchar(cake->array[cake->top]);
                    cake->top--;
                }
                printf("\n");
                break;
            }
            //此项为操作数，直接输出
            if (IsNum(elem))
                putchar(elem);
            //此项为括号
            else if (IsKuohao(elem)) {
                //左括号,入符号栈
                if (elem == '(') {
                    cake->array[++cake->top] = elem;
                }
                //右括号，依次输出直到'('
                else {
                    while (cake->array[cake->top] != '(') {
                        putchar(cake->array[cake->top]);
                        cake->top--;
                    }
                    //'('出栈
                    cake->top--;
                }
            }
            //此项为操作符
            else {
                h:
                //操作栈为空或栈顶为'(',入栈
                if (!cake->top || cake->array[cake->top] == '(') {
                    cake->array[++cake->top] = elem;
                }
                    //比栈顶元素优先级高，入栈
                else if (CharJudge(elem, cake->array[cake->top])) {
                    cake->array[++cake->top] = elem;
                } else {
                    //出栈
                    putchar(cake->array[cake->top--]);
                    goto h;
                }
            }
        }
        getchar();
        free(cake);
    }
}
