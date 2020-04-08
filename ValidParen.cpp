#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s){
    stack<char> parenStack;
    char temp;

    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            parenStack.push(s[i]);
        }else if(s[i] == ')' && parenStack.size()){
            if(parenStack.top() != '(')
                return false;
            parenStack.pop();
        }else if(s[i] == '}' && parenStack.size()){
            if(parenStack.top() != '{')
                return false;
            parenStack.pop();
        }else if(s[i] == ']' && parenStack.size()){
            if(parenStack.top() != '[')
                return false;
            parenStack.pop();
        }else{
            return false;
        }
    }

    if(!parenStack.size())
        return true;
    else
        return false;
}

int main(){
    string s = "((";
    cout << isValid(s);
    return 0;
}