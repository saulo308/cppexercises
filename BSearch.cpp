#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(int start,int end,vector<int> vec,int data){
    if(start <= end){
        int middle = (start + end) / 2;

        if(vec[middle] == data)
            return middle;

        if(data > vec[middle])
            return BinarySearch(middle + 1,end,vec,data);
        
        return BinarySearch(start,middle - 1,vec,data);
    }

    return -1;
}

int main(){
    vector<int> v1 = {2,4,10,20,30};

    cout << BinarySearch(0,v1.size(),v1,0) << endl;

    return 0;
}