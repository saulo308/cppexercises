#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getSmallerStringOnArray(vector<string> strs,int& strIdx){
    int smallestLen = 9999;
    string returnString;

    for(int i = 0;i < strs.size();i++){
        if(strs[i].size() < smallestLen){
            strIdx = i;
            smallestLen = strs[i].size();
            returnString = strs[i];
        }
    }

    return returnString;
}

string longestCommonPrefix(vector<string>& strs){
    string resultPrefix = "";
    int idx, flag = 0;

    //Get smallestString
    string smallestString = getSmallerStringOnArray(strs,idx);
    if(strs.size() == 1) return smallestString;

    //Looking for common prefix
    for(int i = 0; i < smallestString.size(); i ++){
        for(int j = 0; j < strs.size();j ++){
            if(j == idx) continue;
            if(strs[j][i] == smallestString[i]){
                flag = 1;
            }else{
                return resultPrefix;
            }
        }

        if(flag){
            flag = 0;
            resultPrefix.push_back(smallestString[i]);
        }
    }

    return resultPrefix;
}

int main(){
    vector<string> strs = {"flow","flight","flower"};

    cout << longestCommonPrefix(strs);

    return 0;
}