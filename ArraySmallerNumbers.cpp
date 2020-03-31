#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numArray = {8,1,2,2,3};
    vector<int> resultArray;

    for(int i = 0; i < numArray.size();i ++)
        resultArray.push_back(0);

    for(int i = 0;i < numArray.size();i ++){
        for(int j = 0;j < numArray.size();j ++){
            if(i != j && numArray[i] > numArray[j]){
                resultArray[i]++;
            }
        }
    }

    for(int i = 0; i < numArray.size();i ++)
        cout << resultArray[i];
    return 0;
}