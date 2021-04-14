
int main()
{
	stack *p;//定义栈名 
	p=StackCreate();
	StackInput(p,'#');
	int num = 1,i; 
    char temp;        
	while((temp=getchar())!='\n'){
	
		if(temp>='A'&&temp<='Z'||temp>='a'&&temp<='z'||temp>='0'&&temp<='9'||temp=='.'){        //包含数字表达式和字母表达式，支持小数
			printf("\n第%d次输出%c\n",num++,temp);
        } 
        else
        {
            if(temp=='*'||temp=='/')
            {
                while(p->data[p->top-1]!='#'&&(p->data[p->top-1]=='*'||p->data[p->top-1]=='/')){  //保证栈不会越界
                    printf("\n第%d次输出%c\n",num++,StackOutput(p));
                    printf("出栈操作，出站前栈内情况(底--->顶)：");
                    for(i=p->bottom;i<p->top;i++){
                    	printf("%c  ",p->data[i]);
                    }
                    printf("\n");
                }
	     	    StackInput(p,temp);
	     	    printf("进栈操作，进栈后(底--->顶)：");
	     	    for(i=p->bottom;i<p->top;i++){
                    printf("%c  ",p->data[i]);
                }
	     	    printf("\n");
            }
            else if(temp=='+'||temp=='-')
            {
                while(p->data[p->top-1]!='('&&p->data[p->top-1]!='#'){
                	printf("\n第%d次输出%c\n",num++,StackOutput(p));
                    printf("出栈操作，出站后栈内情况(底--->顶)：");
                    for(i=p->bottom;i<p->top;i++){
                    	printf("%c  ",p->data[i]);
                    }
                    printf("\n");
                }
	     	    StackInput(p,temp);
	     	    printf("进栈操作，进栈后(底--->顶)：");
	     	    for(i=p->bottom;i<p->top;i++){
                    printf("%c  ",p->data[i]);
                }
	     	    printf("\n");
                   
            }
            else if(temp=='('){
             	StackInput(p,temp);
             	printf("进站操作，进站后(底--->顶)：");
	     	    for(i=p->bottom;i<p->top;i++){
                    printf("%c  ",p->data[i]);
                }
	     	    printf("\n");
            }    
            else if(temp==')')
            {
                while(p->data[p->top-1]!='('){
                	printf("\n第%d次输出%c\n",num++,StackOutput(p));
                    printf("出栈操作，出站后栈内情况(底--->顶)：");
                    for(i=p->bottom;i<p->top;i++){
                    	printf("%c  ",p->data[i]);
                    }
                    printf("\n");
                }
				StackOutput(p);
				printf("出栈操作，出站后栈内情况(底--->顶)：");
                for(i=p->bottom;i<p->top;i++){
                	printf("%c  ",p->data[i]);
                }
                printf("\n");
            }
        }	
	}
	while(p->data[p->top-1]!='#'){
		printf("\n第%d次输出%c\n",num++,StackOutput(p));
        printf("出栈操作，出站后栈内情况：");
        for(i=p->bottom;i<p->top;i++){
        	printf("%c  ",p->data[i]);
        }
        printf("\n");
	} 
    return 0;
}