#include <iostream>
#include <list>
using namespace std;
/* 
                10
            5       12
        3       8
    2       4


 */

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int data) : val(data), left(nullptr), right(nullptr){ }
};

void AppendTree(Node** root,int data){
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

void PrintDFS(Node* root){
    if(root){
        PrintDFS(root->left);
        cout << root->val << " ";
        PrintDFS(root->right);
    }
}

int GetTreeHeight(Node* root){
    if(!root)
        return 0;

    int lheight = GetTreeHeight(root->left);
    int rheight = GetTreeHeight(root->right);

    return (lheight > rheight) ? lheight + 1 : rheight + 1;
}

void PrintLevel(Node* root, int height){
    if(!root)
        return;
    if(height == 1){
        cout << root->val << " ";
    }else{
        PrintLevel(root->left,height - 1);
        PrintLevel(root->right,height - 1);
    }
}

void PrintBFS(Node* root){
    int h = GetTreeHeight(root);
    for(int i = 1;i <= h;i ++)
        PrintLevel(root,i);
}

int main(){
    Node* root = nullptr;
    AppendTree(&root,10);
    AppendTree(&root,5);
    AppendTree(&root,3);
    AppendTree(&root,2);
    AppendTree(&root,4);
    AppendTree(&root,8);
    AppendTree(&root,12);
    PrintDFS(root);
    cout << endl;
    PrintBFS(root);

    return 0;
}