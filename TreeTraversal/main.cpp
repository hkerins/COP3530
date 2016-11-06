//
//  main.cpp
//  TreeTraversal
//
//  Created by Henry Kerins on 11/3/16.
//  Copyright © 2016 Henry Kerins. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    int lInd;
    int rInd;
    Node *left;
    Node *right;
    //Node(int x) : val(x), left(NULL), right(NULL) {}
    Node(int x) { val = x; left = NULL; right = NULL; lInd = -1; rInd = -1; };
    Node() {val = -1; left = NULL; right = NULL; lInd = -1; rInd = -1; };
};

void setPointers(vector<Node> &nodeList);

void preorder(Node* root){
    if(root){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<Node> nodeList;
    nodeList.resize(n);
    for(int i = 0; i < n; i++){
        int val, l, r;
        cin >> val >> l >> r;
        Node treeNode(val);
        
        if(l != -1)
            treeNode.lInd = l;
        if(r != -1)
            treeNode.rInd = r;
        nodeList[i] = treeNode;
    }
    Node* root = &nodeList[0];
    //TODO: set left and right based on indexes
    setPointers(nodeList);
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    
    
    return 0;
}

void setPointers(vector<Node> &nodeList){
    vector<Node>::iterator it = nodeList.begin();
    while(it != nodeList.end()){
        if(it->lInd != -1)
            it->left = &nodeList[it->lInd];
        if(it->rInd != -1)
            it->right = &nodeList[it->rInd];
        it++;
    }
    return;
}
