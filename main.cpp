//
//  main.cpp
//  Practice_BST
//
//  Created by Christopher Watson on 10/22/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

int main(int argc, const char * argv[]) {
   
    
    LinkedList LL;
    

    int array[20] = {0,32,67,2,93,89,22,19,62,71,79,70,18,41,40,39,88,99,67,29};
    
    for (int i(0); i < 20; ++i){
        LL.insert(array[i], &LL.root);
    }
    
    LL.inOrder(LL.root);
    std::cout << std::endl;
    std::cout << std::endl;
    LL.preOrder(LL.root);
    std::cout << std::endl;
    std::cout << std::endl;
    LL.postOrder(LL.root);

    std::cout << std::endl;
    std::cout << std::endl;
    LL.remove(62, &LL.root);
    LL.inOrder(LL.root);

    return 0;
}
