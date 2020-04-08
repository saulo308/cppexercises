#include <iostream>
#include <vector>
using namespace std;

/* [5,12,3,4,10] */
/* 
curPivot = 10;
k = start = 0
j = start = 0
    if(v[0] < curPivot) => if(5 < 10) swap();
    [5,12,3,4,10]
k = 1
j = 1
    if(vec[1] < curPivot) => if(12 < 10)
    [5,12,3,4,10]
k = 2
j = 1
    if(3 < 10) 
    swap(12,3);
    [5,3,12,4,10]
k = 3
j = 2
    if(4 < 10)
    swap(12,4)
    [5,3,4,12,10]
k = 4
j = 3
    if(10 < 10)
k = 5
j = 3
    [5,3,4,12,10]

 */

int sepatare(int start,int end,vector<int>& vec){
    int curPivot = vec[end];
    cout << "Cur pivot is: " << curPivot << endl;
    int tempSwap,j = start;

    for(int k = start; k < end; k++){
        if(vec[k] < curPivot){
            tempSwap = vec[k];
            vec[k] = vec[j];
            vec[j] = tempSwap;
            j++;
        }
    }

    tempSwap = vec[end];
    vec[end] = vec[j];
    vec[j] = tempSwap;
    
    return j;
}

void Quicksort(int start, int end, vector<int>& vec){
    if(start < end){
        int pivot = sepatare(start,end,vec);
        Quicksort(start,pivot - 1,vec);
        Quicksort(pivot + 1,end,vec);
    }
}

int main(){
    vector<int> v1 = {5,10,23,2,0,30};
    Quicksort(0,v1.size() - 1,v1);

    for(int i = 0;i < v1.size();i ++)
        cout << v1[i] << endl;

    return 0;
}