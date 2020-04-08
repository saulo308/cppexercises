/*
1     10
/      \
1       15
 */
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr){}
};

void AppendTree(TreeNode** root, int data){
    if(!*root){
        TreeNode* newNode = new TreeNode(data);
        *root = newNode;
        return;
    }

    //Tree not empty(root != nullptr)
    TreeNode* conductor = *root;
    TreeNode* ancestor = nullptr;

    while(conductor != nullptr){
        ancestor = conductor;
        if(data > conductor->val)
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

 bool validHelper(TreeNode* root, int* min, int* max){
    if(!root) return true;

    int val = root->val;
    if(min != nullptr && val <= *min) return false;
    if(max != nullptr && val >= *max) return false;

    if(!validHelper(root->right,&val,max)) return false;
    if(!validHelper(root->left,min,&val)) return false;
    return true; 
}
    
bool isValidBST(TreeNode* root) {
    return validHelper(root,nullptr,nullptr);
}

int main(){
    TreeNode* root = nullptr;
    AppendTree(&root,5);
    AppendTree(&root,1);
    AppendTree(&root,4);
    AppendTree(&root,3);
    AppendTree(&root,6);
    PrintTree(root);
    cout << isValidBST(root) << endl;

    return 0;
}