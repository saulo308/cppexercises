#include <iostream>
#include <list>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int data) : val(data), left(nullptr), right(nullptr){ }
};

void PrintTree(Node* root){
    if(root){
        PrintTree(root->left);
        cout << root->val << " ";
        PrintTree(root->right);
    }
}

void AppendTree(Node** root, int data){
    if(!*root){
        Node* newNode = new Node(data);
        *root = newNode;
        return;
    }

    Node* conductor = *root;
    Node* ancestor = nullptr;
    while(conductor){
        ancestor = conductor;
        if(data >= conductor->val)
            conductor = conductor->right;
        else
            conductor = conductor->left;
    }

    Node* newNode = new Node(data);
    if(data >= ancestor->val)
        ancestor->right = newNode;
    else
        ancestor->left = newNode;
}

int main(){
    Node* root = nullptr;
    AppendTree(&root,10);
    AppendTree(&root,5);
    AppendTree(&root,3);
    AppendTree(&root,2);
    AppendTree(&root,1);
    AppendTree(&root,12);
    PrintTree(root);

    return 0;
}