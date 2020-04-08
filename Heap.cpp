#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void PrintHeap(vector<int> heap){
    while(!heap.empty()){
        cout << heap.front() << endl;;
        pop_heap(heap.begin(),heap.end());
        heap.pop_back();
    }
}

int main(){
    vector<int> v1 = {20,30,1,2,15};


    make_heap(v1.begin(),v1.end());
    //cout << v1.front() << endl;
    
    //Insert:
    v1.push_back(50);
    push_heap(v1.begin(),v1.end());
    //cout << v1.front() << endl;

    //Pop
    /* pop_heap(v1.begin(),v1.end());
    v1.pop_back();
    cout << v1.front() << endl; */
    PrintHeap(v1);

    return 0;
}