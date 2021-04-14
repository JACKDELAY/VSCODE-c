#include<iostream>
using namespace std;
struct matrix//matrix是2*2矩阵 
{
	int num[2][2];
};
matrix mul(matrix A,matrix B)//两个2*2方阵相乘 
{
	matrix C;
	C.num[0][0]=A.num[0][0]*B.num[0][0]+A.num[0][1]*B.num[1][0];
	C.num[0][1]=A.num[0][0]*B.num[0][1]+A.num[0][1]*B.num[1][1];
	C.num[1][0]=A.num[1][0]*B.num[0][0]+A.num[1][1]*B.num[1][0];
	C.num[1][1]=A.num[1][0]*B.num[0][1]+A.num[1][1]*B.num[1][1];
	return C;
}
matrix  Fibonacci(matrix M,int count){//分治法计算矩阵M的n次方 
	if (count == 1)                  //特殊情况，n=1无需计算 
		return M; 
	
	matrix tem=Fibonacci(M, count / 2);		//否则计算矩阵M的n/2次方，然后将M的n/2次方乘M的n/2次方
	M = mul(tem,tem);
	matrix base;
	base.num[0][0]=1;
	base.num[0][1]=1;
	base.num[1][0]=1;
	base.num[1][1]=0;
	if(count%2==1)	M=mul(M,base);//如果cout是奇数，那么在先除后乘的过程中，会比之前小1，这时候需要补乘1次 
	return M;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n<0)
		{
			cout<<"结束";
			break;
		}
		if(n==0)	cout<<"第0个数是0"<<endl;	
		else if(n==1)	cout<<"第1个数是1"<<endl;//对于第0，1个斐波拉且数直接输出 
		else
		{
			matrix m;
			m.num[0][0]=1;
			m.num[0][1]=1;
			m.num[1][0]=1;
			m.num[1][1]=0;
			matrix tem=Fibonacci(m,n-1); 
			cout<<"第"<<n<<"个数是"<<tem.num[0][0]<<endl;//对于第n个斐波拉且数只需要输出[[1,1][1,0]的n-1次方的最左上角数
			
		} 		
	}
	return 0;
}

