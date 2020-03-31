#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Node{
    public:
        Node* next;
        int data;
    Node(){
        next = nullptr;
    }
    Node(int newData){
        data = newData;
        next = nullptr;
    }
    Node(int newData,Node* nextRef){
        data = newData;
        next = nextRef;
    }
};

void PrintList(Node *list){
    while(list != nullptr){
        cout << list->data << endl;
        list = list->next;
    }
}

/* Node* Push(Node* curHead,int data){
    return new Node(data,curHead);
} */

void Push(Node** curHead,int data){
    Node* newNode = new Node(data);
    newNode->next = *curHead;
    (*curHead) = newNode;
}

void Append(Node* node,int data){
    Node* newNode = new Node(data);
    while(node->next != nullptr){
        node = node->next;
    }
    node->next = newNode;
}

void InsertAfter(Node* prevNode,int data){
    if(prevNode == nullptr) return;

    Node* newNode = new Node(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void AppendStruct(ListNode** root,int data){
    if(!*root){
        *root = new ListNode(data);
        return;
    }

    ListNode* conductor = *root;
    while(conductor->next != nullptr)
        conductor = conductor->next;

    conductor->next = new ListNode(data);
}

int main(){
    Node* head = new Node();
    head->data = 2;

    Node* second = new Node();
    second->data = 3;

    head->next = second;

   PrintList(head);
   Push(&head,4);
   cout << endl;
   PrintList(head);
   cout<<endl;
   Append(head,10);
   PrintList(head);
   cout <<endl;
   InsertAfter(second,5);
   PrintList(head);



    return 0;
}