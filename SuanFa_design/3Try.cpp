#include <iostream>
using namespace std;
void MultipyM(int A[2][2],int B[2][2])
{
     int i, j;
        for(i=0;i<2;i++){
            for (j = 0; j < 2;j++){
                B[i][j] = 0;
                for (int t = 0; t < 2;t++){
                    B[i][j] += A[i][t] * A[t][j];
                }
            }
}
 for(i=0;i<2;i++){
            for (j = 0; j < 2;j++){
                A[i][j] = B[i][j];                //B还给A
            }
}
//return 0;
}
void Multipy(int M[2][2]){
    int i, j;
    int A[2][2];
    A[0][0] = M[0][0] + M[0][1];
    A[0][1] = M[0][0];
    A[1][0] = M[1][0]+M[1][1];
    A[1][1] = M[1][0];
    for(i=0;i<2;i++){
            for (j = 0; j < 2;j++){
                M[i][j] = A[i][j];                //A还给M
            }
    }
   // return 0;
}
void  Fibonacci(int M[2][2],int count){
    if (count == 1)
        //cout << M[1][2] << endl;
        return ;
        //return;
    int A[2][2];
    Fibonacci(M, count / 2);
    MultipyM(M,A);  
    if(count%2==1)
        Multipy(M);
    // return M[1][2];
}

int main()
{
    int n;
    cout << "这是一个求解Fibonacci数列的算法" << endl;
    cout << "请输入需要求解的项数n" << endl;
    cin >> n;
    int t,M[2][2];
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;
    M[1][1] = 0;
    //t = Fibonacci(M, n);
   // cout << t << endl;
    Fibonacci(M, n);
    cout << M[0][1] << endl;
}

