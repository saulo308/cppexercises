#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int repeatedNTimes(vector<int>& A){
    int n = A.size() / 2;
    unordered_map<int,int> map;
    
    for(int i = 0;i < A.size();i ++){
        pair<int,int> newPair(A[i],0);
        map.insert(newPair);
    }

    for(int i = 0;i < A.size();i ++){
        map[A[i]]++;
    }

    for(auto& x:map){
        if(x.second == n)
            return x.first;
    }

    return 0;
}

int main(){
    vector<int> a = {5,1,5,2,5,3,5,4};
    cout << repeatedNTimes(a) << endl;

    return 0;
}