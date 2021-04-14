#include<stdio.h>
#include<math.h>
# define  eps  0.0001
double fun_math(double x)
{
    printf("%lf\n", pow(x, 2) -1);
    return pow(x,1/3)-1;}
double fun(double a,double b)
{
	double t;
    //printf("%lf,%lf", a, b);
    while (fun_math(a)*fun_math(b)<0&&fabs(a-b)>eps)
	{
		t=(a+b)/2;
        //printf("%lf\n",t);
        if(fabs(fun_math(a))>=fabs(fun_math(b))) a=t;
		else b=t;
	}
	return a;	
	
}

int main()
{
	double s;
	printf("函数f(x)=x1在0和2之间的零点：");
	s=fun(0.0,2.1);
	printf("shi%lf\n",s);
}