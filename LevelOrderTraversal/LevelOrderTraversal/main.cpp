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
int getHeight(Node* root);
void printLevel(Node* root, int level);

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
    for(int i = 1; i <= getHeight(root); i++){
        printLevel(root, i);
    }
   
    
    
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
int getHeight(Node* root){
    if(root == NULL)
        return 0;
    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);
    if(lHeight > rHeight)
        return lHeight+1;
    else return rHeight+1;
}
void printLevel(Node* root, int level){
    if(root == NULL)
        return;
    if(level == 1)
        cout << root->val << " ";
    else if (level > 1){
        printLevel(root->left,level-1);
        printLevel(root->right, level-1);
    }
}







