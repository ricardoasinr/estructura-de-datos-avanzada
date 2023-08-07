//
//  Header.h
//  Arboles ordenados
//
//  Created by Ricardo Asin on 25/2/23.
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include "Node.h"
using namespace std;


class BinaryTree {
private:
    Node* root;
    
    
    Node* insert(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        } else {
            if (data <= node->data) {
                node->left = insert(node->left, data);
            } else {
                node->right = insert(node->right, data);
            }
            return node;
        }
    }

    void inOrder(Node* node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }
    void preOrder(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }
    
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current;
            
        }
        return current;
    }
    
    bool search(Node* node, int data) {
        if (node == NULL) {
            cout<<"No se encontró el número ["<<data<<"]"<<endl;
            return false;
        }
        if (node->data == data) {
            cout<<"Si se encontró el número ["<<data<<"]"<<endl;
            return true;
        }
        if (data < node->data) {
            return search(node->left, data);
        } else {
            return search(node->right, data);
        }
    }
    
    Node* deleteNode(Node* node, int data) {
        
        if (node == NULL) {
            return NULL;
        } else if (data < node->data) {
            node->left = deleteNode(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        } else {
            if (node->left == NULL && node->right == NULL) { // caso 1: nodo a eliminar es una hoja
                delete node;
                node = NULL;
            } else if (node->left == NULL) { // caso 2a: nodo a eliminar tiene un hijo derecho
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == NULL) { // caso 2b: nodo a eliminar tiene un hijo izquierdo
                Node* temp = node;
                node = node->left;
                delete temp;
            } else { // caso 3: nodo a eliminar tiene dos hijos
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }
    
    int height(Node* node) {
        if (node == NULL) {
            return 0;
        } else {
            int left_height = height(node->left);
            int right_height = height(node->right);
            return 1 + max(left_height, right_height);
        }
    }

    bool isBalanced(Node* node) {
        if (node == NULL) {
            return true;
        } else {
            int left_height = height(node->left);
            int right_height = height(node->right);
            int diff = abs(left_height - right_height);
            if (diff <= 1 && isBalanced(node->left) && isBalanced(node->right)) {
                
                return true;
            } else {
                return false;
            }
        }
    }
  
    
    int balanceFactor(Node* node) {
        if (node == NULL) {
            return 0;
        } else {
            int left_height = height(node->left);
            int right_height = height(node->right);
            return left_height - right_height;
        }
    }

    Node* leftRotate(Node* node) {
        Node* nodeRight = node->right;
        node -> right = node -> left;
        nodeRight -> left = node;
        node = nodeRight;
        return node;
        
    }

    Node* rightRotate(Node* node) {
        Node *nodeLeft = node -> left;
        node -> left = nodeLeft->right;
        nodeLeft -> right = node;
        node = nodeLeft;
        return node;
    }
    

    Node* insertBalance(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        } else if (data < node->data) {
            node->left = insertBalance(node->left, data);
        } else if (data > node->data) {
            node->right = insertBalance(node->right, data);
            //cout<<"Raiz: "<<data<<endl;
        } else {
            // El nodo ya existe en el árbol
            //cout<<"Raiz: "<<data<<endl;
            return node;
        }
        
        // Verificar el factor de equilibrio del nodo actual
        int balance = balanceFactor(node);
        
        
        // Caso izquierdo-izquierdo: rotación simple a la derecha
        if (balance > 1 && data < node->left->data) {
            return rightRotate(node);
        }
        
        // Caso derecho-derecho: rotación simple a la izquierda
        if (balance < -1 && data > node->right->data) {
            return leftRotate(node);
        }
        
        // Caso izquierdo-derecho: rotación doble a la derecha
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        // Caso derecho-izquierdo: rotación doble a la izquierda
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        // El árbol sigue balanceado
        
        return node;
    }
    



public:
    BinaryTree() {
        root = NULL;
    }
    
  
    void insert(int data) {
        root = insert(root, data);
    }

    void inOrder() {
        inOrder(root);
      
    }
    void preOrder() {
        preOrder(root);
    }


    void postOrder() {
        postOrder(root);
    }
    
    void search(int data) {
        search(root, data);
    }

  
    
    void eliminar(int valor){
       
        if (search(root, valor)) {
            root = deleteNode(root, valor);
        } else {
            cout << "El valor [" << valor << "] no se encuentra en el árbol." << endl;
        }
    }
    
    bool isBalanced() {
           return isBalanced(root);
       }

       void insertBalancee(int data) {
           root = insertBalance(root, data);
       }
    

    
    
};


#endif /* Header_h */
