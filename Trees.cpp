#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int x) : data(x), left(nullptr), right(nullptr){}
};

void AppendNode(node** root,int data){
    if(!*root){ //Empty tree
        node* newRoot = new node(data);
        *root = newRoot;
    }else{
        node* conductor = *root;
        node* parent = nullptr;

        while(conductor != nullptr){
            parent = conductor;
            if(data >= conductor->data){
                conductor = conductor->right;
            }else{
                conductor = conductor->left;
            }
        }

        node* newNode = new node(data);
        if(data >= parent->data)
            parent->right = newNode;
        else
            parent->left = newNode;

    }
}

void PrintTree(node* root){
    if(root != nullptr){
        PrintTree(root->left);
        cout << " " << root->data << " ";
        PrintTree(root->right);
    }
}

int main(){
    node* rootNode = nullptr;
    AppendNode(&rootNode,10);
    AppendNode(&rootNode,5);
    AppendNode(&rootNode,12);
    AppendNode(&rootNode,2);
    PrintTree(rootNode);

    return 0;
}