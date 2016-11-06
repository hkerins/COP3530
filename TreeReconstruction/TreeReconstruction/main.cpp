//
//  main.cpp
//  TreeTraversal
//
//  Created by Henry Kerins on 11/3/16.
//  Copyright © 2016 Henry Kerins. All rights reserved.
//
//INPUT:
//On the first line you can read the number of elements in the tree. On
//the second line you can read the postorder traversal of the tree, in
//a format similar to the output format of problem 1, i.e. each node's
//data is printed separated by a single space. On the third line you
//can read the inorder traversal of the tree in the same format.
//9
//7 8 4 5 2 9 6 3 1
//7 4 8 2 5 1 3 9 6
//OUTPUT:
//The output should be one line containing the levelorder traversal
//similar to problem 2.
//1 2 3 4 5 6 7 8 9

#include <iostream>
#include <vector>
#include <algorithm>
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
Node* reconstruct(vector<int> &postorder, vector<int> inorder);

int main() {
    int n;
    cin >> n;
    vector<int> postorder, inorder;
    postorder.resize(n);
    inorder.resize(n);
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        postorder[i] = val;
    }
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        inorder[i] = val;
    }
    Node* root = reconstruct(postorder, inorder);
    for(int i = 1; i <= getHeight(root); i++){
        printLevel(root, i);
    }
    
    
    return 0;
}

Node* reconstruct(vector<int> &postorder, vector<int> inorder){
    if(postorder.empty())
        return NULL;
    Node* root = new Node(postorder.back());
    vector<int>::iterator itIn = find(inorder.begin(), inorder.end(), postorder.back());
    if(itIn == inorder.end())
        return NULL;
    postorder.pop_back();
    vector<int> leftSub(inorder.begin(), itIn /*- 1*/);
    vector<int> rightSub(itIn /*+ 1*/, inorder.end());
    while(!postorder.empty()){
        //if next value in postorder is in left sub tree
        if(find(leftSub.begin(), leftSub.end(), postorder.back()) != leftSub.end()){
            root->left = reconstruct(postorder, leftSub);
        }
        else
        //if next value in postorder is in right sub tree
        if(find(rightSub.begin(), rightSub.end(), postorder.back()) != rightSub.end()){
            root->right = reconstruct(postorder, rightSub);
        }
        else break;
    }
    return root;
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







