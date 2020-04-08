#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int data) : val(data),next(nullptr){}
};

void AppendList(Node** root, int data){
    if(!*root){
        Node* newNode = new Node(data);
        *root = newNode;
        return;
    }

    Node* conductor = * root;
    while(conductor->next != nullptr)
        conductor = conductor->next;

    Node* newNode = new Node(data);
    conductor->next = newNode;
}

void PrintList(Node* root){
    while(root != nullptr){
        cout << root->val << endl;
        root = root->next;
    }
}

int main(){
    Node* root = nullptr;
    AppendList(&root,10);
    AppendList(&root,4);
    AppendList(&root,30);
    AppendList(&root,2);
    PrintList(root);


    return 0;
}