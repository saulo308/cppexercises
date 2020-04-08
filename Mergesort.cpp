#include <iostream>
#include <vector>
using namespace std;

/*vec = [10,12,15,20][10,11,13,15]       */
/* w = [10,10,11,12,13,15,15] */

void merge(int start, int middle,int end,vector<int>& vec){
    vector<int> w; //Workspace vector
    int i = start,j = middle; //Auxiliar variables

    while(i < middle && j < end){
        if(vec[i] <= vec[j])
            w.push_back(vec[i++]);
        else
            w.push_back(vec[j++]);
    }

    while(i < middle) { w.push_back(vec[i++]); }
    while(j < end){ w.push_back(vec[j++]); }
    
    for(int idx = start;idx < end;idx++){
        vec[idx] = w[idx - start];
    }
}

void mergesort(int start,int end,vector<int>& vec){
    if(start < end - 1){
        int middle = (start + end) / 2;
        mergesort(start,middle,vec);
        mergesort(middle,end,vec);
        merge(start,middle,end,vec);
    }
}   

int main(){
    vector<int> v1 = {2,10,5,6,1,0};
    mergesort(0,v1.size(),v1);

    for(int i = 0;i < v1.size();i ++)
        cout << v1[i] << endl;


    return 0;
}