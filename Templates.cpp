#include <iostream>
using namespace std;

template <typename T>
T GetMax(T x,T y){
    return (x > y) ? x : y;
}

template <typename T>
void BubbleSort(T a[], int n){
    for(int i = 0;i < n-1;i ++){
        for(int j = n - 1; i < j;j--){
            if(a[j] < a[j-1])
                swap(a[j],a[j-1]);
        }
    }
}

int main(){
    int a[5] = {1,4,10,2,0};
    int n = sizeof(a) / sizeof(a[0]);
    BubbleSort(a,n);

    for(int i = 0; i < n;i ++)
        cout << a[i] << endl;


    return 0;
}