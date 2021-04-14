#include"func1.h"
int main()
{
	stack *s;//定义栈名 
    ElemType num = 1,i; 
    Elemtype Cinchar;  
	s=Init();
	StackScanf(s,'#');
    printf("请输入中缀表达式：");
    while((Cinchar=getchar())!='\n'){
		if(Cinchar>='A'&&Cinchar<='Z'||Cinchar>='a'&&Cinchar<='z'||Cinchar>='0'&&Cinchar<='9'||Cinchar=='.'){        //包含数字表达式和字母表达式，支持小数
			printf("\n第%d次输出为：%c\n",num++,Cinchar);
        } 
        else
        {
            if(Cinchar=='*'||Cinchar=='/')
            {
                while(s->array[s->top-1]!='#'&&(s->array[s->top-1]=='*'||s->array[s->top-1]=='/')){  //保证栈不会越界
                    printf("\n第%d次输出%c\n",num++,StackPrint(s));
                    printf("出栈操作，出站前栈内情况(由底到顶为)：");
                    for(i=s->bottom;i<s->top;i++){
                    	printf("%c  ",s->array[i]);
                    }
                    printf("\n");
                }
	     	    StackScanf(s,Cinchar);
	     	    printf("进栈操作，进栈后(由底到顶为)：");
	     	    for(i=s->bottom;i<s->top;i++){
                    printf("%c  ",s->array[i]);
                }
	     	    printf("\n");
            }
            else if(Cinchar=='+'||Cinchar=='-')
            {
                while(s->array[s->top-1]!='('&&s->array[s->top-1]!='#'){
                	printf("\n第%d次输出%c\n",num++,StackPrint(s));
                    printf("出栈操作，出站后栈内情况(由底到顶为)：");
                    for(i=s->bottom;i<s->top;i++){
                    	printf("%c  ",s->array[i]);
                    }
                    printf("\n");
                }
	     	    StackScanf(s,Cinchar);
	     	    printf("进栈操作，进栈后(由底到顶为)：");
	     	    for(i=s->bottom;i<s->top;i++){
                    printf("%c  ",s->array[i]);
                }
	     	    printf("\n");
                   
            }
            else if(Cinchar=='('){
             	StackScanf(s,Cinchar);
             	printf("进栈操作，进站后(由底到顶为)：");
	     	    for(i=s->bottom;i<s->top;i++){
                    printf("%c  ",s->array[i]);
                }
	     	    printf("\n");
            }    
            else if(Cinchar==')')
            {
                while(s->array[s->top-1]!='('){
                	printf("\n第%d次输出%c\n",num++,StackPrint(s));
                    printf("出栈操作，出站后栈内情况(由底到顶为)：");
                    for(i=s->bottom;i<s->top;i++){
                    	printf("%c  ",s->array[i]);
                    }
                    printf("\n");
                }
				StackPrint(s);
				printf("出栈操作，出站后栈内情况(由底到顶为)：");
                for(i=s->bottom;i<s->top;i++){
                	printf("%c  ",s->array[i]);
                }
                printf("\n");
            }
        }	
	}
	while(s->array[s->top-1]!='#'){
		printf("\n第%d次输出%c\n",num++,StackPrint(s));
        printf("出栈操作，出站后栈内情况：");
        for(i=s->bottom;i<s->top;i++){
        	printf("%c  ",s->array[i]);
        }
        printf("\n");
	} 
    return 0;
}