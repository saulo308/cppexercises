#include <iostream>
#include <vector>
using namespace std;

void moveElementToArrayEnd(vector<int>& nums, int idx){
    int elementToMove = nums[idx];
    //For each element after the element we want to move
    //we move it one position forward
    for(int i = idx;i < nums.size() - 1;i ++){
        nums[i] = nums[i + 1];
    }
    //Last element receives elementToMove
    nums[nums.size() - 1] = elementToMove;
}

int removeDuplicates(vector<int>& nums){
    int newLength = nums.size();
    if(nums.size()){
        int previousElement = nums[0];

        for(int i = 1;i < newLength;i ++){
            if(nums[i] == previousElement){
                moveElementToArrayEnd(nums,i);
                newLength--;
                i--;
            }else{
                previousElement = nums[i];
            }
        }
    }

    return newLength;
}

int main(){
    vector<int> nums = {};
    int len = removeDuplicates(nums);

    cout << len << endl;
    for(int i = 0;i < len;i++)
        cout << nums[i] << endl;

    return 0;
}