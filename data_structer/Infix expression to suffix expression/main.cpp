
//
// Created by LittleCat on 2019/11/11.
//
#include"func.h"
ElemType IsKuohao(Elemtype elem);
ElemType IsNum(Elemtype elem);
ElemType CharRank(Elemtype elem) ;
ElemType CharJudge(Elemtype elem1,Elemtype elem2) ;
int main() {
    int T;
    scanf("%d\n", &T);          //需要进行转化的字符串个数 
    while (T--) {
        //创建初始符号栈
        STACK op = (STACK) malloc(sizeof(stack));
        op->top = 0;
        while(1) {
            char elem = getchar();
            //判断输入是否结束
            if (elem == '#') {               //从栈底逐个输出 
                while(op->top) {
                    putchar(op->array[op->top]);
                    op->top--;
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
                    op->array[++op->top] = elem;
                }
                //右括号，依次输出直到'('
                else {
                    while (op->array[op->top] != '(') {
                        putchar(op->array[op->top]);
                        op->top--;
                    }
                    //'('出栈
                    op->top--;
                }
            }
            //此项为操作符
            else {
                h:
                //操作栈为空或栈顶为'(',入栈
                if (!op->top || op->array[op->top] == '(') {
                    op->array[++op->top] = elem;
                }
                    //比栈顶元素优先级高，入栈
                else if (CharJudge(elem, op->array[op->top])) {
                    op->array[++op->top] = elem;
                } else {
                    //出栈
                    putchar(op->array[op->top--]);
                    goto h;
                }
            }
        }
        getchar();
        free(op);
    }
}
