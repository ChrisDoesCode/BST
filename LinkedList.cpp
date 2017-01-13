//
//  LinkedList.cpp
//  Practice_BST
//
//  Created by Christopher Watson on 10/22/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList(){
    root = 0;
}

LinkedList::~LinkedList(){
    root = 0;
}

void LinkedList::insert(int d, TreeNode **current){
    
    TreeNode *temp = new TreeNode(d);
    if ((*current) == NULL){
        (*current) = temp;
        
    }
    else if (current !=0){
        if ((*current)->data > temp->data){
            insert(temp->data, &(*current)->left);
        }
        else if ((*current)->data < temp->data){
            insert(temp->data, &(*current)->right);
        }
    }
}

void LinkedList::remove(int d, TreeNode **current){
    TreeNode *temp;
    
    if ((*current)->data > d){
        remove(d, &(*current)->left);
    }
    else if ((*current)->data < d){
        remove(d, &(*current)->right);
    }
    
    if ((*current)->data == d){
        //2 Children
        if (((*current)->left != 0) && ((*current)->right !=0)){
            *current = removalSuccessor(&(*current));
        }
        
        //1 Child on left
        else if (((*current)->left != 0) && ((*current)->right ==NULL)){
            temp = (*current)->left;
            (*current)->left = 0;
            (*current) = temp;
        }
        //1 Child on right
        else if (((*current)->right != 0) && ((*current)->left ==NULL)){
            temp = (*current)->right;
            (*current)->right = 0;
            (*current) = temp;
        }
        
        //No Children
        else if (((*current)->left == NULL) && ((*current)->right == NULL)){
            (*current) = NULL;
        }
        
        
    }
    
}

TreeNode *LinkedList::removalSuccessor(TreeNode **current){
    TreeNode *parent = (*current);
    TreeNode *child = (*current)->right;
    
    if (child->left != NULL){
        child = child->left;
        while (child->left != NULL){
            child = child->left;
        }
        if (child->right == NULL){
            return child;
        }
        if (child->right != NULL){
            parent = child;
            child = child->right;
            return parent;
        }
    }
    else if (child->left == NULL){
        return child;
    }

    return 0;
}

void LinkedList::inOrder(TreeNode *current){
    if (current != 0){
        inOrder(current->left);
        std::cout << "("<< current->data << ")";
        inOrder(current->right);
    }
}

void LinkedList::preOrder(TreeNode *current){
    if (current !=0){
        std::cout <<"("<<current->data<<")";
        preOrder(current->left);
        preOrder(current->right);
    }
}

void LinkedList::postOrder(TreeNode *current){
    if (current !=0){
        postOrder(current->left);
        postOrder(current->right);
        std::cout <<"("<<current->data<<")";
    }
}
