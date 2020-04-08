#include <iostream>
#include <string>
using namespace std;

int main(){
    int num = -1529,result;
    double doubleResult;
    string s = to_string(num),newInt;
    
    for(int i = s.size() - 1;i >= 0 ;i --){
        newInt.push_back(s[i]);
    }
    //Checking if reversed overflows
    doubleResult = stod(newInt);
    if(doubleResult > pow(2,31))
        return 0;
    else
        result = (int)doubleResult;

    if(num < 0)
        result *= -1;
    
    cout << result;

    return 0;
}