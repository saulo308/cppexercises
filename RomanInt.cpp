#include <iostream>
#include <string>
using namespace std;

int romanToInt(string str){
    int result = 0;

    for(int i = 0;i < str.size();i++){
        switch(str[i]){
            case 'I':
                if(str[i + 1] == 'V' || str[i + 1] == 'X')
                    result -= 1;
                else
                    result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if(str[i + 1] == 'L' || str[i + 1] == 'C')
                    result -= 10;
                else
                    result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if(str[i + 1] == 'D' || str[i + 1] == 'M')
                    result -= 100;
                else
                    result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
        }
    }

    return result;
}

int main(){
    string romanNum = "IV";
    int num = romanToInt(romanNum);
    cout << num;
    return 0;
}