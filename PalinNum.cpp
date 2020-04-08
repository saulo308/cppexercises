#include <iostream>
#include <string>
using namespace std;

bool Palindrome(int num){
    if(num < 0) return false;

    string numStr = to_string(num);

    int i = 0,j = numStr.size() - 1;
    while(i <= numStr.size()){
        if(numStr[i] != numStr[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    int num = 12;
    cout << Palindrome(num);
    return 0;
}