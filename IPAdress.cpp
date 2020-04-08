#include <iostream>
#include <string>
using namespace std;

void pushString(string& str,string push){
    for(int i = 0;i < push.size(); i ++){
        str.push_back(push[i]);
    }
}

int main(){
    string originalString = "1.1.1.1";
    string replaceString = "[.]";
    string newString;

    for(int i = 0;i < originalString.size(); i ++){
        if(originalString[i] == '.'){
            pushString(newString,replaceString);
        }else{
            newString.push_back(originalString[i]);
        }
    }
    cout << newString;
    return 0;
}