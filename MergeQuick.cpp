#include <iostream>
#include <vector>
using namespace std;

int Separate(int start, int end, vector<int>& vec){
    int curPivot = vec[end];
    int j = start;

    for(int k = start; k < end; k++){
        if(vec[k] > curPivot)
            swap(vec[k],vec[j++]);
    }

    swap(vec[end],vec[j]);
    return j;
}

void QuickSort(int start, int end, vector<int>& vec){
    if(start < end){
        int pivot = Separate(start,end,vec);
        QuickSort(start,pivot - 1,vec);
        QuickSort(pivot + 1,end,vec);
    }
}

void Merge(int start, int middle, int end, vector<int>& vec){
    vector<int> w; //Workspace
    int i = start,j = middle; //Temp variables

    while(i < middle && j < end){
        if(vec[i] > vec[j])
            w.push_back(vec[i++]);
        else
            w.push_back(vec[j++]);
    }

    while(i < middle){ w.push_back(vec[i++]); }
    while(j < end){ w.push_back(vec[j++]); }

    for(int idx = start; idx < end; idx++)
        vec[idx] = w[idx - start];
}

void MergeSort(int start,int end,vector<int>& vec){
    if(start < end - 1){
        int middle = (start + end) / 2;
        MergeSort(start,middle,vec);
        MergeSort(middle,end,vec);
        Merge(start,middle,end,vec);
    }
}


int main(){
    vector<int> v1 = {10,5,15,20,2,0};
    vector<int> v2 = {10,5,15,20,2,0};

    MergeSort(0,v1.size(),v1);
    for(int i = 0;i < v1.size();i++){
        cout << v1[i] << endl;
    }

    cout << endl;

    QuickSort(0,v2.size() - 1,v2);
    for(int i = 0;i < v2.size();i++){
        cout << v2[i] << endl;
    }


    return 0;
}