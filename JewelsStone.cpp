#include <iostream>
#include <string>
using namespace std;

int numJewelsInStones(string J,string S){
    int num = 0;

    for(int i = 0;i < J.size();i ++){
        for(int j = 0;j < S.size(); j ++){
            if(J[i] == S[j])
                num++;
        }
    }
    return num;
}

int main(){
    string J = "Z";
    string S = "ZZ";
    cout << numJewelsInStones(J,S);
    return 0;
}