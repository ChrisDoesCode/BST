//
//  LinkedList.hpp
//  Practice_BST
//
//  Created by Christopher Watson on 10/22/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
class TreeNode{
public:
    friend class LinkedList;
    TreeNode(int d){
        data = d;
        left = 0;
        right = 0;
    }
    ~TreeNode(){
        data = 0;
        left = 0;
        right = 0;
    }
    
private:
    int data;
    TreeNode *left;
    TreeNode *right;
    
};

class LinkedList{
    
public:
    TreeNode *root;
    LinkedList();
    ~LinkedList();
    
    void insert(int d, TreeNode **current);
    void search(int d, TreeNode *current);
    void preOrder(TreeNode *current);
    void postOrder(TreeNode *current);
    void inOrder(TreeNode *current);
    void remove(int d, TreeNode **current);
    TreeNode *removalSuccessor(TreeNode **current);
};

#endif /* LinkedList_hpp */
