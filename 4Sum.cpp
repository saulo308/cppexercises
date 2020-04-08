#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int>& A,vector<int>& B,vector<int>& C,vector<int>& D){
    int sum = 0;
    unordered_map<int,int> cdMap;
    for(int i = 0;i < D.size(); i++){
        for(int j = 0; j < C.size();j ++){
            if(cdMap.count(D[i] + C[j])){
                cdMap[D[i] + C[j]]++;
            }else{
                pair<int,int> newPair(D[i] + C[j],1);
                cdMap.insert(newPair);
            }
        } 
    }

    for(auto& x:cdMap)
        cout << x.first << ":" << x.second << endl;

    for(int i = 0;i < A.size();i++){
        for(int j = 0;j < B.size();j ++){
            int idx = -(A[i] + B[j]);
            if(cdMap.count(idx))
                sum += cdMap[idx];
        }
    }

    return sum;
}

int main(){
   /*  vector<int> A = {-1,1,1,1,-1},B = {0,-1,-1,0,1},C = {-1,-1,1,-1,-1},D = {0,1,0,-1,-1}; */
    /* vector<int> A = {0,1,-1},B = {-1,1,0},C = {0,0,1},D = {-1,1,1}; */
    vector<int> A = {1,2},B = {-2,-1},C = {-1,2},D = {0,0}; 
    cout << fourSumCount(A,B,C,D);

    return 0;
}