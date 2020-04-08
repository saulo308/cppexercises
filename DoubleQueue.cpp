#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* previous;
    Node(int data) : val(data), next(nullptr), previous(nullptr){}
};

void PrintList(Node* root){
    while(root != nullptr){
        cout << root->val << endl;
        root = root->next;
    }
}

void ApppendList(Node** root, int data){
    if(!*root){
        Node* newNode = new Node(data);
        *root = newNode;
        return;
    }

    Node* conductor = *root;
    while(conductor->next != nullptr)
        conductor = conductor->next;

    Node* newNode = new Node(data);
    conductor->next = newNode;
    newNode->previous = conductor;
}

int main(){
    Node* root = nullptr;
    ApppendList(&root,10);
    ApppendList(&root,4);
    ApppendList(&root,30);
    ApppendList(&root,20);
    ApppendList(&root,19);
    //PrintList(root);
    cout << root->next->previous->previous->val << endl;

    return 0;
}