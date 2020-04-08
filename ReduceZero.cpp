#include <iostream>
using namespace std;

int main(){
    int count = 0,num = 8;

    while(num > 0){
        if(num % 2 != 0){
            num -= 1;
            count++;
        }else{
            num /= 2;
            count ++;
        }
    }

    cout << count;

    return 0;
}