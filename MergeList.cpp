#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(){
            next = nullptr;
        }
        Node(int newData){
            val = newData;
            next = nullptr;
        }
};

/* void Append(Node* node,int data){
    //Empty list passed
    if(!node){
        node = new Node(data);
        return;
    } 

    //New node has to be created
    Node* newNode = new Node(data);
    while(node->next != nullptr){
        node = node->next;
    }
    node->next = newNode;
}
 */
/* void Push(Node** node,int data){
    Node* newNode = new Node(data);
    newNode->next = *node;
    *node = newNode;
} */

void Append(Node** list,int data){
    if(*list == nullptr){
        *list = new Node(data);
    }else{
        Node* newNode = new Node(data);
        while((*list)->next != nullptr)
            *list = (*list)->next;

        (*list)->next = newNode;
    }
}

void PrintList(Node* head){
    while(head != nullptr){
        cout << head->val << endl;
        head = head->next;
    }
}

/* Node* mergeTwoLists(Node* l1,Node* l2){
    Node* newList = new Node();

    while(l1 != nullptr || l2 != nullptr){
        if(l1 && l2){
            if(l1->val <= l2->val){
                Append(newList,l1->val);
                l1 = l1->next;
            }else{
                Append(newList,l2->val);
                l2 = l2->next;
            }
        }else if(!l1 && l2){
            Append(newList,l2->val);
            l2 = l2->next;
        }else if(l1 && !l2){
            Append(newList,l1->val);
            l1 = l1->next;
        }
    }
    
    return newList;
} */

int main(){
    Node* ListA = nullptr;
    Append(&ListA,1);
    Append(&ListA,2);
    Append(&ListA,4);
    PrintList(ListA);

   /*  Node* ListB = new Node(1);
    Append(ListB,3);
    Append(ListB,4); */

    //Node* newList = mergeTwoLists(ListA,ListB);
    //PrintList(newList);

    return 0;
}