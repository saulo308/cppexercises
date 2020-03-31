#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(nullptr){}
};

void Append(ListNode** l1,int data){
    if(!*l1){
        *l1 = new ListNode(data);
    }else{
        ListNode* conductor = *l1;

        while(conductor->next != nullptr)
            conductor = conductor->next;

        conductor->next = new ListNode(data);
    }
}

void PrintList(ListNode* root){
    while(root != nullptr){
        cout << root->val << endl;
        root = root->next;
    }
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode* result = nullptr;

    while(l1 || l2){
        if(l1 && l2){
            if(l1->val <= l2->val){
                Append(&result,l1->val);
                l1 = l1->next;
            }else{
                Append(&result,l2->val);
                l2 = l2->next;
            }
        }else if(l1 && !l2){
            Append(&result,l1->val);
            l1 = l1->next;
        }else if(!l1 && l2){
            Append(&result,l2->val);
            l2 = l2->next;
        }
    }
    
    return result;
}


int main(){
    ListNode* l1 = nullptr;
    Append(&l1,1);
    Append(&l1,2);
    Append(&l1,4);
    ListNode* l2 = nullptr;
    Append(&l2,1);
    Append(&l2,3);
    Append(&l2,4);

    ListNode* newList = mergeTwoLists(l1,l2);
    PrintList(newList);

    return 0;
}