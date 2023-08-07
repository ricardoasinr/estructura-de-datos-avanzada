//
//  Node.h
//  Arboles ordenados
//
//  Created by Ricardo Asin on 18/3/23.
//

#ifndef Node_h
#define Node_h
#include <iostream>
using namespace std;
class Node {
public:
    
    int data;
    Node* left;
    Node* right;
  

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
    
    
    
    
};



#endif /* Node_h */
