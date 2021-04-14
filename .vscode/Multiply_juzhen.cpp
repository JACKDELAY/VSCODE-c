#include <iostream>
using namespace std;
#define N 8
void MatrixAddict(int n,int A[][N],int B[][N],int C[][N]){//矩阵相加
    int i,j;
    for (i = 0; i < n;i++){
        for (j = 0; j < n;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void MatrixSbumit(int n,int A[][N],int B[][N],int C[][N]){//矩阵相加
    int i,j;
    for (i = 0; i < n;i++){
        for (j = 0; j < n;j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void Strassen(int  n,int A[][N],int B[][N],int C[][N]){
    int A11[N][N],A12[N][N],A21[N][N],A22[N][N];
	int B11[N][N],B12[N][N],B21[N][N],B22[N][N];
	int C11[N][N],C12[N][N],C21[N][N],C22[N][N];
	int M1[N][N],M2[N][N],M3[N][N],M4[N][N],M5[N][N],M6[N][N],M7[N][N];
	int T1[N][N],T2[N][N];        //转换的中间变量
    int i, j;
    if(n==2){
        for(i=0;i<2;i++){
            for (j = 0; j < 2;j++){
                C[i][j] = 0;
                for (int t = 0; t < 2;t++){
                    C[i][j] += A[i][t] * B[t][j];
                }
            }
        }
        return;
    }
    for (i = 0; i < n / 2;i++){
        for (j = 0; j < n / 2;j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n / 2];
            A21[i][j] = A[i + n / 2][j];
            A22[i][j] = A[i + n / 2][j + n / 2];
            B11[i][j]=B[i][j];
			B12[i][j]=B[i][j+n/2];
			B21[i][j]=B[i+n/2][j];
			B22[i][j]=B[i+n/2][j+n/2];
        }
    }
    MatrixSbumit(n/2,B12,B22,T1);
	Strassen(n/2,A11,T1,M1);
	MatrixAddict(n/2,A11,A12,T1);
	Strassen(n/2,T1,B22,M2);
	MatrixAddict(n/2,A21,A22,T1);
	Strassen(n/2,T1,B11,M3);
	MatrixSbumit(n/2,B21,B11,T1);
	Strassen(n/2,A22,T1,M4);
	MatrixAddict(n/2,A11,A22,T1);
	MatrixAddict(n/2,B11,B22,T2);
	Strassen(n/2,T1,T2,M5);
	MatrixSbumit(n/2,A12,A22,T1);
	MatrixAddict(n/2,B21,B22,T2);
	Strassen(n/2,T1,T2,M6);
	MatrixSbumit(n/2,A11,A21,T1);
	MatrixAddict(n/2,B11,B12,T2);
	Strassen(n/2,T1,T2,M7);
	MatrixAddict(n/2,M5,M4,T1);
	MatrixSbumit(n/2,T1,M2,T2);
	MatrixAddict(n/2,T2,M6,C11);
	MatrixAddict(n/2,M1,M2,C12);
	MatrixAddict(n/2,M3,M4,C21);
	MatrixAddict(n/2,M5,M1,T1);
	MatrixSbumit(n/2,T1,M3,T2);
	MatrixSbumit(n/2,T2,M7,C22); 
    for(i=0;i<n/2;i++){
        for (j = 0; j < n / 2;j++){
            C[i][j] = C11[i][j];
            C[i + n / 2][j] = C21[i][j];
            C[i][j + n / 2] = C12[i][j];
            C[i + n / 2][j + n / 2] = C22[i][j];
        }
    }

}
int main(){
    int i, j;
    int A[N][N], B[N][N], C[N][N];
    cout << "请输入A矩阵：" << endl;
    for (i = 0; i < N;i++){
        for (j = 0; j < N;j++){
            cin >> A[i][j];
        }
    }
    cout << "请输入B矩阵：" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N;j++){
            cin >>B[i][j];
        }
    }
    Strassen(N, A, B, C);
    cout << "矩阵相乘：" << endl;
    for (i = 0; i < N;i++){
        for (j = 0; j < N;j++){
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
