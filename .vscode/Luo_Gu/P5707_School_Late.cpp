#include <iostream>
#include<iomanip>
using namespace std;
int main(){
    int a[2][2];// 数组第一位控制时，第二位控制秒
    int s, v;
    int time;
    a[0][0] = 8;
    a[0][1] = 0;
    cin >> s>>v;
    time = s / v;
   // cout << time;
    if((s%v)!=0)         //多备一分钟
        time+= 1;
    a[0][1] -= time;
    a[0][1] -= 10;
    while(a[0][1]<0){
        a[0][1] += 60;
        a[0][0] -= 1;
    }
    while(a[0][0]<0){
       
        a[0][0] += 24;
    }
    cout << setw(2) << setfill('0') << a[0][0] << ":" << setw(2) << setfill('0') << a[0][1] << endl;
    return 0;
}
