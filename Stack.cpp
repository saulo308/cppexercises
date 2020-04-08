#include <iostream>
#include <stack>
#include <string>
using namespace std;

void PrintStack(stack<char> stack){
    while(!stack.empty()){
        cout << stack.top() << endl;
        stack.pop();
    }
}

bool validParentheses(string str){
    stack<char> parenStack;
    for(int i = 0;i < str.size();i++){
        switch(str[i]){
            case '(':
            case '[':
            case '{':
                parenStack.push(str[i]);
                break;
            case ')':
                if(!parenStack.empty() && parenStack.top() == '(')
                    parenStack.pop();
                else
                    return false;
                break;
            case ']':
                if(!parenStack.empty() && parenStack.top() == '[')
                    parenStack.pop();
                else
                    return false;
                break;
            case '}':
                if(!parenStack.empty() && parenStack.top() == '{')
                    parenStack.pop();
                else
                    return false;
                break;
        }
    }
    PrintStack(parenStack);

    if(parenStack.empty())
        return true;

    return false;
}


int main(){
    string str = "";

    cout << validParentheses(str) << endl;

    return 0;
}