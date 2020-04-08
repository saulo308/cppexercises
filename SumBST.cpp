#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : val(data),left(nullptr),right(nullptr){}
};

int rangeSumBST(TreeNode* root, int L, int R){
    if(!root)
        return 0;

    if(root->val >= L && root->val <= R)
        return root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);

    return rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
}

void AppendTree(TreeNode** root, int data){
    if(!*root){
        TreeNode* newNode = new TreeNode(data);
        *root = newNode;
        return;
    }

    TreeNode* conductor = *root;
    TreeNode* ancestor = nullptr;
    while(conductor != nullptr){
        ancestor = conductor;
        if(data >= conductor->val)
            conductor = conductor->right;
        else
            conductor = conductor->left;
    }

    TreeNode* newNode = new TreeNode(data);
    if(data >= ancestor->val)
        ancestor->right = newNode;
    else
        ancestor->left = newNode;
}

void PrintTree(TreeNode* root){
    if(root){
        PrintTree(root->left);
        cout << root->val << " ";
        PrintTree(root->right);
    }
}

int main(){
    TreeNode* root = nullptr;
    //root = [10,5,15,3,7,null,18]
    AppendTree(&root,10);
    AppendTree(&root,5);
    AppendTree(&root,15);
    AppendTree(&root,3);
    AppendTree(&root,7);
    AppendTree(&root,18);
    int L = 7,R = 15;
    PrintTree(root);
    cout << endl << rangeSumBST(root,L,R) << endl;

    return 0;
}